#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef pair<int, int> pi;
typedef pair<ll, ll> pll;
typedef vector<pi> vpi;

#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)
#define trav(a,x) for (auto& a: x)

#define pb push_back
#define rsz resize
#define all(x) begin(x), end(x)
#define mp make_pair
#define F first
#define S second

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll MOD = 1e9+7;// 998244353;

int t, n, m, w;
int dx[4] = {1,0,-1,0}, dy[4]={0,1,0,-1};
vvi a;
vvll dd, sd;
vvb vis;

void solve() {
    cin >> n >> m >> w;
    a.rsz(n, vi(m));
    F0R(i, n) F0R(j, m) cin >> a[i][j];
    dd.clear(); dd.rsz(n, vll(m, 1e18));
    sd.clear(); sd.rsz(n, vll(m, 1e18));
    queue<pi> q;
    dd[0][0]=0; q.push(mp(0, 0));
    while (! q.empty()) {
        pi cur = q.front();
        int x = cur.F, y = cur.S;
        q.pop();
        F0R(d, 4) {
            if (x+dx[d]>=0 && x+dx[d]<n && y+dy[d]>=0 && y+dy[d]<m && a[x+dx[d]][y+dy[d]]>-1 && dd[x+dx[d]][y+dy[d]]>dd[x][y]+w) {
                dd[x+dx[d]][y+dy[d]]=dd[x][y]+w;
                q.push(mp(x+dx[d], y+dy[d]));
            }
        }
    }
    sd[n-1][m-1]=0; q.push(mp(n-1, m-1));
    while (! q.empty()) {
        pi cur = q.front();
        int x = cur.F, y = cur.S;
        q.pop();
        F0R(d, 4) {
            if (x+dx[d]>=0 && x+dx[d]<n && y+dy[d]>=0 && y+dy[d]<m && a[x+dx[d]][y+dy[d]]>-1 && sd[x+dx[d]][y+dy[d]]>sd[x][y]+w) {
                sd[x+dx[d]][y+dy[d]]=sd[x][y]+w;
                q.push(mp(x+dx[d], y+dy[d]));
            }
        }
    }
    ll ans = 1e18;
    ans = min(ans, dd[n-1][m-1]);
    ll s=1e18, d=1e18;
    F0R(i, n) F0R(j, m) if (a[i][j]>0) {
        s=min(s, sd[i][j]+a[i][j]);
        d=min(d, dd[i][j]+a[i][j]);
    }
    if (s<1e18 && d<1e18) ans=min(ans, s+d);
    if (ans==1e18) cout << -1 << '\n';
    else cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}