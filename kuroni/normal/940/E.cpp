#include <iostream>
#include <cstdio>
#include <deque>
#define ll I64
using namespace std;

const int N = 1E5 + 5;

deque<int> val, ret;
int n, c, a[N];
long long ans[N], sum = 0;

int main()
{
    scanf("%d%d", &n, &c);
    if (c == 1)
    {
        printf("0");
        return 0;
    }
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", a + i);
        sum += a[i];
    }
    for (int i = 1; i < c; i++)
    {
        while (!val.empty() && a[val.back()] >= a[i])
            val.pop_back();
        val.push_back(i);
    }
    ret.push_back(c - 1);
    for (int i = c; i <= n; i++)
    {
        while (!val.empty() && val.front() <= i - c)
            val.pop_front();
        while (!val.empty() && a[val.back()] >= a[i])
            val.pop_back();
        val.push_back(i);
        while (!ret.empty() && ret.front() <= i - c)
            ret.pop_front();
        ans[i] = max(ans[i - c] + a[val.front()], ans[ret.front()]);
        while (!ret.empty() && ans[ret.back()] <= ans[i])
            ret.pop_back();
        ret.push_back(i);
    }
    printf("%lld", sum - ans[n]);
}