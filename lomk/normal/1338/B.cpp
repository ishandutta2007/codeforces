/*input
6
1 3
2 3
3 4
4 5
5 6
*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define sp ' '
#define endl '\n'
#define fi first
#define se second
#define bit(x,y) ((x>>y)&1)
#define loop(i,l,r) for(int i=(int)l; i<=(int)r; i++)
#define rloop(i,l,r) for(int i=(int)l; i>=(int)r; i--)
#ifdef UncleGrandpa
#include <prettyprint.hpp>
#define debug(x...) {cout << "[" << #x << "] ="; print(x);}
void print() {cout << endl;}
template<typename T, typename... Ts> void print(const T& value, const Ts&... values) {cout << value << ' ', print(values...);}
#endif
const int N = 1e5 + 5;

int n;
vector<vector<int> > a(N);

int pdfs(int u, int p) {
    if (a[u].size() == 1) return 0;
    int ret = -1;
    for (auto v : a[u]) {
        if (v == p) continue;
        auto rec = pdfs(v, u);
        if (ret == -1) ret = rec;
        else if (rec != ret) throw 1;
    }
    return (ret + 1) % 2;
}

int solveMin(int root) {
    try {
        pdfs(root, root);
    } catch (...) {
        return 3;
    }
    return 1;
}

int dfsCount(int u, int p) {
    int cnt = 0, ret = 0;
    for (auto v : a[u]) {
        if (v == p) continue;
        ret += dfsCount(v, u);
        if (a[v].size() == 1) cnt++;
    }
    if (cnt >= 1)
        ret += cnt - 1;
    return ret;
}

int solveMax(int root) {
    auto rec = dfsCount(root, root);
    return n - 1 - rec;
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n;
    loop(i, 1, n - 1) {
        int u, v; cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    int root = 0;
    loop(i, 1, n) {
        if (a[i].size() >= 2) {
            root = i;
            break;
        }
    }
    cout << solveMin(root) << sp << solveMax(root) << endl;
}