
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
    vi p(n);
    rep(i, 0, n) cin >> p[i];
    bool ok = true;
    rep(i, 0, n) if(p[i] != i + 1) ok = false;
    int ans = 0;
    if(ok) {
        ans = 0;
    }else {
        if(p[0] == 1 || p[n - 1] == n) ans = 1;
        else if(p[0] == n && p[n - 1] == 1) ans = 3;
        else ans = 2;
    }
    cout << ans << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int te;
    cin >> te;
    while(te--) solve();
}