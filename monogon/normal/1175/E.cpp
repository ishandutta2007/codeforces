
#include <bits/stdc++.h>

#define ll long long
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
#define vi vector<int>
#define pii pair<int, int>
#define rep(i, a, b) for(int i = (a); i < (b); i++)
using namespace std;
template<typename T>
using minpq = priority_queue<T, vector<T>, greater<T>>;

const int N = 2e5 + 5, X = 5e5 + 5;
int n, m, l[N], r[N], cov[X][20], x, y;
int ins[X], del[X];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    rep(i, 0, n) {
        cin >> l[i] >> r[i];
        ins[l[i]] = max(ins[l[i]], r[i]);
    }
    int mx = 0;
    rep(i, 0, X) {
        mx = max({i, mx, ins[i]});
        cov[i][0] = mx;
    }
    rep(l, 1, 20) {
        rep(i, 0, X) {
            cov[i][l] = cov[cov[i][l - 1]][l - 1];
        }
    }
    while(m--) {
        cin >> x >> y;
        if(cov[x][19] < y) {
            cout << "-1\n";
            continue;
        }
        int ans = 0;
        for(int l = 19; l >= 0; l--) {
            if(cov[x][l] < y) {
                x = cov[x][l];
                ans += (1LL << l);
            }
        }
        cout << ans + 1 << '\n';
    }
}