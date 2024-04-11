
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

const int N = 2005;
int n;
ll a[N][N];
map<int, ll> ma1, ma2;
ll ans[2] = {-1, -1};
pii pos[2] = {{0, 0}, {0, 0}};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    rep(i, 0, n) rep(j, 0, n) {
        cin >> a[i][j];
        ma1[i - j] += a[i][j];
        ma2[i + j] += a[i][j];
    }
    rep(i, 0, n) rep(j, 0, n) {
        int b = (i + j) % 2;
        ll val = ma1[i - j] + ma2[i + j] - a[i][j];
        if(val > ans[b]) {
            ans[b] = val;
            pos[b] = {i + 1, j + 1};
        }
    }
    cout << ans[0] + ans[1] << '\n' << pos[0].fi << ' ' << pos[0].se << ' ' << pos[1].fi << ' ' << pos[1].se << endl;
}