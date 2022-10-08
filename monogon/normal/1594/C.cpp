
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
    int n; char c;
    string s;
    cin >> n >> c >> s;
    s = "$" + s;
    vi cnt(n + 1, 0);
    bool ok = false;
    rep(i, 1, n + 1) {
        if(s[i] != c) ok = true;
    }
    if(!ok) {
        cout << 0 << '\n';
        return;
    }
    rep(i, 1, n + 1) {
        for(int j = i; j <= n; j += i) {
            cnt[i] += (s[j] != c);
        }
        if(cnt[i] == 0) {
            cout << 1 << '\n';
            cout << i << '\n';
            return;
        }
    }
    cout << 2 << '\n' << n << ' ' << n - 1 << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int te;
    cin >> te;
    while(te--) solve();
}