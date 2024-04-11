
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

const int N = 1e5 + 5, M = 1e9 + 7;
int n, x[N], y[N], dsu[2 * N];
bool flag[2 * N];
ll pow2[2 * N];
map<int, vi> row, col;

int trace(int x) {
    return dsu[x] < 0 ? x : dsu[x] = trace(dsu[x]);
}
void join(int x, int y) {
    if((x = trace(x)) == (y = trace(y))) {
        flag[x] = true;
        return;
    }
    if(dsu[x] > dsu[y]) swap(x, y);
    dsu[x] += dsu[y];
    dsu[y] = x;
    flag[x] |= flag[y];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    vi vx, vy;
    pow2[0] = 1;
    rep(i, 1, 2 * N) {
        pow2[i] = 2 * pow2[i - 1];
        if(pow2[i] >= M) pow2[i] -= M;
    }
    rep(i, 0, n) {
        cin >> x[i] >> y[i];
        row[x[i]].push_back(i);
        col[y[i]].push_back(i);
        vx.push_back(x[i]);
        vy.push_back(y[i]);
    }
    sort(all(vx));
    sort(all(vy));
    vx.erase(unique(all(vx)), vx.end());
    vy.erase(unique(all(vy)), vy.end());
    int r = sz(row);
    int c = sz(col);
    assert(r == sz(vx));
    assert(c == sz(vy));
    fill(dsu, dsu + r + c, -1);
    rep(i, 0, n) {
        int ix = lower_bound(all(vx), x[i]) - vx.begin();
        int iy = lower_bound(all(vy), y[i]) - vy.begin();
        join(ix, r + iy);
    }
    ll ans = 1;
    rep(i, 0, r + c) {
        if(dsu[i] < 0) {
            ll mul = pow2[-dsu[i]];
            if(!flag[i]) mul--;
            ans = (ans * mul) % M;
        }
    }
    cout << ans << '\n';
}