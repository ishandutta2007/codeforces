
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

const int N = 1e5 + 5;
int dsu[N];

int trace(int x) {
    return dsu[x] < 0 ? x : dsu[x] = trace(dsu[x]);
}
void join(int x, int y) {
    if((x = trace(x)) == (y = trace(y))) return;
    if(dsu[x] > dsu[y]) swap(x, y);
    dsu[x] += dsu[y];
    dsu[y] = x;
}

bool lucky(ll k) {
    while(k > 0) {
        int d = k % 10;
        if(d != 4 && d != 7) return false;
        k /= 10;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    fill(dsu + 1, dsu + n + 1, -1);
    rep(i, 0, n - 1) {
        int u, v;
        ll w;
        cin >> u >> v >> w;
        if(!lucky(w)) {
            join(u, v);
        }
    }
    ll ans = 0;
    rep(i, 1, n + 1) {
        if(dsu[i] < 0) {
            int s = -dsu[i];
            ans += 1LL * s * (n - s) * (n - s - 1);
        }
    }
    cout << ans << '\n';
}