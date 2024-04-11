
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

void solve() {
    int n, m;
    cin >> n >> m;
    vector<string> s(n, string(m, '0'));
    if(n % 2 == 1) {
        if(m % 2 == 1) {
            rep(i, 0, n) rep(j, 0, m) {
                if((i + j) % 2 == 0 && (i == 0 || i == n - 1 || j == 0 || j == m - 1)) {
                    s[i][j] = '1';
                }
            }
        }
        else {
            swap(n, m);
            for(int j = 0; j < m - 1; j += 2) {
                s[j][0] = '1';
                s[m - 1 - j][n - 1] = '1';
            }
            for(int i = 0; i < n; i += 2) {
                s[0][i] = '1';
                s[m - 1][i + 1] = '1';
            }
            swap(n, m);
        }
    }else {
        if(m % 2 == 1) {
            for(int j = 0; j < m - 1; j += 2) {
                s[0][j] = '1';
                s[n - 1][m - 1 - j] = '1';
            }
            for(int i = 0; i < n; i += 2) {
                s[i][0] = '1';
                s[i + 1][m - 1] = '1';
            }
        }
        else {
            for(int j = 1; j < m - 1; j += 2) {
                s[0][j] = '1';
                s[n - 1][m - j - 1] = '1';
            }
            for(int i = 1; i < n - 1; i += 2) {
                s[i][m - 1] = '1';
                s[n - i - 1][0] = '1';
            }
        }
    }
    rep(i, 0, n) {
        cout << s[i] << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int te;
    cin >> te;
    while(te--) solve();
}