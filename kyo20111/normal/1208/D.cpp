#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mid ((l+r)>>1)
int n,ans[200200];
ll a[200200],tree[800800],lazy[800800];
void build(int node, int l, int r){
    if(l == r){
        tree[node] = a[l];
        return;
    }
    build(node*2, l, mid);
    build(node*2+1, mid+1, r);
    tree[node] = min(tree[node*2], tree[node*2+1]);
}
void lazy_update(int node, int l, int r){
    tree[node] = max(0ll, tree[node] + lazy[node]);

    if(l != r){
        lazy[node*2] += lazy[node];
        lazy[node*2+1] += lazy[node];
    }

    lazy[node] = 0;
}
int find(int node, int l, int r){
    lazy_update(node, l, r);
    if(l == r) return l;
    
    lazy_update(node*2, l, mid);
    lazy_update(node*2+1, mid+1, r);

    if(tree[node*2+1] == 0) return find(node*2+1, mid+1, r);
    return find(node*2, l, mid);
}
void up(int node, int l, int r, int nl, int nr, ll v){
    lazy_update(node, l, r);
    if(r<nl || nr<l) return;
    if(nl<=l && r<=nr){
        lazy[node] += v;
        lazy_update(node, l, r);
        return;
    }
    up(node*2, l, mid, nl, nr, v);
    up(node*2+1, mid+1, r, nl, nr, v);
    tree[node] = min(tree[node*2], tree[node*2+1]);
}

int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%lld",a+i);
    build(1, 1, n);
    for(int i=1;i<=n;i++){
        int k = find(1, 1, n);
        ans[k] = i;
        up(1, 1, n, k, k, 1e18);
        if(k<n) up(1, 1, n, k+1, n, -i);
    }
    for(int i=1;i<=n;i++) printf("%d ",ans[i]);
}