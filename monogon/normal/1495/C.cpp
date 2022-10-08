
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
    rep(i, 0, n) {
        cin >> s[i];
    }
    
    int r = (n % 3 == 0 ? 1 : 0);
    for(int i = r; i < n; i += 3) {
        fill(all(s[i]), 'X');
    }
    for(int i = r; i + 3 < n; i += 3) {
        if(m == 1 || (s[i + 1][1] == '.' && s[i + 2][1] == '.')) {
            s[i + 1][0] = s[i + 2][0] = 'X';
        }else {
            s[i + 1][1] = s[i + 2][1] = 'X';
        }
    }

    rep(i, 0, n) {
        // for(char &c : s[i]) if(c != '.') c = 'X';
        cout << s[i] << '\n';
    }
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