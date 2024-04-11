#include<bits/stdc++.h>
using namespace std;
void pre(){}
typedef long long ll;
int n;
const long long int MAX = 400000;
int t[2*MAX];
int woo[2*MAX];
int h = sizeof(int) * 8 - __builtin_clz(MAX);
int d[MAX];  
void apply(int p, int value) {
    t[p] += value;
    if (p < n) d[p] += value;
}
void build(int p) {
    while (p > 1) p >>= 1, t[p] = max(t[p<<1], t[p<<1|1]) + d[p];
}
void buil() { 
  for (int i = n - 1; i > 0; --i) t[i] = max(t[i<<1],t[i<<1|1]);
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
void inc(int l, int r, int value) {
    l += n, r += n;
    int l0 = l, r0 = r;
    for (; l < r; l >>= 1, r >>= 1) {
        if (l&1) apply(l++, value);
        if (r&1) apply(--r, value);
    }
    build(l0);
    build(r0 - 1);
}
int mi[200001];
int ma[200001]{0};
int val[200001];
vector<int>arr[200001];
int query(int l, int r) {
    l += n, r += n;
    push(l);
    push(r - 1);
    int res = -2e9;
    for (; l < r; l >>= 1, r >>= 1) {
        if (l&1) res = max(res, t[l++]);
        if (r&1) res = max(t[--r], res);
    }
    return res;
}
int j = 0;
void dfs(int to,int from){
    t[n+j]=0;
    mi[to]=j;
    woo[j]=val[to];
    //cout<<to<<" ";
    ma[to]=max(ma[to],j);
    j++;
    for(auto i:arr[to]){
        if(i!=from){
            dfs(i,to);
            t[n+j]=0;
            woo[j]=val[to];
            //cout<<to<<" ";
            ma[to]=max(ma[to],j);
            j++;
        }
    }
}
void solve(){
    int N,q,u,v;cin>>N>>q;
    n=2*N-1;
    for(int i=1;i<=N;i++) cin>>val[i];
    for(int i=0;i<N -1;i++){
        cin>>u>>v;
        arr[v].push_back(u);
        arr[u].push_back(v);
    }
    dfs(1,0);
    //cout<<"\n";
    buil();
    for(int i=0;i<q;i++){
        cin>>u;
        if(u==2){
            cin>>u;
            int wee;
            if(mi[u]%2==0){
                wee=query(mi[u],mi[u]+1);
            }else{
                wee=query(mi[u],mi[u]+1)*-1;
            }
            cout<<wee+woo[mi[u]]<<"\n";
        }else{
            cin>>u>>v;
            if(mi[u]%2==0){
                inc(mi[u],ma[u]+1,v);
            }else{
                inc(mi[u],ma[u]+1,-1*v);
            }
        }
    }
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