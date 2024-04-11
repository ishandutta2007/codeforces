/*
Though leaves are many , the root is one.
Through all the lying days of my youth
I swayed my leaves and flowers in the sun.
Now I may wither into the truth.
*/
//#pragma GCC optimize("Ofast,no-stack-protector")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
//#pragma GCC target("avx,tune=native")
#include<bits/stdc++.h>
//#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
//using namespace __gnu_pbds;
const int inf=0x3f3f3f3f;
const double eps=1e-6;
const int mod=1000000007;
typedef long long ll;
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
inline string getstr(string &s,int l,int r){string ret="";for(int i=l;i<=r;i++)ret.push_back(s[i]);return ret;}
int modpow(int x,int y,int md=mod){if(y==0)return 1;int ret=modpow(x,y>>1,md);ret=(ll)ret*ret%md;if(y&1)ret=(ll)ret*x%md;return ret;}
int n,q;
vector<int>g[200005];
int v[200005],l[200005],r[200005],dfn[200005],dfs_clock;
void dfs(int x){
	l[x]=dfn[x]=++dfs_clock;
	for(auto to:g[x])dfs(to);
	r[x]=dfs_clock;
}
struct segtree{
	#define SIZE 262144
	int f[SIZE<<1],lazy[SIZE<<1],sz[SIZE<<1],l,r;
	segtree(){
		for(int i=SIZE;i<SIZE*2;i++)sz[i]=1;
		for(int i=SIZE-1;i>=1;i--)sz[i]=sz[i<<1]+sz[i<<1|1];
	}
	void set(int pos,int v){
		pos+=SIZE;f[pos]=v;
		while(pos!=1){
			pos>>=1;
			f[pos]=f[pos<<1]+f[pos<<1|1];
		}
	}
	void _inv(int ll,int rr,int k){
		if(rr<l||r<ll)return;
		if(l<=ll&&rr<=r){
			lazy[k]^=1;
			return;
		}
		int mid=ll+rr>>1;
		if(lazy[k]){
			lazy[k<<1]^=1;
			lazy[k<<1|1]^=1;
			lazy[k]=0;
		}
		_inv(ll,mid,k<<1);
		_inv(mid+1,rr,k<<1|1);
		f[k]=(lazy[k<<1]?sz[k<<1]-f[k<<1]:f[k<<1])+(lazy[k<<1|1]?sz[k<<1|1]-f[k<<1|1]:f[k<<1|1]);
	}
	void inv(int _l,int _r){
		l=_l;r=_r;_inv(0,SIZE-1,1);
	}
	int _query(int ll,int rr,int k){
		if(rr<l||r<ll)return 0;
		if(l<=ll&&rr<=r){
			return lazy[k]?sz[k]-f[k]:f[k];
		}
		int mid=ll+rr>>1;
		if(lazy[k]){
			lazy[k<<1]^=1;
			lazy[k<<1|1]^=1;
			lazy[k]=0;
		}
		int vl=_query(ll,mid,k<<1);
		int vr=_query(mid+1,rr,k<<1|1);
		f[k]=(lazy[k<<1]?sz[k<<1]-f[k<<1]:f[k<<1])+(lazy[k<<1|1]?sz[k<<1|1]-f[k<<1|1]:f[k<<1|1]);
		return vl+vr;
	}
	int query(int _l,int _r){
		l=_l;r=_r;return _query(0,SIZE-1,1);
	}
}seg;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=2;i<=n;i++){
		int p;cin>>p;g[p].push_back(i);
	}
	dfs(1);
	for(int i=1;i<=n;i++)cin>>v[i];
	for(int i=1;i<=n;i++)seg.set(dfn[i],v[i]);
	cin>>q;
	while(q--){
		string s;int root;
		cin>>s>>root;
		if(s[0]=='p'){
			seg.inv(l[root],r[root]);
		}else{
			cout<<seg.query(l[root],r[root])<<endl;
		}
	}
	return 0;
}