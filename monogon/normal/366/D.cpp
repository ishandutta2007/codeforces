
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

// for fixed L, consider only edges with l_k <= L
// what's the first R so that we cannot reach n?
// consider all edges with l_k <= L. Add edges in decreasing order of R
// find when 1 and n are first in the same component (possibly, never)

const int N = 1e3 + 5, M = 3e3 + 5;
int n, m, a[M], b[M], l[M], r[M];
vector<pii> edge;
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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    rep(i, 0, m) {
        cin >> a[i] >> b[i] >> l[i] >> r[i];
        edge.emplace_back(r[i], i);
    }
    sort(edge.rbegin(), edge.rend());
    int ans = 0;
    rep(j, 0, m) {
        int L = l[j];
        fill(dsu + 1, dsu + n + 1, -1);
        for(auto &p : edge) {
            int i = p.second;
            if(l[i] > L) continue;
            join(a[i], b[i]);
            if(trace(1) == trace(n)) {
                ans = max(ans, r[i] - L + 1);
                break;
            }
        }
    }
    if(ans == 0) {
        cout << "Nice work, Dima!\n";
    }else {
        cout << ans << "\n";
    }
}