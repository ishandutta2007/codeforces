#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < int(n); ++i)
#define rrep(i,n) for(int i = int(n)-1; i >= 0; --i)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
template<class T> void chmax(T& a, const T& b) {a = max(a, b);}
template<class T> void chmin(T& a, const T& b) {a = min(a, b);}
using ll = long long;
using P = pair<int,int>;
using VI = vector<int>;
using VVI = vector<VI>;
using VL = vector<ll>;
using VVL = vector<VL>;

bool occupied[400][400];
int num[400][400];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while(tt--) {
        int n, m;
        cin >> n >> m;
        VI a(n * m);
        rep(i, n * m) cin >> a[i];
        int mx = -1;
        {
            VI ds; ds.reserve(n * m);
            rep(i, n * m) ds.push_back(a[i]);
            sort(all(ds));
            ds.erase(unique(all(ds)), ds.end());
            rep(i, n * m) a[i] = lower_bound(all(ds), a[i]) - ds.begin();
            mx = ds.size();
        }
        VI hist(mx);
        rep(i, n * m) hist[a[i]]++;
        int x = 0, y = 0;
        rep(i, mx) {
            rep(_, hist[i]) {
                num[x][y] = i;
                y++;
                if (y == m) x++, y = 0;
            }
        }
        assert(x == n && y == 0);
        vector<vector<int>> idxs(mx);
        rep(i, n) rrep(j, m) idxs[num[i][j]].push_back(i * m + j);
        rep(i, mx) reverse(all(idxs[i]));
        int ans = 0;
        rep(i, n) rep(j, m) occupied[i][j] = false;
        for(int x: a) {
            int idx = idxs[x].back(); idxs[x].pop_back();
            int i0 = idx / m, j0 = idx % m;
            for(int j = 0; j < j0; j++) ans += occupied[i0][j];
            occupied[i0][j0] = true;
        }
        cout << ans << '\n';
    }
}