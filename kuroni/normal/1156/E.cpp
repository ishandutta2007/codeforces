#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

const int N = 200005;

int n, ans = 0, a[N], pos[N], l[N], r[N];

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", a + i);
        pos[a[i]] = i;
    }
    a[0] = a[n + 1] = n + 1;
    vector<int> le = {0}, ri = {n + 1};
    for (int i = 1; i <= n; i++)
    {
        while (a[le.back()] < a[i])
            le.pop_back();
        l[i] = le.back() + 1;
        le.push_back(i);
    }
    for (int i = n; i >= 1; i--)
    {
        while (a[ri.back()] < a[i])
            ri.pop_back();
        r[i] = ri.back() - 1;
        ri.push_back(i);
    }
    for (int i = 1; i <= n; i++)
        if (i - l[i] < r[i] - i)
        {
            for (int j = l[i]; j <= i; j++)
                if (pos[a[i] - a[j]] >= i && pos[a[i] - a[j]] <= r[i])
                    ++ans;
        }
        else
        {
            for (int j = i; j <= r[i]; j++)
                if (pos[a[i] - a[j]] <= i && pos[a[i] - a[j]] >= l[i])
                    ++ans;
        }
    printf("%d", ans);
}