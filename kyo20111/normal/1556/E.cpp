#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define mid ((l+r)/2)
#define lch (node+1)
#define rch (node+2*(mid-l+1))

struct Node{
    ll v[2][2];
} t[400400], e;

int n, q;
ll a[100100], b[100100], c[100100];

Node merge(Node l, Node r){
    Node re = e;

    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            for(int k=0;k<2;k++){
                ll x = min(l.v[i][j], r.v[!j][k]);
                re.v[i][k] += x;
                l.v[i][j] -= x, r.v[!j][k] -= x;
            }
        }
    }

    for(int i=0;i<2;i++) for(int j=0;j<2;j++) re.v[i][j] += l.v[i][j] + r.v[i][j];
    return re;
}

void build(int node = 1, int l = 1, int r = n){
    if(l == r){
        if(c[l] == 0) return;
        int k = (c[l] > 0 ? 1 : 0);
        t[node].v[k][k] = abs(c[l]);
        return;
    }
    build(lch, l, mid), build(rch, mid+1, r);
    t[node] = merge(t[lch], t[rch]);
}

Node find(int nl, int nr, int node = 1, int l = 1, int r = n){
    if(nr < l || r < nl) return e;
    if(nl <= l && r <= nr) return t[node];
    return merge(find(nl, nr, lch, l, mid), find(nl, nr, rch, mid+1, r));
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    // for(int i=1;i<=400000;i++) t[i].v[0][0] = t[i].v[0][1] = t[i].v[1][0] = t[i].v[0][1] = 0;
    // e.v[0][0] = e.v[0][1] = e.v[1][0] = e.v[0][1] = 0;

    cin >> n >> q;
    for(int i=1;i<=n;i++) cin >> a[i];
    for(int i=1;i<=n;i++) cin >> b[i];
    for(int i=1;i<=n;i++) c[i] = a[i] - b[i];
    build();

    while(q--){
        int l, r; cin >> l >> r;

        Node k = find(l, r);

        if(!k.v[1][0] && !k.v[1][1] && !k.v[0][0]){
            cout << k.v[0][0] + k.v[0][1] << "\n";
        }else{
            cout << "-1\n";
        }
    }
}