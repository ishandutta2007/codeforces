#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_pbds;
#define int long long
#define double long double
#define ff first
#define ss second
#define pii pair<int,int>
#define pb push_back
#define all(v) v.begin(),v.end()
#define rofl exit(1);
#define debug(x) cerr<<(#x)<<"::"<<(x)<<"\n";
template<typename T> using OST=tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
const int mod=1e9+7,mod2=998244353,inf=1e18;
void yes(){cout<<"YES\n";}
void no(){cout<<"NO\n";}
int bm(int b,int p,int m=mod){
    int ans=1;
    b%=m;
    while(p){
        if(p&1)(ans*=b)%=m;
        (b*=b)%=m;
        p>>=1;
    }
    return ans;
}
const int mxN=2e6+5;
int go[mxN],segtree[mxN<<2];
void build(int idx,int l,int r){
    if(l==r){
        segtree[idx]=go[l];
        return;
    }
    int mid=(l+r)>>1;
    build(idx<<1,l,mid);
    build(idx<<1|1,mid+1,r);
    segtree[idx]=max(segtree[idx<<1],segtree[idx<<1|1]);
}
int qry(int idx,int l,int r,int x,int y){
    if(l>y||r<x)return -1e18;
    if(x<=l&&r<=y)return segtree[idx];
    int mid=(l+r)>>1;
    return max(qry(idx<<1,l,mid,x,y),qry(idx<<1|1,mid+1,r,x,y));
}
void eat(){
    int n,m;
    cin>>n>>m;
    int arr[n+1][m+1],f[n+1][m+1],g[n+1][m+1];
    memset(arr,0,sizeof arr);
    memset(f,0,sizeof f);
    memset(g,0,sizeof g);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            char ch;
            cin>>ch;
            arr[i][j]=(ch=='.');
            f[i][j]=i;
            g[i][j]=j;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(arr[i-1][j]){
                f[i][j]=min(f[i][j],f[i-1][j]);
                g[i][j]=min(g[i][j],g[i-1][j]);
            }
            if(arr[i][j-1]){
                f[i][j]=min(f[i][j],f[i][j-1]);
                g[i][j]=min(g[i][j],g[i][j-1]);
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(f[i][j]==1)continue; // alr ok
            go[j]=max(go[j],g[i][j]);
        }
    }
    build(1,1,m);
    int q;
    cin>>q;
    while(q--){
        int l,r;
        cin>>l>>r;
        int ans=qry(1,1,m,l,r);
        if(ans>l)no();
        else yes();
    }
    return;
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
	int t=1;
	//cin>>t;
	while(t--)eat();
}