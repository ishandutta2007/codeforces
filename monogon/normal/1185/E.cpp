
#include <bits/stdc++.h>

#define ll long long
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
#define vi vector<int>
#define pii pair<int, int>
#define rep(i, a, b) for(int i = (a); i < (b); i++)
using namespace std;

const int N = 2005;
int t, n, m;
string s[N], s2[N];
int minx[26], maxx[26], miny[26], maxy[26];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> n >> m;
        rep(i, 0, n) cin >> s[i];
        rep(i, 0, 26) {
            minx[i] = miny[i] = 1e9;
            maxx[i] = maxy[i] = -1e9;
        }
        int maxch = -1;
        rep(i, 0, n) rep(j, 0, m) {
            char c = s[i][j];
            if(c != '.') {
                maxch = max(maxch, c - 'a');
                minx[c - 'a'] = min(minx[c - 'a'], i);
                maxx[c - 'a'] = max(maxx[c - 'a'], i);
                miny[c - 'a'] = min(miny[c - 'a'], j);
                maxy[c - 'a'] = max(maxy[c - 'a'], j);
            }
        }
        rep(i, 0, n) s2[i].assign(m, '.');
        bool flag = true;
        rep(c, 0, 26) {
            if(minx[c] <= n) {
                if(minx[c] == maxx[c]) {
                    rep(j, miny[c], maxy[c] + 1) {
                        s2[minx[c]][j] = (c + 'a');
                    }
                }else if(miny[c] == maxy[c]) {
                    rep(i, minx[c], maxx[c] + 1) {
                        s2[i][miny[c]] = (c + 'a');
                    }
                }else {
                    flag = false;
                    break;
                }
            }
        }
        rep(i, 0, n) {
            if(s2[i] != s[i]) {
                flag = false;
                break;
            }
        }
        if(flag) {
            cout << "YES\n";
            cout << maxch + 1 << '\n';
            rep(c, 0, maxch + 1) {
                if(minx[c] <= n) {
                    cout << minx[c] + 1 << ' ' << miny[c] + 1 << ' ' << maxx[c] + 1 << ' ' << maxy[c] + 1 << '\n';
                }else {
                    cout << minx[maxch] + 1 << ' ' << miny[maxch] + 1 << ' ' << maxx[maxch] + 1 << ' ' << maxy[maxch] + 1 << '\n';
                }
            }
        }else {
            cout << "NO\n";
        }
    }
}