// why am i so fucking stupid, cant even remember how to write 01-trie

#include <bits/stdc++.h>
using namespace std;
//#define int long long
const int mxN=2e5+5;
int n,cnt,arr[mxN],nxt[2][mxN<<4],idx[mxN<<4],p[mxN];
vector<int> adj[mxN<<4];
int set_of(int u){
    return p[u]==u?u:p[u]=set_of(p[u]);
}
void upd(int x,int v){
    int ptr=0;
    adj[ptr].push_back(x);
    for(int i=30;i>=0;i--){
        int z=(v>>i)&1;
        if(!nxt[z][ptr])nxt[z][ptr]=++cnt;
        ptr=nxt[z][ptr];
        adj[ptr].push_back(x);
    }
    idx[ptr]=x;
}
int qry(int x,int v,int pp){
    if(pp==-1)return idx[x];
    int z=(v>>pp)&1;
    return qry(nxt[z^(!nxt[z][x])][x],v,pp-1);
}
long long eat(int u,int pp){
    if(pp==-1)return 0;
    int lc=nxt[0][u],rc=nxt[1][u];
    if(!lc||!rc)return eat(lc|rc,pp-1);
    int mini=2e9;
    for(auto i:adj[lc])mini=min(mini,arr[i]^arr[qry(rc,arr[i],pp-1)]);
    return mini+eat(lc,pp-1)+eat(rc,pp-1);
}
signed main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
        p[i]=i;
    }
    for(int i=1;i<=n;i++)upd(i,arr[i]);
    cout<<eat(0,30)<<"\n";
}