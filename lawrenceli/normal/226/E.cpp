#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second

typedef pair<int, int> pii;

const int MAXN = 100100;
const int MAXLG = 17;

int n, m, root;
vector<int> adj[MAXN];
int par[MAXN], jump[MAXN][MAXLG], sub[MAXN], dep[MAXN];
int head[MAXN], cmp[MAXN], ind[MAXN];
vector<vector<int> > chain, attack;
struct node {
    node *l, *r;
    int sum;
    node * copy() {
        node *ret = new node();
        ret->l = l;
        ret->r = r;
        ret->sum = sum;
        return ret;
    }
};
vector<vector<node*> > tree;

void dfs(int cur) {
    sub[cur] = 1;
    dep[cur] = par[cur] == -1 ? 0 : dep[par[cur]]+1;
    head[cur] = cur;
    for (int i=0; i<adj[cur].size(); i++) {
        int nxt = adj[cur][i];
        dfs(nxt);
        sub[cur] += sub[nxt];
    }
}

void dfs2(int cur) {
    if (head[cur] == cur) {
        cmp[cur] = chain.size();
        ind[cur] = 0;
        chain.push_back(vector<int>());
        chain[cmp[cur]].push_back(cur);
    }
    for (int i=0; i<adj[cur].size(); i++) {
        int nxt = adj[cur][i];
        if (sub[nxt] > sub[cur]/2) {
            head[nxt] = head[cur];
            cmp[nxt] = cmp[cur];
            ind[nxt] = ind[cur]+1;
            chain[cmp[nxt]].push_back(nxt);
        }
        dfs2(nxt);
    }
}

void initlca() {
    for (int i=0; i<n; i++) jump[i][0] = par[i] == -1 ? i : par[i];
    for (int k=1; k<MAXLG; k++)
        for (int i=0; i<n; i++)
            jump[i][k] = jump[jump[i][k-1]][k-1];
}

int lca(int a, int b) {
    if (dep[a] < dep[b]) swap(a, b);
    for (int k=MAXLG-1; k>=0; k--)
        if (dep[jump[a][k]] >= dep[b])
            a = jump[a][k];
    if (a == b) return a;
    for (int k=MAXLG-1; k>=0; k--)
        if (jump[a][k] != jump[b][k])
            a = jump[a][k], b = jump[b][k];
    return par[a];
}

//b is an ancestor of a - returns ancestor of a right below b
int lca2(int a, int b) {
    //assert(a != b);
    for (int k=MAXLG-1; k>=0; k--)
        if (dep[jump[a][k]] > dep[b])
            a = jump[a][k];
    return a;
}

void init(node *cur, int lt, int rt) {
    cur->sum = 0;
    if (lt + 1 != rt) {
        int mid = (lt + rt) / 2;
        cur->l = new node();
        cur->r = new node();
        init(cur->l, lt, mid);
        init(cur->r, mid, rt);
    }
}

void update(node *cur, int lt, int rt, int p) {
    if (lt + 1 == rt) {
        //assert(!cur->sum);
        cur->sum = 1;
    } else {
        int mid = (lt + rt) / 2;
        if (p < mid) {
            node *nxt = cur->l->copy();
            cur->l = nxt;
            update(nxt, lt, mid, p);
        } else {
            node *nxt = cur->r->copy();
            cur->r = nxt;
            update(nxt, mid, rt, p);
        }
        cur->sum = cur->l->sum + cur->r->sum;
    }
}

int qcount(node *cur1, node *cur2, int lt, int rt, int ql, int qr) {
    if (rt <= ql || lt >= qr) return 0;
    if (lt >= ql && rt <= qr) return (rt-lt) - (cur2->sum-cur1->sum);
    else {
        int mid = (lt + rt) / 2;
        return qcount(cur1->l, cur2->l, lt, mid, ql, qr)+qcount(cur1->r, cur2->r, mid, rt, ql, qr);
    }
}

int query(node *cur1, node *cur2, int lt, int rt, int ql, int qr, int k) {
    if (lt + 1 == rt) {
        //assert(k == 1);
        return lt;
    } else {
        int mid = (lt + rt) / 2;
        int res = qcount(cur1->l, cur2->l, lt, mid, ql, qr);
        if (k <= res) return query(cur1->l, cur2->l, lt, mid, ql, qr, k);
        else return query(cur1->r, cur2->r, mid, rt, ql, qr, k-res);
    }
}

int tcount(int cur, int nd, int y) {
    int ret = 0;
    while (cur >= 0) {
        if (cmp[cur] != cmp[nd]) {
            if (ind[cur]+1 == chain[cmp[cur]].size()) ret += chain[cmp[cur]].size()-(attack[cmp[cur]].end()-lower_bound(attack[cmp[cur]].begin(), attack[cmp[cur]].end(), y));
            else {
                int a = lower_bound(attack[cmp[cur]].begin(), attack[cmp[cur]].end(), y)-attack[cmp[cur]].begin()-1;
                ret += qcount(tree[cmp[cur]][a], tree[cmp[cur]].back(), 0, chain[cmp[cur]].size(), 0, ind[cur]+1);
            }
            cur = par[head[cur]];
        } else {
            int a = lower_bound(attack[cmp[cur]].begin(), attack[cmp[cur]].end(), y)-attack[cmp[cur]].begin()-1;
            //cout << a << ' ' << attack[cmp[cur]].size() << endl;
            ret += qcount(tree[cmp[cur]][a], tree[cmp[cur]].back(), 0, chain[cmp[cur]].size(), ind[nd], ind[cur]+1);
            break;
        }
    }
    return ret;
}

int getk(int cur, int nd, int y, int k) {
    while (cur >= 0) {
        if (cmp[cur] != cmp[nd]) {
            int res;
            if (ind[cur]+1 == chain[cmp[cur]].size()) res = chain[cmp[cur]].size()-(attack[cmp[cur]].end()-lower_bound(attack[cmp[cur]].begin(), attack[cmp[cur]].end(), y));
            else {
                int a = lower_bound(attack[cmp[cur]].begin(), attack[cmp[cur]].end(), y)-attack[cmp[cur]].begin()-1;
                res = qcount(tree[cmp[cur]][a], tree[cmp[cur]].back(), 0, chain[cmp[cur]].size(), 0, ind[cur]+1);
            }
            if (res >= k) {
                int a = lower_bound(attack[cmp[cur]].begin(), attack[cmp[cur]].end(), y)-attack[cmp[cur]].begin()-1;
                int ans = query(tree[cmp[cur]][a], tree[cmp[cur]].back(), 0, chain[cmp[cur]].size(), 0, ind[cur]+1, res-k+1);
                return chain[cmp[cur]][ans];
            } else k -= res;
            cur = par[head[cur]];
        } else {
            int a = lower_bound(attack[cmp[cur]].begin(), attack[cmp[cur]].end(), y)-attack[cmp[cur]].begin()-1;
            int res = qcount(tree[cmp[cur]][a], tree[cmp[cur]].back(), 0, chain[cmp[cur]].size(), ind[nd], ind[cur]+1);
            //assert(res >= k);
            int ans = query(tree[cmp[cur]][a], tree[cmp[cur]].back(), 0, chain[cmp[cur]].size(), ind[nd], ind[cur]+1, res-k+1);
            return chain[cmp[cur]][ans];
        }
    }
    //assert(0);
}

int main() {
    if (fopen("input.txt", "r")) {
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    }

    scanf("%d", &n);
    for (int i=0; i<n; i++) {
        scanf("%d", &par[i]);
        par[i]--;
        if (par[i] == -1) root = i;
        else adj[par[i]].push_back(i);
    }

    dfs(root);
    dfs2(root);
    initlca();

    attack.resize(chain.size(), vector<int>());
    tree.resize(chain.size(), vector<node*>());
    for (int i=0; i<chain.size(); i++) {
        attack[i].push_back(-1);
        tree[i].push_back(new node());
        init(tree[i][0], 0, chain[i].size());
    }

    scanf("%d", &m);
    for (int i=0; i<m; i++) {
        int t; scanf("%d", &t);
        if (t == 1) {
            int c; scanf("%d", &c);
            c--;
            attack[cmp[c]].push_back(i);
            tree[cmp[c]].push_back(tree[cmp[c]].back()->copy());
            update(tree[cmp[c]].back(), 0, chain[cmp[c]].size(), ind[c]);
        } else {
            int a, b, k, y;
            scanf("%d %d %d %d", &a, &b, &k, &y);
            a--, b--;
            if (a == par[b] || b == par[a]) {
                printf("-1\n");
                continue;
            }
            int l = lca(a, b);
            if (a == l) {
                int l2 = lca2(b, l);
                b = par[b];
                int x = tcount(b, l2, y);
                if (x < k) printf("-1\n");
                else printf("%d\n", getk(b, l2, y, x-k+1)+1);
            } else {
                a = par[a];
                if (b == l) {
                    int l2 = lca2(a, l);
                    int x = tcount(a, l2, y);
                    if (x < k) printf("-1\n");
                    else printf("%d\n", getk(a, l2, y, k)+1);
                } else {
                    int x = tcount(a, l, y);
                    if (x >= k) printf("%d\n", getk(a, l, y, k)+1);
                    else {
                        k -= x;
                        int l2 = lca2(b, l);
                        if (b == l2) printf("-1\n");
                        else {
                            b = par[b];
                            x = tcount(b, l2, y);
                            if (x < k) printf("-1\n");
                            else printf("%d\n", getk(b, l2, y, x-k+1)+1);
                        }
                    }
                }
            }
        }
    }
    return 0;
}