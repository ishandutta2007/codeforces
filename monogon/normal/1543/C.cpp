
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

using ftype = long double;

const ftype EPS = 1e-10;

ftype solve(ftype a, ftype b, ftype c, ftype v) {
    ftype ans = c;
    if(a > EPS) {
        ftype d = min(a, v);
        if(b < EPS) ans += a * (1 + solve(a - d, 0, c + d, v));
        else ans += a * (1 + solve(a - d, b + d / 2, c + d / 2, v));
    }
    if(b > EPS) {
        ftype d = min(b, v);
        if(a < EPS) ans += b * (1 + solve(0, b - d, c + d, v));
        else ans += b * (1 + solve(a + d / 2, b - d, c + d / 2, v));
    }
    return ans;
}

void solve() {
    ftype a, b, c, v;
    cin >> a >> b >> c >> v;
    cout << solve(a, b, c, v) << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(8);
    int te;
    cin >> te;
    while(te--) solve();
}