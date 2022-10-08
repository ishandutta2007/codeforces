
#define _USE_MATH_DEFINES
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
template<typename T>
using minpq = priority_queue<T, vector<T>, greater<T>>;

// at most 26 operations, because we can change everything to 'a'.
// connect two characters if there's a mismatch between them.
// answer = sum(component_size - 1) for all connected components
// fix some character c in the string s.
// for each window, we want to know if it has a mismatch
// check each pair of characters if a mismatch occurs.
// do DFS to find number of components in each window

const int N = 2e5 + 5;
string s, t;
int n, m, ans[N];
using cd = complex<double>;
vi adj[N][6];
bool vis[N][6];

int dfs(int i, int j) {
    vis[i][j] = true;
    int res = 1;
    for(int y : adj[i][j]) {
        if(!vis[i][y]) res += dfs(i, y);
    }
    return res;
}

void fft(vector<cd> & a, bool inv) {
    int n = a.size();
    for (int i = 1, j = 0; i < n; i++) {
        int bit = n >> 1;
        for (; j & bit; bit >>= 1)
            j ^= bit;
        j ^= bit;
        if (i < j) swap(a[i], a[j]);
    }
    for(int len = 2; len <= n; len <<= 1) {
        cd wlen = polar(1.0, 2 * M_PI / len * (inv ? -1 : 1));
        for(int i = 0; i < n; i += len) {
            cd w(1);
            rep(j, 0, len / 2) {
                cd u = a[i + j], v = a[i + j + len / 2] * w;
                a[i + j] = u + v;
                a[i + j + len / 2] = u - v;
                w *= wlen;
            }
        }
    }
    if(inv) {
        for (cd &x : a) x /= n;
    }
}
vi mult(const vi &a, const vi &b) {
    vector<cd> A(all(a));
    vector<cd> B(all(b));
    int s = max(sz(A), sz(B)), n = 1;
    while(n < 2 * s) n <<= 1;
    A.resize(n);
    B.resize(n);
    fft(A, false);
    fft(B, false);
    vector<cd> c(n, 0);
    rep(i, 0, n) c[i] = A[i] * B[i];
    fft(c, true);
    vi ans(n, 0);
    rep(i, 0, n) ans[i] = round(c[i].real());
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> s >> t;
    n = s.length();
    m = t.length();
    for(char ch = 'a'; ch <= 'f'; ch++) {
        for(char ch2 = 'a'; ch2 <= 'f'; ch2++) {
            if(ch != ch2) {
                vi a(n + 1, 0), b(m, 0);
                rep(i, 0, n) a[n - i] = (s[i] == ch);
                rep(j, 0, m) b[j] = (t[j] == ch2);
                vi c = mult(a, b);
                rep(i, 0, n - m + 1) {
                    if(c[n - i] > 0) {
                        adj[i][ch - 'a'].push_back(ch2 - 'a');
                        adj[i][ch2 - 'a'].push_back(ch - 'a');
                    }
                }
            }
        }
    }
    rep(i, 0, n - m + 1) {
        rep(j, 0, 6) {
            if(!vis[i][j]) {
                int comp = dfs(i, j);
                ans[i] += comp - 1;
            }
        }
        cout << ans[i] << ' ';
    }
    cout << '\n';
}