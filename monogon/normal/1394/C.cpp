
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

const int N = 3e5 + 5, S = 5e5 + 5;
int n;
string s[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    vector<pii> ve;
    rep(i, 0, n) {
        cin >> s[i];
        int a = 0, b  = 0;
        for(char c : s[i]) {
            a += (c == 'B');
            b += (c == 'N');
        }
        ve.emplace_back(a, b);
        // cout << a << ' ' << b << endl;
    }
    int L = 0, R = 1e6 + 5;
    int xl, xr, yl, yr, difl, difr;
    int A = 0, B = 0;
    auto upd = [&](int m) {
        xl = 0, xr = 1e6 + 5;
        yl = 0, yr = 1e6 + 5;
        difl = -1e6 + 5, difr = 1e6 + 5;
        for(auto &pa : ve) {
            int a, b;
            tie(a, b) = pa;
            xl = max(xl, a - m);
            xr = min(xr, a + m);
            yl = max(yl, b - m);
            yr = min(yr, b + m);
            difl = max(difl, a - b - m);
            difr = min(difr, a - b + m);
        }
        if(difl <= xr - yr) {
            A = max(xl, difl + yr);
            B = yr;
        }else {
            A = xr;
            B = xr - difl;
        }
    };
    while(L < R) {
        int m = (L + R) / 2;
        upd(m);
        if(xl <= xr && yl <= yr && difl <= difr && difl <= xr - yl && difr >= xl - yr) {
            R = m;
        }else {
            L = m + 1;
        }
    }
    upd(L);

    cout << L << '\n';
    rep(i, 0, A) cout << 'B';
    rep(i, 0, B) cout << 'N';
    // cout << A << ' ' << B << endl;
    cout << '\n';
}