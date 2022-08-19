#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const LL MOD = 1000000007;

vector<LL> a;

struct node {
    node *l, *r;
    int lx, rx;
    LL wsum;
    LL wasum; // mod
};

node *build(int lx, int rx){
    node *v = new node();
    v->lx = lx; v->rx = rx;
    v->wsum = v->wasum = 0;
    if(lx == rx){
        v->l = v->r = 0;
    } else {
        v->l = build(lx, (lx+rx)/2);
        v->r = build((lx+rx)/2 + 1, rx);
    }
    return v;
}

void upd(node *v, int pos, LL neww){
    if(v == NULL || v->rx < pos || v->lx > pos) return;
    if(v->lx == pos && v->rx == pos){
        v->wsum = neww;
        v->wasum = (neww * a[pos]) % MOD;
    } else {
        upd(v->l, pos, neww);
        upd(v->r, pos, neww);
        v->wsum = v->l->wsum + v->r->wsum;
        v->wasum = (v->l->wasum + v->r->wasum) % MOD;
    }
}

LL wquery(node *v, int lx, int rx){
    if(v->rx < lx || rx < v->lx) return 0;
    if(lx <= v->lx && v->rx <= rx) return v->wsum;
    return wquery(v->l, lx, rx) + wquery(v->r, lx, rx);
}

LL waquery(node *v, int lx, int rx){
    if(v->rx < lx || rx < v->lx) return 0;
    if(lx <= v->lx && v->rx <= rx) return v->wasum;
    return waquery(v->l, lx, rx) + waquery(v->r, lx, rx);
}
int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    int n, q;
    cin >> n >> q;
    a.resize(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
        a[i] -= i;
    }

    node * segtree = build(0, n-1);
    vector<LL> w(n);
    for(int i = 0; i < n; i++){
        cin >> w[i];
        upd(segtree, i, w[i]);
    }
    for(int i = 0; i < q; i++){
        int x, y;
        cin >> x >> y;
        if(x < 0){
            int id = -x;
            id--;
            LL nw = y;
            upd(segtree, id, nw);
        } else {
            int l = x;
            int r = y;
            l--; r--;
            LL tw = wquery(segtree, l, r);
            int s = l-1;
            int e = r;
            while(s + 1 < e){
                int m = (s + e) / 2;
                if(wquery(segtree, l, m) * 2 > tw){
                    e = m;
                } else {
                    s = m;
                }
            }
            LL cur_ans = 0;
            cur_ans += a[e] * (wquery(segtree, l, e) % MOD) - waquery(segtree, l, e);
            cur_ans += waquery(segtree, e, r) - a[e] * (wquery(segtree, e, r) % MOD);
            cur_ans %= MOD;
            if(cur_ans < 0) cur_ans += MOD;
            cout << cur_ans << '\n';
        }
    }
}