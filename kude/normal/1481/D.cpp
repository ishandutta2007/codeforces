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

void solve() {
    int n, m;
    cin >> n >> m;
    vector<string> s(n);
    rep(i, n) cin >> s[i];
    rep(i, n) rep(j, i) {
        if (s[i][j] == s[j][i]) {
            cout << "YES\n";
            cout << i + 1 << ' ';
            swap(i, j);
            rep(z, m) {
                cout << i + 1 << " \n"[z + 1 == m];
                swap(i, j);
            }
            return;
        }
    }
    if (m & 1) {
        cout << "YES\n";
        int i = 1, j = 2;
        cout << i << ' ';
        swap(i, j);
        rep(z, m) {
            cout << i << " \n"[z + 1 == m];
            swap(i, j);
        }
        return;
    }
    rep(i, n) {
        int a = -1, b = -1;
        rep(j, n) if (i != j) {
            if (s[i][j] == 'a') a = j;
            else b = j;
        }
        if (a != -1 && b != -1) {
            cout << "YES\n";
            int p = (i + 1) % n;
            int t;
            if (s[p][i] == 'a') t = a;
            else t = b;
            const int m2 = m / 2;

            int x, y;
            if (m2 & 1) {
                x = p, y = i;
            } else {
                x = i, y = p;
            }
            cout << x + 1 << ' ';
            swap(x, y);
            rep(z, m2) {
                cout << x + 1 << ' ';
                swap(x, y);
            }

            x = t, y = i;
            rep(z, m2) {
                cout << x + 1 << " \n"[z + 1 == m2];
                swap(x, y);
            }
            return;
        }
    }
    cout << "NO\n";
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while(tt--) solve();
}