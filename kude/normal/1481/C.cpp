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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while(tt--) {
        int n, m;
        cin >> n >> m;
        VI a(n), b(n), c(m);
        rep(i, n) cin >> a[i], --a[i];
        rep(i, n) cin >> b[i], --b[i];
        rep(i, m) cin >> c[i], --c[i];
        VVI todo(n);
        rep(i, n) {
            if (a[i] != b[i]) todo[b[i]].push_back(i);
        }
        int trash;
        int last = c[m-1];
        VI ans(m);
        if (!todo[last].empty()) {
            trash = todo[last].back(); todo[last].pop_back();
        } else {
            for(trash = 0; trash < n; ++trash) {
                if (b[trash] == last) break;
            }
            if (trash == n) {
                cout << "NO\n";
                continue;
            }
        }
        ans[m-1] = trash;
        rep(i, m - 1) {
            if (todo[c[i]].empty()) {
                ans[i] = trash;
            } else {
                ans[i] = todo[c[i]].back(); todo[c[i]].pop_back();
            }
        }
        bool ok = true;
        rep(i, n) if (!todo[i].empty()) {
            ok = false;
            break;
        }
        if (!ok) {
            cout << "NO\n";
            continue;
        }
        cout << "YES\n";
        rep(i, m) cout << ans[i] + 1 << " \n"[i + 1 == m];
    }
}