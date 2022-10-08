
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

vector<string> build(int n, int m, int h) {
    vector<string> s(n, string(m, '.'));
    rep(i, 0, n) rep(j, 0, m) {
        char ch = 'a';
        if((i/2 + j/2) % 2 == 1) ch += 2;
        if(j % 2 == 1) ch++;
        s[i][j] = ch;
    }
    for(int i = 0; i < n; i += 2) {
        for(int j = 0; j + 1 < m; j += 2) {
            if(h > 0) {
                swap(s[i + 1][j], s[i][j + 1]);
                h -= 2;
            }
        }
    }
    return s;
}

void solve() {
    int n, m, h;
    cin >> n >> m >> h;
    int dom = n * m / 2;
    if((n % 2 == 0 && h % 2 == 0) || (m % 2 == 0 && (dom - h) % 2 == 0)) {
        if((m % 2 == 1 && 2 * h + n > n * m) || (n % 2 == 1 && 2 * (dom - h) + m > n * m)) {
            cout << "NO\n";
            return;
        }
        cout << "YES\n";
        vector<string> ans(n);
        if(n % 2 == 1) {
            vector<string> s = build(m, n, dom - h);
            rep(i, 0, n) ans[i].assign(m, '.');
            rep(i, 0, n) rep(j, 0, m) ans[i][j] = s[j][i];
        }else {
            ans = build(n, m, h);
        }
        rep(i, 0, n) {
            cout << ans[i] << '\n';
        }
    }else {
        cout << "NO\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int te;
    cin >> te;
    while(te--) solve();
}