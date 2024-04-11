/*input
6
1 2
1 3
4 2
5 2
3 6
14
2 4 5 10 2
1 3
1 6
2 1 1 10 20
2 6 6 10 20
1 3
2 3 2 10 0
2 5 2 10 1
1 1
1 2
1 3
1 4
1 5
1 6


*/
#include <bits/stdc++.h>
using namespace std;
#define sp ' '
#define endl '\n'
#define fi first
#define se second
#define bit(x, y) ((x >> y) & 1)
#define loop(i, l, r) for (int i = (int)l; i <= (int)r; ++i)
#define rloop(i, l, r) for (int i = (int)l; i >= (int)r; --i)
#ifdef UncleGrandpa
#include <prettyprint.hpp>
void print() {cout << endl;} template<typename T, typename... Ts> void print(const T& value, const Ts&... values) {cout << value << ' ', print(values...);}
#endif
const int N = 2e5+105;

// each node d+1 length array

class ITrangeSum {
private:
#define mid ((l+r)/2)
  int n, f[4 * N], lazy[4 * N];
  void dolazy(int k, int l, int r) {
    if (lazy[k] == 0) return;
    f[k] = (f[k] + 1LL * lazy[k] * (r - l + 1));
    if (l != r) {
      lazy[k * 2] = (lazy[k * 2] + lazy[k]);
      lazy[k * 2 + 1] = (lazy[k * 2 + 1] + lazy[k]);
    }
    lazy[k] = 0;
  }
  void update(int k, int l, int r, int L, int R, int val) {
    dolazy(k, l, r);
    if (r < L || R < l) return;
    if (L <= l && r <= R) {
      lazy[k] = (lazy[k] + val); dolazy(k, l, r);
      return;
    }
    update(k * 2, l, mid, L, R, val); update(k * 2 + 1, mid + 1, r, L, R, val);
    f[k] = (f[k * 2] + f[k * 2 + 1]);
  }
  int get(int k, int l, int r, int L, int R) {
    dolazy(k, l, r);
    if (r < L || R < l) return 0;
    if (L <= l && r <= R) return f[k];
    return (get(k * 2, l, mid, L, R) + get(k * 2 + 1, mid + 1, r, L, R));
  }
  void init(int k, int l, int r) {
    f[k] = lazy[k] = 0; if (l == r)return;
    init(k * 2, l, mid); init(k * 2 + 1, mid + 1, r);
  }
public:
  ITrangeSum(){};
  void init(int _n) {n = _n; init(1, 0, n + 1);}
  int get(int l, int r) {return get(1, 0, n + 1, l, r);};
  void update(int l, int r, int val) {update(1, 0, n + 1, l, r, val);};
#undef mid
} ITx[21];

int n;
vector<vector<int> > a(N);

const int lgx = 20;
int par[lgx][N], depth[N];
bool vis[N];

void pdfs(int u, int p) {
    par[0][u] = p; vis[u] = true;
    for (auto v : a[u]) {
        if (v != p) {
            depth[v] = depth[u] + 1;
            pdfs(v, u);
        }
    }
}

int lca(int p, int q) {
    if (depth[p] < depth[q]) swap(p, q);
    rloop(i, lgx - 1, 0) {
        if (depth[par[i][p]] >= depth[q])
            p = par[i][p];
    }
    if (p == q) return p;
    rloop(i, lgx - 1, 0) {
        if (par[i][p] != par[i][q])
            p = par[i][p], q = par[i][q];
    }
    if (par[0][p] != par[0][q]) throw 1;
    return par[0][p];
}

void makelca() {
    loop(i, 1, n) if (depth[i] == 0) {
        depth[i] = 1;
        pdfs(i, i);
    }
    loop(i, 1, lgx - 1) {
        loop(j, 1, n) {
            par[i][j] = par[i - 1][par[i - 1][j]];
        }
    }
}

struct HLDx {
    int sz[N], in[N], out[N], nxt[N], par[N];
    int Time = 0;
    void dfs_sz(int u, int p) {
        sz[u] = 1; par[u] = p;
        loop(i, 0, (int)a[u].size() - 1) {
            auto v = a[u][i];
            if (v == p) {
                swap(a[u][i], a[u].back());
                a[u].pop_back(); i--;
                continue;
            }
            dfs_sz(v, u);
            sz[u] += sz[v];
            if (sz[v] > sz[a[u][0]])
                swap(a[u][i], a[u][0]);
        }
    }
    void dfs_hld(int u, int p) {
        in[u] = ++Time;
        for (auto v : a[u]) {
            nxt[v] = (v == a[u][0] ? nxt[u] : v);
            dfs_hld(v, u);
        }
        out[u] = Time;
    }
    void update(int u, int p, int val, ITrangeSum &IT) {
        while (true) {
            if (in[u] <= in[p]) break;
            IT.update(max(in[p] + 1, in[nxt[u]]), in[u], val);
            u = nxt[u]; u = par[u];
        }
        IT.update(in[p], in[p], val);
    }
    int query(int u, int p, ITrangeSum &IT) {
        int ret = 0;
        while (true) {
            if (in[u] <= in[p]) break;
            ret+= IT.get(max(in[p] + 1, in[nxt[u]]), in[u]);
            u = nxt[u]; u = par[u];
        }
        ret+= IT.get(in[p], in[p]);
        return ret;
    }
    void init(int root) {
        dfs_sz(root, root);
        nxt[root] = root;
        dfs_hld(root, root);
    }
} HLD;


void query2(int u, int v, int k, int d){
    int p = lca(u,v);
    
    int cnt = 0;
    if (u!=p) HLD.update(u,p,k,ITx[d]),cnt++;
    if (v!=p) HLD.update(v,p,k,ITx[d]),cnt++;
    HLD.update(p,p,k*(-cnt),ITx[d]);   
    // clear value of p
    
    loop(i,0,d){
       HLD.update(p,p,k,ITx[d-i]);
       if (d-i-1>=0) HLD.update(p,p,k,ITx[d-i-1]);
        p = par[0][p];
    }
}

int query1(int u){
  int ret = 0;
  loop(i,0,20){
    ret+=HLD.query(u,u,ITx[i]);
    if (u!=1) u = par[0][u];
  }  
  return ret;
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    const int off = 22;
    cin >> n;
    loop(i,1,n-1){
      int u, v;
      cin >> u >> v;
      u+=off;
      v+=off;
      a[u].push_back(v);
      a[v].push_back(u);
    }
    n+=off;
    loop(i,1,off) {
      a[i].push_back(i+1);
      a[i+1].push_back(i);
    }
    
    HLD.init(1);
    loop(i,0,20) ITx[i].init(n);
    makelca();
    
    int q;
    cin >> q;
    loop(Q,1,q){
      int type;
      cin >> type;
      if (type==1){
        int u; cin >> u; u+=off;
        cout << query1(u) << endl;
      }
      else{
        int u,v,k,d;
        cin >> u >> v >> k >> d;
        u+=off; v+=off;
        query2(u,v,k,d);
      }
    }
}