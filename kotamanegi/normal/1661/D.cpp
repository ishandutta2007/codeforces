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
int dx_die[1000000];
void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> inputs;
    REP(i, n)
    {
        int a;
        cin >> a;
        inputs.push_back(a);
    }
    int now_count = 0;
    int dx = 0;
    int ans = 0;
    for (int q = n - k; q >= 1; --q)
    {
        now_count += dx;
        if (now_count < inputs[q + k - 1])
        {
            int moves = (inputs[q + k - 1] - now_count + k - 1) / k;
            ans += moves;
            now_count += moves * k;
            dx -= moves;
            dx_die[q - 1] += moves;
        }
        dx += dx_die[q + k - 1];
    }

    for (int q = k - 1; q >= 0; --q)
    {
        now_count += dx;
        inputs[q] -= now_count;
        dx += dx_die[q];
    }
    int sums = 0;
    REP(q, k)
    {
        sums = max(sums, (inputs[q] + q) / (q + 1));
    }
    ans += sums;
    cout << ans << endl;
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