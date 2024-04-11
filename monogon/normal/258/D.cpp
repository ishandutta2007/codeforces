
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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vi p(n + 1);
    rep(i, 1, n + 1) cin >> p[i];
    vector<vector<ftype>> prob(n + 1, vector<ftype>(n + 1, 0.0));
    rep(i, 1, n + 1) rep(j, i + 1, n + 1) {
        if(p[i] > p[j]) {
            prob[i][j] = 1.0;
        }
    }
    while(m--) {
        int a, b;
        cin >> a >> b;
        if(a > b) swap(a, b);
        prob[a][b] = 0.5;
        rep(i, 1, a) {
            prob[i][a] = prob[i][b] = 0.5 * (prob[i][a] + prob[i][b]);
        }
        rep(i, b + 1, n + 1) {
            prob[a][i] = prob[b][i] = 0.5 * (prob[a][i] + prob[b][i]);
        }
        rep(i, a + 1, b) {
            ftype pa = prob[a][i], pb = prob[i][b];
            prob[a][i] = 0.5 * (pa + 1 - pb);
            prob[i][b] = 0.5 * (pb + 1 - pa);
        }
    }
    ftype ans = 0;
    rep(i, 1, n + 1) rep(j, i + 1, n + 1) {
        ans += prob[i][j];
    }
    cout << fixed << setprecision(8) << ans << '\n';
}