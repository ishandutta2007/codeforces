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
#define MAXN 113
#define INF 1000000007

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpi;
typedef vector<pll> vpl;

int N;
int arr[MAXN];
int dp[MAXN][MAXN][MAXN][2];
int evens, odds;
int ans;

int32_t main()
{
    cout << fixed << setprecision(12);
    cerr << fixed << setprecision(4);
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> N;
    evens = N / 2; odds = N - evens;
    FOR(i, 0, N)
    {
        cin >> arr[i];
        if (arr[i] == 0)
        {
            arr[i] = -1;
        }
        else
        {
            arr[i] %= 2;
        }
    }
    FOR(i, 0, N + 1)
    {
        FOR(j, 0, N + 1)
        {
            FOR(k, 0, N + 1)
            {
                dp[i][j][k][0] = INF;
                dp[i][j][k][1] = INF;
            }
        }
    }
    dp[0][evens][odds][0] = 0;
    dp[0][evens][odds][1] = 0;
    FOR(i, 0, N)
    {
        FOR(j, 0, N + 1)
        {
            FOR(k, 0, N + 1)
            {
                if (arr[i] != 1 && j > 0)
                {
                    ckmin(dp[i + 1][j - 1][k][0], dp[i][j][k][0]);
                    ckmin(dp[i + 1][j - 1][k][0], dp[i][j][k][1] + 1);
                }
                if (arr[i] != 0 && k > 0)
                {
                    ckmin(dp[i + 1][j][k - 1][1], dp[i][j][k][0] + 1);
                    ckmin(dp[i + 1][j][k - 1][1], dp[i][j][k][1]);
                }
                // cerr << "pos " << i << " rem " << j << " rem " << k << ' ' << dp[i][j][k][0] << ' ' << dp[i][j][k][1] << endl;
            }
        }
    }
    ans = min(dp[N][0][0][0], dp[N][0][0][1]);
    cout << ans << '\n';
    return 0;
}