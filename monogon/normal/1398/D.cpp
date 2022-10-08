
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

const int N = 205;
int R, G, B;
ll dp[N][N][N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> R >> G >> B;
    vi r(R), g(G), b(B);
    rep(i, 0, R) cin >> r[i];
    rep(i, 0, G) cin >> g[i];
    rep(i, 0, B) cin >> b[i];
    sort(all(r));
    sort(all(g));
    sort(all(b));
    // numb is dumb
    rep(numr, 0, R + 1) rep(numg, 0, G + 1) rep(numb, 0, B + 1) {
        auto &d = dp[numr][numg][numb];
        if(numr > 0 && numg > 0) {
            d = max(d, r[numr - 1] * g[numg - 1] + dp[numr - 1][numg - 1][numb]);
        }
        if(numr > 0 && numb > 0) {
            d = max(d, r[numr - 1] * b[numb - 1] + dp[numr - 1][numg][numb - 1]);
        }
        if(numg > 0 && numb > 0) {
            d = max(d, g[numg - 1] * b[numb - 1] + dp[numr][numg - 1][numb - 1]);
        }
    }
    cout << dp[R][G][B] << '\n';
}