
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
    string s;
    cin >> s;
    int n = s.length();
    int ans = 0;
    rep(i, 0, n) {
        if(i > 0 && s[i] == s[i - 1]) {
            ans++;
            s[i] = '?';
        }
        if(s[i] != '?' && i > 1 && s[i] == s[i - 2]) {
            ans++;
            s[i] = '?';
        }
    }
    // cout << s << endl;
    cout << ans << '\n';
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