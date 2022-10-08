
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

#define ll long long
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define vi vector<int>
#define pii pair<int, int>
#define rep(i, a, b) for(int i = (a); i < (b); i++)
using namespace std;
template<typename T>
using minpq = priority_queue<T, vector<T>, greater<T>>;

using cd = complex<double>;

void fft(vector<cd> &a, bool inv) {
    int n = sz(a);
    for(int i = 1, j = 0; i < n; i++) {
        int bit = n >> 1;
        for(; j & bit; bit >>= 1) j ^= bit;
        j ^= bit;
        if(i < j) swap(a[i], a[j]);
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
    if(inv) for(cd &x : a) x /= n;
}

vi mult(vi &a, vi &b) {
    vector<cd> A(all(a)), B(all(b));
    int n = 1;
    while(n < 2 * max(sz(A), sz(B))) n <<= 1;
    A.resize(n);
    B.resize(n);
    fft(A, false);
    fft(B, false);
    rep(i, 0, n) {
        A[i] *= B[i];
    }
    fft(A, true);
    vi ans(n);
    rep(i, 0, n) {
        ans[i] = round(A[i].real());
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int te;
    cin >> te;
    while(te--) {
        int n;
        string s;
        cin >> n >> s;
        vi a(n + 1, 0), b(n + 1, 0);
        rep(i, 0, n) {
            if(s[i] == 'V') {
                a[i] = 1;
            }else if(s[i] == 'K') {
                b[n - i] = 1;
            }
        }
        vi c = mult(a, b);
        vi ve;
        vector<bool> bs(n + 1, true);
        rep(i, 1, n + 1) {
            if(c[n + i] != 0 || c[n - i] != 0) {
                bs[i] = false;
            }
        }
        rep(i, 1, n + 1) {
            bool flag = true;
            for(int j = i; j <= n; j += i) {
                flag &= bs[j];
            }
            if(flag) ve.push_back(i);
        }
        cout << sz(ve) << '\n';
        for(int x : ve) {
            cout << x << ' ';
        }
        cout << '\n';
    }
}