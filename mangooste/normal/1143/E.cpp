#include <algorithm>
#include <cmath>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <string>
#include <vector>
 
using namespace std;
using ll = long long;
using pii = pair<int, int>;
 
// #define int long long
#define all(a) a.begin(), a.end()
#define pb push_back
#define eb emplace_back
#define mp make_pair

vector<int> tree;

void build(int v, int vl, int vr, vector<int> &a) {
    if (vr - vl == 1) {
        tree[v] = a[vl];
        return;
    }
    int vm = (vl + vr) / 2;
    build(2 * v, vl, vm, a);
    build(2 * v + 1, vm, vr, a);
    tree[v] = min(tree[2 * v], tree[2 * v + 1]);
}

int get(int v, int vl, int vr, int L, int R) {
    if (R <= vl || vr <= L)
        return 1e9;
    if (L <= vl && vr <= R)
        return tree[v];
    int vm = (vl + vr) / 2;
    return min(get(2 * v, vl, vm, L, R), get(2 * v + 1, vm, vr, L, R));
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int n, m, q;
    cin >> n >> m >> q;
    vector<int> p(n), a(m);
    for (auto &el : p)
        cin >> el, el--;
    for (auto &el : a)
        cin >> el, el--;
    // cerr << "p = ";
    // for (auto el : p)
    //     cerr << el << ' ';
    // cerr << endl;
    // cerr << "a = ";
    // for (auto el : a)
    //     cerr << el << ' ';
    // cerr << endl;
    vector<int> where(n);
    for (int i = 0; i < n; i++)
        where[p[i]] = i;
    vector<int> to(m, -1);
    vector<int> ind(n, -1);
    for (int i = m - 1; i >= 0; i--) {
        int need;
        if (a[i] == p[n - 1])
            need = p[0];
        else
            need = p[where[a[i]] + 1];
        // cerr << "i = " << i << ' ' << "need = " << need << endl;
        to[i] = ind[need];
        ind[a[i]] = i;
    }
    // cerr << "to = ";
    // for (auto el : to)
    //     cout << el << ' ';
    // cerr << endl;
    // cerr << "kek" << endl;
    const int Log = 19;
    vector<vector<int>> jump(m, vector<int>(Log, -1));
    for (int i = 0; i < m; i++)
        if (to[i] != -1)
            jump[i][0] = to[i];
    for (int level = 1; level < Log; level++)
        for (int i = 0; i < m; i++) {
            if (jump[i][level - 1] == -1)
                continue;
            jump[i][level] = jump[jump[i][level - 1]][level - 1];
        }
    vector<int> mn(m);

    const int INF = 1e9;
    auto LA = [&](int v, int len) {
        for (int i = 0; i < Log; i++)
            if (len & (1 << i)) {
                if (jump[v][i] == -1)
                    return INF;
                v = jump[v][i];
            }
        return v;
    };

    // cerr << "kek" << endl;
    for (int i = 0; i < m; i++)
        mn[i] = LA(i, n - 1);
    // cerr << "mn = ";
    // for (auto el : mn)
    //     cerr << el << ' ';
    // cerr << endl;
    tree.resize(4 * m);
    build(1, 0, m, mn);
    while (q--) {
        int L, R;
        cin >> L >> R, L--;
        if (R - L < n) {
            cout << 0;
            continue;
        }
        int cur_mn = get(1, 0, m, L, R);
        if (cur_mn < R)
            cout << 1;
        else
            cout << 0;
    }
    cout << '\n';
}