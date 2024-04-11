
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

const int N = 1e5 + 5, M = 1e6 + 5;
int n, m;
int y[N], lx[N], rx[N], x[N], ly[N], ry[N];
int bit[M];

int getSum(int k) {
    int s = 0;
    while(k >= 1) {
        s += bit[k];
        k -= k & -k;
    }
    return s;
}
void add(int k, int x) {
    while(k < M) {
        bit[k] += x;
        k += k & -k;
    }
}

#define ENTER 0
#define VERT 1
#define EXIT 2

struct event {
    int idx;
    bool horz;
    ll x;
    int ty;
    bool operator<(const event &e) const {
        return make_tuple(x, ty, idx) < make_tuple(e.x, e.ty, e.idx);
    }
};

// V - E + F = 2
// how many vertices?
// how many edges?

pair<ll, ll> solve() {
    fill(bit, bit + M, 0);
    vector<event> ve;
    rep(i, 0, n) {
        ve.push_back({i, true, lx[i], ENTER});
        ve.push_back({i, true, rx[i], EXIT});
    }
    rep(i, 0, m) {
        ve.push_back({i, false, x[i], VERT});
    }
    sort(all(ve));
    ll V = 0, E = 0;
    for(event &e : ve) {
        if(e.horz) {
            add(y[e.idx], e.x == lx[e.idx] ? 1 : -1);
        }else {
            int sum = getSum(ry[e.idx]) - getSum(ly[e.idx] - 1);
            V += sum;
            E += sum - 1;
        }
    }
    // cout << V << ' ' << E << endl;
    return make_pair(V, E);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    n += 2;
    m += 2;
    y[0] = 1; lx[0] = 1; rx[0] = 1e6 + 1;
    y[1] = 1e6 + 1; lx[1] = 1; rx[1] = 1e6 + 1;
    x[0] = 1; ly[0] = 1; ry[0] = 1e6 + 1;
    x[1] = 1e6 + 1; ly[1] = 1; ry[1] = 1e6 + 1;
    rep(i, 2, n) {
        cin >> y[i] >> lx[i] >> rx[i];
        y[i]++; lx[i]++; rx[i]++;
    }
    rep(i, 2, m) {
        cin >> x[i] >> ly[i] >> ry[i];
        x[i]++; ly[i]++; ry[i]++;
    }
    
    ll V = 0, E = 0;
    tie(V, E) = solve();
    rep(i, 0, max(n, m)) {
        swap(y[i], x[i]);
        swap(lx[i], ly[i]);
        swap(rx[i], ry[i]);
    }
    swap(n, m);
    E += solve().second;
    cout << 1 - V + E << '\n';
}