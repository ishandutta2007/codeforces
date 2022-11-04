#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define mid ((l+r)/2)
#define lch (node+1)
#define rch (node+2*(mid-l+1))

int n, a[300300], val[600600], t[600600], lz[600600];

int build(int node = 1, int l = 1, int r = n){
    if(l == r) return t[node] = 1;
    return t[node] = build(lch, l, mid) + build(rch, mid+1, r);
}

void lazy_update(int node, int l, int r){
    if(!lz[node]) return;
    val[node] += lz[node];
    if(l != r) lz[lch] += lz[node], lz[rch] += lz[node];
    lz[node] = 0;
}

void update(int nl, int nr, int v, int node = 1, int l = 1, int r = n){
    lazy_update(node, l, r);
    if(nr < l || r < nl) return;
    if(nl <= l && r <= nr){
        lz[node] += v;
        lazy_update(node, l, r);
        return;
    }

    update(nl, nr, v, lch, l, mid), update(nl, nr, v, rch, mid+1, r);
    val[node] = min(val[lch], val[rch]);
    t[node] = (val[node] == val[lch] ? t[lch] : 0) + (val[node] == val[rch] ? t[rch] : 0);
}

int find(int nl, int nr, int node = 1, int l = 1, int r = n){
    lazy_update(node, l, r);
    if(nr < l || r < nl) return 0;
    if(nl <= l && r <= nr) return val[node] == 0 ? t[node] : 0;
    return find(nl, nr, lch, l, mid) + find(nl, nr, rch, mid+1, r);
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for(int i=1;i<=n;i++){
        int x, y; cin >> x >> y;
        a[x] = y;
    }

    build();
    stack<int> mx, mn; mx.push(0), mn.push(0);
    ll ans = 0;

    for(int i=1;i<=n;i++){
        while(mx.top() && a[mx.top()] < a[i]){
            int tmp = mx.top(); mx.pop();
            update(mx.top()+1, tmp, a[i] - a[tmp]);
        }
        mx.push(i);

        while(mn.top() && a[mn.top()] > a[i]){
            int tmp = mn.top(); mn.pop();
            update(mn.top()+1, tmp, a[tmp] - a[i]);
        }
        mn.push(i);

        ans += find(1, i);
        update(1, i, -1);
    }

    cout << ans;
}