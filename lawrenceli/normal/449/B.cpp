#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define px real()
#define py imag()
#define rep(i, n) for (int i=0, _##i=(n); i<_##i; ++i)
#define repi(i, n) for (__typeof((n).begin()) i=(n).begin(), _##i=n.end(); i != _##i; ++i)
#define sz(x) int((x).size())
#define print(x) cerr << #x << ": " << x << endl
#define _ ios_base::sync_with_stdio(0); cin.tie(0);

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef complex<double> pnt;
typedef pair<pii, int> piii;
typedef pair<pll, ll> plll;

const int MAXN = 100100;
const ll INF = 1e15;

int n, m, k, s[MAXN], v[MAXN];
vector<piii> adj[MAXN];
int num[MAXN];
ll dist[MAXN];
bool train[MAXN];

void go() {
    rep(i, n) dist[i] = INF, train[i] = 0;
    priority_queue<plll> pq;
    pq.push(plll(pll(0, 0), 0));
    while (!pq.empty()) {
        ll d = -pq.top().fi.fi, x = pq.top().se;
        bool b = pq.top().fi.se;
        pq.pop();
        if (dist[x] != INF) continue;
        dist[x] = d;
        train[x] = b;
        rep(i, adj[x].size()) {
            ll d2 = d+adj[x][i].fi.se, y = adj[x][i].fi.fi;
            bool b2 = adj[x][i].se;
            if (d2 < dist[y])
                pq.push(plll(pll(-d2, b2), y));
        }
    }
}

int main() { _
    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    cin >> n >> m >> k;
    rep(i, m) {
        int a, b, c;
        cin >> a >> b >> c;
        a--, b--;
        adj[a].push_back(piii(pii(b, c), 1));
        adj[b].push_back(piii(pii(a, c), 1));
    }

    rep(i, k) {
        cin >> s[i] >> v[i];
        s[i]--;
        adj[0].push_back(piii(pii(s[i], v[i]), 0));
        adj[s[i]].push_back(piii(pii(0, v[i]), 0));
    }
    go();

    int ans = 0;
    rep(i, k) {
        if (v[i] > dist[s[i]]) ans++;
        else {
            if (train[s[i]]) ans++;
            else num[s[i]]++;
        }
    }

    rep(i, n)
        if (num[i])
            ans += num[i]-1;

    cout << ans << '\n';
    return 0;
}