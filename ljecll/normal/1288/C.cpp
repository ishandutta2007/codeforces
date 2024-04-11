#include <bits/stdc++.h>

using namespace std;

template<class T, class U>
void ckmin(T &a, U b)
{
    if (a > b) a = b;
}

template<class T, class U>
void ckmax(T &a, U b)
{
    if (a < b) a = b;
}

#define MP make_pair
#define PB push_back
#define LB lower_bound
#define UB upper_bound
#define fi first
#define se second
#define SZ(x) ((int) (x).size())
#define ALL(x) (x).begin(), (x).end()
#define FOR(i, a, b) for (auto i = (a); i < (b); i++)
#define FORD(i, a, b) for (auto i = (a) - 1; i >= (b); i--)
#define INF 1000000007

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpi;
typedef vector<pll> vpl;

int N, M;
int dp[21][1013];
int ans;

int32_t main()
{
    cout << fixed << setprecision(12);
    cerr << fixed << setprecision(4);
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> N >> M; M *= 2;
    dp[0][0] = 1;
    FOR(i, 1, M + 1)
    {
        dp[i][0] = 1;
        FOR(j, 1, N)
        {
            dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
            if (dp[i][j] >= INF) dp[i][j] -= INF;
        }
    }
    FOR(j, 0, N)
    {
        ans += dp[M][j];
        if (ans >= INF) ans -= INF;
    }
    cout << ans << '\n';
    return 0;
}