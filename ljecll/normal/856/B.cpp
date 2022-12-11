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
#define CO 1000007
#define INF 1000000931
#define MOD 1000000933
#define MAXN 2000013

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpi;
typedef vector<pll> vpl;

int TC, T;
int N;
vi str[MAXN];
map<int, int> ch[MAXN];
map<pii, int> mp;

int fc[MAXN], depth[MAXN];
pii hashval[MAXN];
pii msg[MAXN];
vi edge[MAXN];
bitset<MAXN> go;
int dp[MAXN][2]; //dp[i][1] = you did take me, 0 is you didn't
int ans;

vi stov(string s)
{
    vi res(SZ(s));
    FOR(i, 0, SZ(s))
    {
        res[i] = (s[i] - 'a' + 1);
    }
    return res;
}

int mul(int a, int b, ll mod)
{
    return ((ll) a * b % mod);
}
int ad(int a, int b, int mod)
{
    a += b; if (a >= mod) a -= mod;
    return a;
}
int sb(int a, int b, int mod)
{
    a -= b; if (a < 0) a += mod;
    return a;
}

void solve(int u)
{
    for (int v : edge[u])
    {
        solve(v);
    }
    //dp[x] = how many strings do we have to waste?
    //max independent set = if we don't take this guy, we can take all children.
    //if we take this guy, we cannot take all chidlren.
    int mn = INF;
    dp[u][0] = 1;
    dp[u][1] = 0;
    for (int v : edge[u])
    {
        dp[u][1] += dp[v][0];
        dp[u][0] += dp[v][1];
    }
    if (u != 0) ckmin(dp[u][1], dp[u][0]);
}

void ins(vi s)
{
    // cerr << "INSERT " << endl;
    int node = 0;
    FOR(i, 0, SZ(s))
    {
        // cerr << "NODE " << node << endl;
        int c = s[i];
        if (ch[node].find(c) == ch[node].end())
        {
            ch[node][c] = T;
            // cerr << "ch " << node << ',' << c << " = " << ch[node][c] << endl;
            hashval[T].fi = ad(mul(hashval[node].fi, CO, INF), c, INF);
            hashval[T].se = ad(mul(hashval[node].se, CO, MOD), c, MOD);
            msg[T].fi = (node == 0 ? 0 : ad(mul(msg[node].fi, CO, INF), c, INF));
            msg[T].se = (node == 0 ? 0 : ad(mul(msg[node].se, CO, MOD), c, MOD));
            // cerr << "hash " << T << ' ' << hashval[T].fi << ',' << hashval[T].se << endl;
            mp[hashval[T]] = T;
            fc[T] = s[0];
            depth[T] = depth[node] + 1;
            T++;
        }
        node = ch[node][c];
        // cerr << node << ',';
    }
    // cerr << endl;
}

int32_t main()
{
    cout << fixed << setprecision(12);
    cerr << fixed << setprecision(4);
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> TC;
    while(TC--)
    {
        cin >> N;
        FOR(i, 0, N)
        {
            string temps;
            cin >> temps;
            str[i] = stov(temps);
        }
        T = 1;
        hashval[0] = {0, 0};
        mp[{0, 0}] = 0;
        FOR(i, 0, N)
        {
            ins(str[i]);
        }
        FOR(i, 0, T)
        {
            go[i] = true;
        }
        FOR(i, 1, T)
        {
            //what do you get after deleting thef irst char?
            int c = fc[i], d = depth[i];
            auto it = mp.find(msg[i]);
            if (it != mp.end())
            {
                edge[it -> se].PB(i);
                go[i] = false;
                // cerr << "EDGE " << it -> se << ',' << i << endl;
            }
        }
        // cout << "T = " << T << endl;
        ans = T;
        FOR(i, 0, T)
        {
            if (go[i])
            {
                solve(i);
                ans -= (i == 0 ? dp[i][0] : dp[i][1]);
            }
        }
        cout << ans << '\n';
        FOR(i, 0, T)
        {
            ch[i].clear();
            edge[i].clear();
        }
        mp.clear();
    }
    return 0;
}