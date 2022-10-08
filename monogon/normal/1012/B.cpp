
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

const int N = 2e5 + 5;
int n, m, q;
vi adj[2 * N];
int dsu[2 * N];

int trace(int x) {
    return dsu[x] < 0 ? x : dsu[x] = trace(dsu[x]);
}
void join(int x, int y) {
    if((x = trace(x)) == (y = trace(y))) return;
    if(dsu[x] > dsu[y]) swap(x, y);
    dsu[x] += dsu[y];
    dsu[y] = x;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> q;
    fill(dsu + 1, dsu + n + m + 1, -1);
    rep(i, 0, q) {
        int x, y;
        cin >> x >> y;
        join(x, n + y);
    }
    int cnt = 0;
    rep(i, 1, n + m + 1) {
        cnt += (dsu[i] < 0);
    }
    cout << cnt - 1 << '\n';
}