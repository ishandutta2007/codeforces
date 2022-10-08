
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
    int n;
    cin >> n;
    vector<string> s(n);
    vector<pii> ve;
    rep(i, 0, n) {
        cin >> s[i];
        rep(j, 0, n) {
            if(s[i][j] == '*') {
                ve.push_back({i, j});
            }
        }
    }
    assert(sz(ve) == 2);
    int x, y, X, Y;
    tie(x, y) = ve[0];
    tie(X, Y) = ve[1];
    if(x != X) {
        if(y != Y) {
            s[x][Y] = '*';
            s[X][y] = '*';
        }else {
            int y2 = 0;
            if(y2 == y) y2++;
            s[x][y2] = '*';
            s[X][y2] = '*';
        }
    }else {
        int x2 = 0;
        if(x2 == x) x2++;
        s[x2][y] = s[x2][Y] = '*';
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