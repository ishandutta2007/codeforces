
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

const string S = "LRUD";
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};

pii mv(int x, int y, char c) {
    int d = 0;
    while(S[d] != c) d++;
    return {x + dx[d], y + dy[d]};
}

void solve() {
    string s;
    cin >> s;
    int n = s.length();
    int ax = 0, ay = 0;
    auto check = [&](int x, int y) {
        int X = 0, Y = 0;
        rep(j, 0, n) {
            int xx, yy;
            tie(xx, yy) = mv(X, Y, s[j]);
            if(xx == x && yy == y) continue;
            else {
                X = xx;
                Y = yy;
            }
        }
        if(X == 0 && Y == 0) {
            ax = x; ay = y;
        }
    };
    check(5000, 5000);
    rep(i, 0, n) {
        int x = 0, y = 0;
        rep(j, 0, i + 1) tie(x, y) = mv(x, y, s[j]);
        if(x == 0 && y == 0) continue;
        check(x, y);
    }
    cout << ax << ' ' << ay << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int te;
    cin >> te;
    while(te--) {
        solve();
    }
}