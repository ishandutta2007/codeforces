#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define MOD 1000000007
#define MOD2 998244353
#define _INFINITY 9223372036854775807
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

int main()
{
    int n;
    int r[100005] = {0};
    cin >> n;
    r[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        int m;
        cin >> m;
        //if (m <= i)
        //r[i % 2][m] = (r[i % 2][m] + r[(i - 1) % 2][m - 1]) % MOD;
        vector<int> v;
        for (int j = min((int)sqrt(m), i); j > 0; j--)
            if (m % j == 0)
            {
                v.emplace_back(j);
                if (m / j != j)
                    v.emplace_back(m / j);
            }
        sort(v.begin(), v.end(), [](int a, int b) { return a > b; });

        for (int j : v)
            if (j <= i)
                r[j] = (r[j - 1] + r[j]) % MOD;
    }
    int sum = 0;
    for (int i = 1; i <= n; i++)
        sum = (sum + r[i]) % MOD;
    cout << sum;
    return 0;
}