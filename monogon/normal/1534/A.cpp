
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
    vector<string> s(n);
    rep(i, 0, n) cin >> s[i];
    char ev = '.';
    bool ok = true;
    rep(i, 0, n) rep(j, 0, m) {
        if(s[i][j] == 'R') {
            if((i + j) % 2 == 0) {
                if(ev == 'W') ok = false;
                ev = 'R';
            }
            else {
                if(ev == 'R') ok = false;
                ev = 'W';
            }
        }else if(s[i][j] == 'W') {
            if((i + j) % 2 == 0) {
                if(ev == 'R') ok = false;
                ev = 'W';
            }else {
                if(ev == 'W') ok = false;
                ev = 'R';
            }
        }
    }
    if(ok) {
        cout << "YES\n";
        if(ev == '.') ev = 'R';
        rep(i, 0, n) {
            rep(j, 0, m) {
                cout << (char) ((i + j) % 2 == 0 ? ev : 'R' ^ 'W' ^ ev);
            }
            cout << '\n';
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