
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

const int N = 1e6 + 5, M = 1e9 + 7;
string s, t;
int n, m;
ll h[N], pow31[N][2];

ll mod(ll a, ll m) {
    return (a % m + m) % m;
}
ll euclid(ll a, ll b, ll &x, ll &y) {
    ll xx = y = 0;
    ll yy = x = 1;
    while(b) {
        ll q = a / b;
        ll t = b; b = a % b; a = t;
        t = xx; xx = x - q * xx; x = t;
        t = yy; yy = y - q * yy; y = t;
    }
    return a;
}
ll modinverse(ll a, ll m) {
    ll x, y;
    ll g = euclid(a, m, x, y);
    return g > 1 ? -1 : mod(x, m);
}

ll gethash(int l, int r) {
    if(l == 0) return h[r];
    return mod((h[r] - h[l - 1]) * pow31[l][1], M);
}

bool check(int x, int y) {
    int px = -1, py = -1, j = 0;
    rep(i, 0, n) {
        if(s[i] == '0') {
            if(px != -1 && gethash(j, j + x - 1) != gethash(px, px + x - 1)) {
                return false;
            }
            px = j;
            j += x;
        }else {
            if(py != -1 && gethash(j, j + y - 1) != gethash(py, py + y - 1)) {
                return false;
            }
            py = j;
            j += y;
        }
    }
    return x != y || gethash(py, py + y - 1) != gethash(px, px + x - 1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> s >> t;
    n = s.length();
    m = t.length();
    pow31[0][0] = pow31[0][1] = 1;
    pow31[1][0] = 31;
    pow31[1][1] = modinverse(31, M);
    rep(i, 2, N) {
        rep(j, 0, 2) {
            pow31[i][j] = mod(pow31[1][j] * pow31[i - 1][j], M);
        }
    }
    int A[2] = {0, 0};
    rep(i, 0, n) {
        A[s[i] - '0']++;
    }
    ll H = 0;
    rep(i, 0, m) {
        h[i] = H = (H + (t[i] - 'a') * pow31[i][0]) % M;
    }
    int ans = 0;
    rep(x, 1, 2 + m / A[0]) {
        int y = (m - A[0] * x) / A[1];
        if(x > 0 && y > 0 && A[0] * x + A[1] * y == m) {
            ans += check(x, y);
        }
    }
    cout << ans << '\n';
}