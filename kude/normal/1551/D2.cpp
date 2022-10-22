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
        int n, m, k;
        cin >> n >> m >> k;
        int k1 = k, k2 = n * m / 2 - k1;
        bool flipped = false;
        if (m % 2) {
            flipped = true;
            swap(n, m);
            swap(k1, k2);
        }
        vector<string> ans(n, string(m, '.'));
        if (n % 2 == 0) {
            bool ok = k2 % 2 == 0;
            if (!ok) {
                cout << "NO\n";
                continue;
            }
            for(int i = 0; i < n; i += 2) for(int j = 0; j < m; j += 2) {
                char c1 = 'a', c2 = 'b';
                if ((i / 2 + j / 2) % 2 == 1) {
                    c1 = 'c', c2 = 'd';
                }
                if (k2) {
                    k2 -= 2;
                    ans[i][j] = ans[i+1][j] = c1;
                    ans[i][j+1] = ans[i+1][j+1] = c2;
                } else {
                    ans[i][j] = ans[i][j+1] = c1;
                    ans[i+1][j] = ans[i+1][j+1] = c2;
                }
            }
        } else {
            int r = m / 2;
            bool ok = r <= k1 && r % 2 == k1 % 2 && k2 % 2 == 0;
            if (!ok) {
                cout << "NO\n";
                continue;
            }
            {
                int i = n - 1;
                for(int j = 0; j < m; j += 2) {
                    char c1 = 'a', c2 = 'b';
                    if ((i / 2 + j / 2) % 2 == 1) {
                        c1 = 'c', c2 = 'd';
                    }
                    ans[i][j] = ans[i][j+1] = c1;
                }
                k1 -= r;
            }
            for(int i = 0; i < n - 1; i += 2) for(int j = 0; j < m; j += 2) {
                char c1 = 'a', c2 = 'b';
                if ((i / 2 + j / 2) % 2 == 1) {
                    c1 = 'c', c2 = 'd';
                }
                if (k1) {
                    k1 -= 2;
                    ans[i][j] = ans[i][j+1] = c1;
                    ans[i+1][j] = ans[i+1][j+1] = c2;
                } else {
                    ans[i][j] = ans[i+1][j] = c1;
                    ans[i][j+1] = ans[i+1][j+1] = c2;
                }
            }
        }

        cout << "YES\n";
        if (flipped) {
            vector<string> t(m, string(n, '.'));
            rep(i, n) rep(j, m) t[j][i] = ans[i][j];
            swap(n, m);
            swap(t, ans);
        }
        rep(i, n) cout << ans[i] << '\n';
    }
}