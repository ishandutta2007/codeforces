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

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpi;
typedef vector<pll> vpl;

const int INF = 998244353;
const int MAXN = 3013;

int add(int a, int b)
{
    a += b; if (a >= INF) a -= INF;
    return a;
}
int mul(int a, int b)
{
    return (ll) a * b % INF;
}
vi stov(string ss)
{
    vi res(SZ(ss));
    FOR(i, 0, SZ(ss))
    {
        res[i] = ss[i] - 'a';
    }
    return res;
}

vi S, T;
// int dp[MAXN], tmp[MAXN];
int ways[MAXN];
int ans;
bitset<MAXN> vis[MAXN];
int dp[MAXN][MAXN];

int solve(int L, int R)
{
    if (L > R) return 1;
    if (vis[L][R])
    {
        return dp[L][R];
    }
    vis[L][R] = true;
    int pos = R - L;
    if (R >= SZ(T) || T[R] == S[pos])
    {
        dp[L][R] = add(dp[L][R], solve(L, R - 1));
    }
    if (L >= SZ(T) || T[L] == S[pos])
    {
        dp[L][R] = add(dp[L][R], solve(L + 1, R));
    }
    // cerr << "SOLVE " << L << " " << R << " = " << dp[L][R] << endl;
    return dp[L][R];
}

int32_t main()
{
    cout << fixed << setprecision(12);
    cerr << fixed << setprecision(4);
    ios_base::sync_with_stdio(false); cin.tie(0);
    string temps; cin >> temps;
    S = stov(temps);
    cin >> temps;
    T = stov(temps);
    //suppose the T is purely from adding chars to front.
    //so then it's the # of ways
    // dp[SZ(T)] = 1;
    // FOR(i, 0, SZ(S))
    // {
    //     FOR(j, 0, SZ(T) + 1)
    //     {
    //         tmp[j] = dp[j];
    //         dp[j] = 0;
    //     }
    //     FORD(j, SZ(T) + 1, 0)
    //     {
    //         dp[j] = add(dp[j], tmp[j]);
    //         if (j != 0 && T[j - 1] == S[i])
    //         {
    //             dp[j - 1] = add(dp[j - 1], tmp[j]);
    //         }
    //     }
    //     ans = add(ans, dp[0]);
    // }
    FOR(i, SZ(T) - 1, SZ(S))
    {
        // cerr << solve(0, i) << ' ' << SZ(S) - i << endl;
        ans = add(ans, solve(0, i));
    }
    cout << ans << '\n';
    return 0;
}