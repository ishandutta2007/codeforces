#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define pb push_back
#define mii map <int, int>
#define mll map <ll, ll>
#define pii pair <int, int>
#define pll pair <ll, ll>
#define vi vector <int>
#define vd vector <double>
#define vll vector <ll>
#define fi first
#define se second
#define si set <int>
#define sll set <ll>
#define spii set <pii>
#define vs vector <string>
#define vpii vector <pair <int, int> >
#define vpll vector <pair <long long, long long> >
#define vvi vector <vector <int> >
#define vvpii vector <vector <pii > >
#define vb vector <bool>
#define vvb vector <vb>
#define mp make_pair
#define vvll vector <vll>
#define vsi vector <si>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define MANX MAXN
#define itn int
#define dbg(x); {cout << #x << "=" << x << ", ";}
#define in(x); { for (auto &to : x) cin >> to;}
#define out(x); { for (auto &to : x) cout << to << " "; cout << '\n'; }

template<class T>
bool uin(T &a, T b) { return a > b ? (a = b, true) : false; }

template<class T>
bool uax(T &a, T b) { return a < b ? (a = b, true) : false; }

const ll INFLL = 1e18;
const int MAXN = 2e5 + 100;
const ll INF = 1e9;
const int mod1 = 1e9 + 7;
const int mod2 = 1e9 + 21;
vll ans;
vi dp;
vb used;
int n;
vvi g;
vi par;
vb done;
int times;

void cnt(int s, int p, int &total) {
    dp[s] = 1;
    total++;
    for (auto to:g[s]) {
        if (to == p || used[to])
            continue;
        cnt(to, s, total);
        dp[s] += dp[to];
    }
}

int find_centroid(int s, int p, int total) {
    for (auto to:g[s]) {
        if (to == p || used[to])
            continue;
        if (dp[to] > total / 2)
            return find_centroid(to, s, total);
    }
    return s;
}

void ha(int s, int p, unordered_set<int> &ss) {
    done[s]=false;
    dp[s] = 1;
    ss.insert(s);
    par[s] = p;
    for (auto to:g[s]) {
        if (to == p || used[to])
            continue;
        ha(to, s, ss);
        dp[s] += dp[to];
    }
}

void go(int s) {
    times = 0;
    int total = 0;
    cnt(s, s, total);
    s = find_centroid(s, s, total);
    unordered_set<int> ss;
    vector<ll> anss(total + 1);
    ha(s, s, ss);
//    cout << s << '\n';
    {
        ll sum = 0, sum_sq = 0;
        for (auto to:g[s]) {
            if (used[to])
                continue;
            sum += dp[to];
            sum_sq += 1ll * dp[to] * dp[to];
        }
        anss[0] += (sum * sum - sum_sq) / 2;
        anss[0] += total - 1;
    }
    if (ss.find(0) != ss.end()) {
        int need = 0;
        if (s == 0) {
            ll sum = 0, sum_sq = 0;
            for (auto to:g[s]) {
                if (used[to])
                    continue;
                sum += dp[to];
                sum_sq += 1ll * dp[to] * dp[to];
            }
            anss[1] += (sum * sum - sum_sq) / 2;
            anss[1] += total - 1;
            need = 1;
        }
        if (ss.find(need) != ss.end()) {
            int p = need;
            while (par[p] != s) {
//                cout << "P = " << p << '\n';
                done[p] = true, p = par[p];
            }
//            cout << p << " " << s << '\n';
            done[p] = true;
            done[s] = true;
            int a = need, b = s;
            anss[need + 1] += 1ll * dp[a] * (dp[b] - dp[p]);
            while (ss.find(need + 1) != ss.end()) {
                need++;
//                cout << a << " " << b << " " << need << " " << done[need] << '\n';
                if (done[need]) {
                    if (b == s)
                        anss[need + 1] += 1ll * dp[a] * (dp[b] - dp[p]);
                    else
                        anss[need + 1] += 1ll * dp[a] * dp[b];
                    continue;
                }
                int now = need;
                while (!done[par[now]])
                    done[now] = true, now = par[now];
                done[now] = true;
                if (par[now] != a && par[now] != b)
                    break;
                if (par[now] == a)
                    a = need;
                else
                    b = need;
                if (b == s)
                    anss[need + 1] += 1ll * dp[a] * (dp[b] - dp[p]);
                else
                    anss[need + 1] += 1ll * dp[a] * dp[b];
            }
        }
    }
//    cout << "WAS\n";
//    cout << s << '\n';
//    for (int i = 0; i <= total; i++)
//        cout << anss[i] << " ";
//    cout << '\n';
    ll sum = 0;
    for (int i = total; i >= 0; i--)
        anss[i] -= sum, sum += anss[i];
//    cout << "AFTER\n";
//    cout << s << '\n';
//    for (int i = 0; i <= total; i++)
//        cout << anss[i] << " ";
//    cout << '\n';
//    for (auto to:ss)
//        cout << to << " ";
//    cout << '\n';
    for (int i = 0; i <= total; i++)
        ans[i] += anss[i];
    used[s] = true;
    for (auto to:g[s]) {
        if (!used[to])
            go(to);
    }
}

void solve() {
    cin >> n;
    done = vb(n);
    par = vi(n);
    dp = vi(n);
    ans = vll(n + 1);
    used = vb(n);
    g = vvi(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    go(0);
    for (int i = 0; i <= n; i++)
        cout << ans[i] << ' ';
    cout << '\n';
}

int main() {
#ifdef Mip182
    freopen("a.in", "r", stdin);
#else
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#endif
    int _t;
    _t = 1;
    cin >> _t;
    while (_t--)
        solve();
#ifdef Mip182
    cout << '\n' << "Time : " << (double) (clock()) / CLOCKS_PER_SEC << '\n';
#endif
}