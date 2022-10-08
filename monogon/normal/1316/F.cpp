
#pragma GCC optimize ("Ofast")
#include <bits/stdc++.h>

#define ll long long
using namespace std;

const int N = 3e5 + 5, M = 1e9 + 7;

ll pow2[N], pow2n[N];

struct node {
    pair<int, int> val;
    int cnt = 1;
    int dp1, dp2, dp;
    node *child[2] = {0, 0};
    node(int p, int i): val({p, i}) {
        dp1 = (2 * p) % M;
        dp2 = ((1 + (M/2)) * p) % M;
        dp = 0;
    }
    inline void recalc();
    inline node*&choose(const node *x) {
        return child[x->val > val];
    }
    inline void link(node *x) {
        choose(x) = x;
    }
};
inline int count(const node *x) {
    return x ? x->cnt : 0;
}
inline int getdp1(const node *x) {
    return x ? x->dp1 : 0;
}
inline int getdp2(const node *x) {
    return x ? x->dp2 : 0;
}
inline int getdp(const node *x) {
    return x ? x->dp : 0;
}
void node::recalc() {
    int c0 = count(child[0]) + 1, c1 = count(child[1]);
    cnt = c0 + c1;
    int d = getdp1(child[0]), d2 = getdp2(child[1]);
    dp1 = (d + pow2[c0] * val.first) % M;
    dp2 = (getdp2(child[0]) + pow2n[c0] * val.first + pow2n[c0] * d2) % M;
    dp = (((pow2n[c0 + 1] * val.first) % M) * d + getdp(child[0]) + getdp(child[1])
        + ((pow2n[c0 + 1] * dp1) % M) * d2) % M;
    dp1 = (dp1 + pow2[c0] * getdp1(child[1])) % M;
}

inline void rot(node *g, node *p, node *x) {
    bool b = (x->val < p->val);
    p->child[!b] = x->child[b];
    x->link(p);
    if(g) g->link(x);
}
inline node* splay(node *p, node *x) {
    stack<node*> st;
    while(p != x) {
        st.push(p);
        p = p->choose(x);
    }
    while(st.size() >= 2) {
        p = st.top(); st.pop();
        node *g = st.top(); st.pop();
        node *gg = (st.empty() ? 0 : st.top());
        if((g->child[0] == p) == (p->child[0] == x)) {
            rot(gg, g, p);
            rot(gg, p, x);
        }else {
            rot(g, p, x);
            rot(gg, g, x);
        }
        g->recalc();
        p->recalc();
    }
    if(!st.empty()) {
        p = st.top();
        rot(0, p, x);
        p->recalc();
    }
    x->recalc();
    return x;
}
inline node* join(node *x, node *y) {
    if(!x) return y;
    if(!y) return x;
    node *r = x;
    while(r->child[1]) r = r->child[1];
    x = splay(x, r);
    x->link(y); x->recalc();
    return x;
}

inline node* ins(node *r, node *x) {
    if(!r) return x;
    node *p = r, *q = r;
    while((q = p->choose(x))) p = q;
    p->link(x);
    return splay(r, x);
}
inline node* del(node *r, node *x) {
    splay(r, x);
    return join(x->child[0], x->child[1]);
}

int n, q, i, x, p;
node *pnode[N], *root = 0;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    pow2[0] = pow2n[0] = 1;
    pow2[1] = 2, pow2n[1] = 1 + (M / 2);
    for(int i = 2; i < N; i++) {
        pow2[i] = (pow2[i - 1] * pow2[1]) % M;
        pow2n[i] = (pow2n[i - 1] * pow2n[1]) % M;
    }
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> p;
        root = ins(root, pnode[i] = new node(p, i));
    }
    cout << root->dp << '\n';
    cin >> q;
    while(q--) {
        cin >> i >> x;
        root = del(root, pnode[i]);
        *pnode[i] = node(x, i);
        root = ins(root, pnode[i]);
        cout << root->dp << '\n';
    }
}