using namespace std;
#include "bits/stdc++.h"

typedef string::const_iterator State;
#define eps 1e-8L
#define MAX_MOD 1000000007LL
#define GYAKU 500000004LL
#define MOD 998244353LL
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef long double ld;
#define REP(a, b) for (long long(a) = 0; (a) < (b); ++(a))
#define ALL(x) (x).begin(), (x).end()

#define int long long
int dp[32768];
void solve()
{
    REP(i, 32768)
    {
        dp[i] = 1e9;
    }
    queue<int> nexts;
    nexts.push(0);
    dp[0] = 0;
    const int mod = 32768;
    while (!nexts.empty())
    {
        int now = nexts.front();
        nexts.pop();
        if (dp[(mod - 1 + now) % mod] == 1e9)
        {
            dp[(mod - 1 + now) % mod] = dp[now] + 1;
            nexts.push((mod - 1 + now) % mod);
        }
        if (now % 2 == 0)
        {
            REP(t, 2)
            {
                int target = (mod / 2) * t + now / 2;
                if (dp[target] == 1e9)
                {
                    dp[target] = dp[now] + 1;
                    nexts.push(target);
                }
            }
        }
    }
    int n;
    cin >> n;
    REP(i, n)
    {
        int a;
        cin >> a;
        if (i)
            cout << " ";
        cout << dp[a];
    }
    cout << endl;
}
#undef int

// generated by oj-template v4.7.2
// (https://github.com/online-judge-tools/template-generator)
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(100);
    int t = 1;
    // cin >> t; // comment out if solving multi testcase
    for (int testCase = 1; testCase <= t; ++testCase)
    {
        solve();
    }
    return 0;
}