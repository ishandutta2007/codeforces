
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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int te;
    cin >> te;
    while(te--) {
        int n, m;
        cin >> n >> m;
        vector<string> s(n);
        vector<array<int, 6>> ops;
        rep(i, 0, n) {
            cin >> s[i];
        }
        auto flip = [&](int x, int y) {
            s[x][y] = '0' ^ '1' ^ s[x][y];
        };
        auto bruh = [&](int i, int j) {
            if(s[i][j] == '1') {
                if(i < n - 2) {
                    if(j == m - 1) {
                        ops.push_back({i, j, i + 1, m - 1, i + 1, m - 2});
                        flip(i, j);
                        flip(i + 1, m - 1);
                        flip(i + 1, m - 2);
                    }else {
                        ops.push_back({i, j, i + 1, j, i + 1, j + 1});
                        flip(i, j);
                        flip(i + 1, j);
                        flip(i + 1, j + 1);
                    }
                }else if(j < m - 2) {
                    if(i == n - 1) {
                        ops.push_back({i, j, i - 1, j + 1, i, j + 1});
                        flip(i, j);
                        flip(i - 1, j + 1);
                        flip(i, j + 1);
                    }else {
                        ops.push_back({i, j, i, j + 1, i + 1, j + 1});
                        flip(i, j);
                        flip(i, j + 1);
                        flip(i + 1, j + 1);
                    }
                }
            }
        };
        rep(i, 0, n - 2) {
            rep(j, 0, m) {
                bruh(i, j);
            }
        }
        rep(j, 0, m - 1) {
            rep(i, n - 2, n) {
                bruh(i, j);
            }
        }
        bool f[2][2] = {{false, false}, {false, false}};
        if(s[n - 1][m - 1] == '1') {
            rep(i, 0, 2) rep(j, 0, 2) f[i][j] ^= 1;
            f[0][0] ^= 1;
        }
        if(s[n - 2][m - 1] == '1') {
            rep(i, 0, 2) rep(j, 0, 2) f[i][j] ^= 1;
            f[1][0] ^= 1;
        }
        if(s[n - 1][m - 2] == '1') {
            rep(i, 0, 2) rep(j, 0, 2) f[i][j] ^= 1;
            f[0][1] ^= 1;
        }
        if(s[n - 2][m - 2] == '1') {
            rep(i, 0, 2) rep(j, 0, 2) f[i][j] ^= 1;
            f[1][1] ^= 1;
        }
        if(f[0][0]) {
            ops.push_back({n - 1, m - 2, n - 2, m - 1, n - 2, m - 2});
        }
        if(f[0][1]) {
            ops.push_back({n - 1, m - 1, n - 2, m - 1, n - 2, m - 2});
        }
        if(f[1][0]) {
            ops.push_back({n - 1, m - 2, n - 1, m - 1, n - 2, m - 2});
        }
        if(f[1][1]) {
            ops.push_back({n - 1, m - 2, n - 2, m - 1, n - 1, m - 1});
        }
        assert(sz(ops) <= n * m);
        cout << sz(ops) << '\n';
        for(auto &ar : ops) {
            rep(i, 0, 6) {
                cout << ar[i] + 1 << ' ';
            }
            cout << '\n';
        }
    }
}