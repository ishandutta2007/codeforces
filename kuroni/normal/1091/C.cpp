#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<long long> ans;

long long find_ans(int u)
{
    return 1LL * u * (n + 2 - n / u) / 2;
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i * i <= n; i++)
        if (n % i == 0)
        {
            ans.push_back(find_ans(i));
            if (n != i * i)
                ans.push_back(find_ans(n / i));
        }
    sort(ans.begin(), ans.end());
    for (long long &v : ans)
        printf("%lld ", v);
}