
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
    int ans = 2;
    if((s.back() - '0') % 2 == 0) {
        ans = 0;
    }else if((s[0] - '0') % 2 == 0) {
        ans = 1;
    }
    bool ok = false;
    int n = s.length();
    rep(i, 0, n) {
        if((s[i] - '0') % 2 == 0) {
            ok = true;
        }
    }
    if(!ok) ans = -1;
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int te;
    cin >> te;
    while(te--) solve();
}