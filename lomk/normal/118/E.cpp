/*input
6 8
1 2
2 3
1 3
4 5
4 6
5 6
2 4
3 5

*/
#include <bits/stdc++.h>
using namespace std;
#define sp ' '
#define endl '\n'
#define fi first
#define se second
#define mp make_pair
#define __builtin_popcount __builtin_popcountll
#define int long long
#define bit(x,y) ((x>>y)&1LL)
#define loop(i,l,r) for(int i=(int)l; i<=(int)r; i++)
#define rloop(i,l,r) for(int i=(int)l; i>=(int)r; i--)
const int N = 100005;
template <class T1, class T2>
ostream &operator<<(ostream &os, const pair<T1, T2> &a) {
    return os << '(' << a.first << ", " << a.second << ')';
}
template <class T>
ostream &operator<<(ostream &os, const vector<T> &a) {
    os << '[';
    for (unsigned int i = 0; i < a.size(); i++)
        os << a[i] << (i < a.size() - 1 ? ", " : "");
    os << ']';
    return os;
}

// call solve(), vertext starts from 1
// result is in arti and bridge
int n, m;
vector<vector<int> > a(N);
struct UndirectedDfs {
    vector<int> num, low;
    vector<bool> arti; int Time;
    vector<pair<int, int> > bridge;
    UndirectedDfs(): num(n + 5, 0LL), low(n + 5, 0LL), arti(n + 5, 0), Time(0) {
        bridge.clear();
    }
private:
    void dfs(int u, int p) {
        num[u] = low[u] = ++Time;
        int child = 0;
        for (auto v : a[u]) {
            if (v == p)
                continue;
            if (!num[v]) {
                dfs(v, u);
                child++;
                low[u] = min(low[u], low[v]);
                if (low[v] >= num[v])
                    bridge.push_back(mp(u, v));
                if (u == p) {
                    if (child >= 2)
                        arti[u] = true;
                }
                else {
                    if (low[v] >= num[u])
                        arti[u] = true;
                }
            }
            else
                low[u] = min(low[u], num[v]);
        }
    }
public:
    void solve() {
        loop(i, 1, n) {
            if (!num[i]) dfs(i, i);
        }
    }
};
bool visited[N];
map<pair<int, int>, bool> mark;

void dfs(int u, int p) {
    visited[u] = true;
    for (auto v : a[u]) {
        if (v == p) continue;
        if (mark.find(mp(u, v)) == mark.end() && mark.find(mp(v, u)) == mark.end())
            mark[mp(u, v)] = true;
        if (!visited[v])
            dfs(v, u);
    }
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    vector<pair<int, int> > inp;
    loop(i, 1, m) {
        int u, v;
        cin >> u >> v; a[u].push_back(v); a[v].push_back(u);
        inp.push_back(mp(u, v));
    }
    UndirectedDfs Tree;
    Tree.solve();
    if (Tree.bridge.size() > 0) {
        cout << 0 << endl;
        return 0;
    }
    dfs(1, 1);
    for (auto it : inp) {
        if (mark.find(it) == mark.end()) cout << it.se << sp << it.fi << endl;
        else cout << it.fi << sp << it.se << endl;
    }
}