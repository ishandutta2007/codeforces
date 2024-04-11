#include<bits/stdc++.h>
using namespace std;
 
#define int long long
 
#define rep(i,n) for(int i=0;i<(n);i++)
#define pb push_back
#define all(v) (v).begin(),(v).end()
#define fi first
#define se second
typedef vector<int>vint;
typedef pair<int,int>pint;
typedef vector<pint>vpint;
 
template<typename A,typename B>inline void chmin(A &a,B b){if(a>b)a=b;}
template<typename A,typename B>inline void chmax(A &a,B b){if(a<b)a=b;}
/*
time: less than O(NlogN+Q) amortized
based on weighted union heuristic
*/
struct UnionFindTree{
    vector<int>par,sz;
    UnionFindTree(int n){
        par.resize(n);
        sz.resize(n);
        for(int i=0;i<n;i++){
            par[i]=i;
            sz[i]=1;
        }
    }
    int find(int x){
        return x==par[x]?x:par[x]=find(par[x]);
    }
    void unite(int x,int y){
        x=find(x);y=find(y);
        if(x==y)return;
        if(sz[x]<sz[y])swap(x,y);
        sz[x]+=sz[y];
        par[y]=x;
    }
    bool areSame(int x,int y){
        return find(x)==find(y);
    }
    int size(int x){
        return sz[find(x)];
    }
};
int N,M;
int G[44];
 
template<class T>
inline void FastZetaTransformSubset(vector<T>&f,function<T(T,T)>add){
    int n=__lg(f.size());
    for(int i=0;i<n;i++){
        for(int j=0;j<1<<n;j++){
            if(~j>>i&1)f[j|1<<i]=add(f[j|1<<i],f[j]);
        }
    }
}
template<class T>
inline void FastZetaTransformSuperset(vector<T>&f,function<T(T,T)>add){
    int n=__lg(f.size());
    for(int i=0;i<n;i++){
        for(int j=0;j<1<<n;j++){
            if(~j>>i&1)f[j]=add(f[j],f[j|1<<i]);
        }
    }
}
 
 
signed main(){
	cin>>N>>M;
	rep(i,M){
		int a,b;
		cin>>a>>b;
		a--;b--;
		G[a]|=1ll<<b;
		G[b]|=1ll<<a;
	}
 
	int ans=1ll<<N;
	if(M==0)ans-=1ll<<N;
 
	UnionFindTree uf(2*N);
	rep(i,N)rep(j,N)if(G[i]>>j&1){
		uf.unite(i,j+N);
		uf.unite(i+N,j);
	}
 
	bool isbi=true;
	rep(i,N)if(uf.find(i)==uf.find(i+N))isbi=false;
	if(isbi){
		int num=0;
		rep(i,2*N)if(uf.find(i)==i)num++;
		num>>=1;
		ans+=1ll<<num;
	
    }
 
    int num=0;
    rep(i,N)if(__builtin_popcountll(G[i])==0)num++;
    ans+=1ll<<num+1;
 
    uf=UnionFindTree(N);
    rep(i,N)rep(j,N)if(G[i]>>j&1)uf.unite(i,j);
    num=0;
    rep(i,N)if(uf.find(i)==i)num++;
 
    ans-=1ll<<num;
 
 
    int n1=N/2;
    int n2=N-n1;
 
    vint f1(1ll<<n1,1);
    vint f2(1ll<<n2,1);
 
    rep(i,n1)rep(j,n1)if(G[i]>>j&1)f1[1ll<<i|1ll<<j]=0;
    rep(i,n2)rep(j,n2)if(G[n1+i]>>(n1+j)&1)f2[1ll<<i|1ll<<j]=0;
 
    FastZetaTransformSubset<int>(f1,[](int a,int b){return a&b;});
    FastZetaTransformSubset<int>(f2,[](int a,int b){return a&b;});
 
    FastZetaTransformSubset<int>(f2,[](int a,int b){return a+b;});
 
    rep(i,1ll<<n1){
        if(!f1[i])continue;
        int mask=0;
        rep(j,n1)if(i>>j&1)mask|=G[j]>>n1;
        mask=~mask^-1<<n2;
        
        ans-=f2[mask]*2;
    }
    cout<<ans<<endl;
	return 0;
}