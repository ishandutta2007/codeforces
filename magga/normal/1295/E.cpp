#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
const long long int MAX = 300000;
long long int t[2*MAX]{0};
int h = sizeof(int) * 8 - __builtin_clz(MAX);
long long int d[MAX]{0};  
void apply(int p,long long int value) {
    t[p] += value;
    if (p < n) d[p] += value;
}
void build(int p) {
    while (p > 1) p >>= 1, t[p] = min(t[p<<1], t[p<<1|1]) + d[p];
}
void buil(){
    for (int i = n - 1; i > 0; --i) t[i] = min(t[i<<1],t[i<<1|1]);
}
void push(int p) {
    for (int s = h; s > 0; --s) {
        int i = p >> s;
        if (d[i] != 0) {
            apply(i<<1, d[i]);
            apply(i<<1|1, d[i]);
            d[i] = 0;
        }
    }
}
void inc(int l, int r,long long int value) {
    l += n, r += n;
    int l0 = l, r0 = r;
    for (; l < r; l >>= 1, r >>= 1) {
        if (l&1) apply(l++, value);
        if (r&1) apply(--r, value);
    }
    build(l0);
    build(r0 - 1);
}

long long int query(int l, int r) {
    l += n, r += n;
    push(l);
    push(r - 1);
    long long int res = 1e15;
    for (; l < r; l >>= 1, r >>= 1) {
        if (l&1) res = min(res, t[l++]);
        if (r&1) res = min(t[--r], res);
    }
    return res;
}
void pre(){}
void solve(){
    cin>>n;
    int arr[n];ll cost[n];int ind[n+1];
    for(int i=0;i<n;i++){cin>>arr[i];ind[arr[i]]=i;}
    for(int i=0;i<n;i++) cin>>cost[i];
    for(int i=0;i<n;i++){
        t[n+i]=t[n+i-1]+cost[i];
    }
    buil();
    long long int ans = min(cost[0],cost[n-1]);
    for(int i=1;i<=n;i++){
        inc(0,ind[i],cost[ind[i]]);
        inc(ind[i],n,-1*cost[ind[i]]);
        //cout<<query(0,n-1)<<"\n";
        ans=min(ans,query(0,n-1));
    }
    cout<<ans<<"\n";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    pre();
    long long int num = 1;
    //cin>>num;
    for(long long int i=0;i<num;i++){
       	solve();
    }   
}