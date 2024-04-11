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
        VVI f(m);
        rep(i, m) {
            int k;
            cin >> k;
            f[i].resize(k);
            rep(j, k) cin >> f[i][j], f[i][j]--;
        }
        VI cnt(n);
        rep(i, m) for(int x: f[i]) cnt[x]++;
        auto it = max_element(all(cnt));
        if (*it > (m + 1) / 2) {
            int k = it - cnt.begin();
            int rest = (m + 1) / 2;
            VI ans(m);
            rep(i, m) {
                if (f[i].size() == 1) {
                    int x = f[i][0];
                    if (x == k) rest--;
                    ans[i] = x;
                } else {
                    int x = f[i][0], y = f[i][1];
                    if (x == k) swap(x, y);
                    ans[i] = x;
                }
            }
            //rep(i, m) cout << ans[i] << " \n"[i + 1 == m];
            //cout << rest << endl;
            rep(i, m) if (ans[i] != k) {
                for(int x: f[i]) if (x == k && rest > 0) {
                    ans[i] = k;
                    rest--;
                    break;
                }
            }
            if (rest < 0) cout << "NO\n";
            else {
                cout << "YES\n";
                rep(i, m) cout << ans[i] + 1 << " \n"[i + 1 == m];
            }
        } else {
            cout << "YES\n";
            rep(i, m) cout << f[i][0] + 1 << " \n"[i + 1 == m];
        }
    }
}