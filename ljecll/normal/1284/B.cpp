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
#define MAXN 100013

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpi;
typedef vector<pll> vpl;

int N;
vi arr[MAXN];
bitset<MAXN> ok;
ll ans;
ll dp[10 * MAXN];

int32_t main()
{
    cout << fixed << setprecision(12);
    cerr << fixed << setprecision(4);
    ios_base::sync_with_stdio(false); cin.tie(0);
    //subtract the # that are unstrictly decreasing
    cin >> N;
    FOR(i, 0, N)
    {
        int x; cin >> x;
        while(x--)
        {
            int y;
            cin >> y;
            arr[i].PB(y);
        }
    }
    ans = 1ll * N * N;
    FOR(i, 0, N)
    {
        FOR(j, 1, SZ(arr[i]))
        {
            if (arr[i][j - 1] < arr[i][j])
            {
                ok[i] = true;
            }
        }
        if (ok[i]) continue;
        dp[arr[i].back()]++;
    }
    FORD(i, 1000007, 0)
    {
        dp[i] += dp[i + 1];
    }
    FOR(i, 0, N)
    {
        if (ok[i]) continue;
        int v = arr[i][0];
        //how many have last values in the range v....infinity?
        ans -= (dp[v]);
    }
    cout << ans << '\n';
    return 0;
}