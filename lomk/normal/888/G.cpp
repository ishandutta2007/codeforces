/*input
4
1 2 3 4
*/
#include <bits/stdc++.h>
using namespace std;
#define sp ' '
#define endl '\n'
#define fi first
#define se second
#define bit(x,y) ((x>>y)&1)
#define loop(i,l,r) for(int i=(int)l; i<=(int)r; i++)
#define rloop(i,l,r) for(int i=(int)l; i>=(int)r; i--)
#ifdef UncleGrandpa
#include <prettyprint.hpp>
void print() {cout << endl;} template<typename T, typename... Ts> void print(const T& value, const Ts&... values) {cout << value << ' ', print(values...);}
void debug() {cerr << endl;} template<typename T, typename... Ts> void debug(const T& value, const Ts&... values) {cerr << value << ' ', debug(values...);}
#endif
// const int N =;

struct Node {
    Node *child[2];
    int cnt; bool leaf;
    Node(): cnt(0), leaf(false) {child[0] = child[1] = NULL;};
};

struct Trie {
    Node *root;
    Trie() {
        root = new Node();
    }
    void modify(int num, int diff) {
        Node *u = root;
        rloop(i, 30, 0) {
            int c = bit(num, i);
            if (u->child[c] == NULL) u->child[c] = new Node();
            u->child[c]->cnt += diff;
            u = u->child[c];
        }
        u->leaf = true;
    }
    int find(int num) {
        Node *u = root; int ret = 0;
        rloop(i, 30, 0) {
            int c = bit(num, i);
            if (u->child[c] == NULL || u->child[c]->cnt == 0) u = u->child[c ^ 1], ret ^= ((c ^ 1) << i);
            else u = u->child[c], ret ^= (c << i);
        }
        return ret;
    }
} trie;

struct dsu {
    vector<int> par, sz;
    dsu() {};
    dsu(int n): par(n, 0), sz(n, 1) {
        iota(par.begin(), par.end(), 0);
    }
    int find(int x) {
        return par[x] = (par[x] == x ? x : find(par[x]));
    }
    void uni(int x, int y) {
        x = find(x); y = find(y);
        if (x != y) {
            if (sz[x] > sz[y]) swap(x, y);
            sz[y] += sz[x]; sz[x] = 0;
            par[x] = y;
        }
    }
} d;

class MyMap {
    int keys[524288], values[524288];
    int mask;
    int hashSeed = 947546573;
public:
    MyMap(int capacity) {
        int length = 4 * capacity;
        if ((length & (length - 1)) != 0)
            length = (1LL << (63 - __builtin_clzll(length)));
        mask = length - 1;
    }
    int get(long long key) {
        int keyHash = (int)key ^ (int)(key >> 32);
        int pos = keyHash ^ hashSeed;
        pos ^= (pos >> 20) ^ (pos >> 21);
        pos &= mask;
        int step = pos;
        step ^= (step >> 14) ^ (step >> 28);
        step = ((step << 1) | 1) & mask;
        for (; keys[pos] != 0; pos = (pos + step) & mask)
            if (keys[pos] == key) return values[pos];
        keys[pos] = key;
        return values[pos];
    }
    void set(long long key, int val) {
        int keyHash = (int)key ^ (int)(key >> 32);
        int pos = keyHash ^ hashSeed;
        pos ^= (pos >> 20) ^ (pos >> 21);
        pos &= mask;
        int step = pos;
        step ^= (step >> 14) ^ (step >> 28);
        step = ((step << 1) | 1) & mask;
        for (; keys[pos] != 0; pos = (pos + step) & mask)
            if (keys[pos] == key) {
                values[pos] = val;
                return;
            }
        keys[pos] = key;
        values[pos] = val;
    }
};

const int INF = numeric_limits<int>::max();
signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
#ifdef in1code
    freopen("1test.inp", "r", stdin);
#endif
    int n;
    vector<int> a;
    cin >> n;
    loop(i, 1, n) {
        int t; cin >> t; a.push_back(t);
    }
    // cout << 1.0 * clock() / CLOCKS_PER_SEC << endl;
    sort(a.begin(), a.end()); a.resize(distance(a.begin(), unique(a.begin(), a.end())));
    vector<vector<int> > cc;
    for (auto it : a) cc.push_back(vector<int> {it});
    for (auto it : a) trie.modify(it, 1);
    long long ans = 0;
    MyMap where(n);
    while (cc.size() > 1) {
        n = cc.size(); d = dsu(n);
        loop(i, 0, n - 1) for (auto it : cc[i]) where.set(it, i);
        loop(i, 0, n - 1) {
            auto &vec = cc[i];
            for (auto it : vec) trie.modify(it, -1);
            pair<int, int> mn = {INF, 0}; // {val,where}
            for (auto it : vec) {
                auto rec = trie.find(it);
                mn = min(mn, {(it ^ rec), rec});
            }
            for (auto it : vec) trie.modify(it, 1);
            mn.se = where.get(mn.se);
            if (d.find(i) != d.find(mn.se)) {
                ans += mn.fi;
                d.uni(i, mn.se);
            }
        }
        vector<vector<int> > cc2(n, vector<int>());
        loop(i, 0, n - 1) {
            int nxt = d.find(i);
            for (auto it : cc[i]) cc2[nxt].push_back(it);
        }
        cc.clear();
        for (auto &it : cc2) {
            if (it.size()) cc.push_back(it);
        }
    }
    cout << ans << endl;
    // cout << 1.0 * clock() / CLOCKS_PER_SEC << endl;
}