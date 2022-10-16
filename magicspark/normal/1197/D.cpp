/*
Though leaves are many , the root is one.
Through all the lying days of my youth
I swayed my leaves and flowers in the sun.
Now I may wither into the truth.
*/
#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
#pragma GCC target("avx,tune=native")
#include<bits/stdc++.h>
#define int long long
//#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
//using namespace __gnu_pbds;
const int inf=0x3f3f3f3f3f3f;
const double eps=1e-6;
const int mod=1000000007;
typedef long long ll;
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
inline string getstr(string &s,int l,int r){string ret="";for(int i=l;i<=r;i++)ret.push_back(s[i]);return ret;}
int modpow(int x,int y,int md=mod){if(y==0)return 1;int ret=modpow(x,y>>1,md);ret=(ll)ret*ret%md;if(y&1)ret=(ll)ret*x%md;return ret;}
int n,m,k;
int a[300015];
int pre[300015];
struct sgt1{
	#define SIZE 1048576
	int f[SIZE<<1],l,r;
	segtree(){for(int i=0;i<(SIZE<<1);i++)f[i]=-1e18;}
	void set(int x,int v){
		x+=SIZE;f[x]=v;
		while(x!=1){
			x>>=1;
			f[x]=max(f[x<<1],f[x<<1|1]);
		}
	}
	int _query(int ll,int rr,int k){
		if(l<=ll&&rr<=r)return f[k];
		if(r<ll||rr<l)return -inf;
		return max(_query(ll,ll+rr>>1,k<<1),_query((ll+rr>>1)+1,rr,k<<1|1));
	}
	int query(int _l,int _r){
		l=_l;r=_r;return _query(0,SIZE-1,1);
	}
}sum;
struct sgt2{
	#define SIZE 1048576
	int f[SIZE<<1],l,r;
	segtree(){for(int i=0;i<(SIZE<<1);i++)f[i]=1e18;}
	void set(int x,int v){
		x+=SIZE;f[x]=v;
		while(x!=1){
			x>>=1;
			f[x]=min(f[x<<1],f[x<<1|1]);
		}
	}
	int _query(int ll,int rr,int k){
		if(l<=ll&&rr<=r)return f[k];
		if(r<ll||rr<l)return inf;
		return min(_query(ll,ll+rr>>1,k<<1),_query((ll+rr>>1)+1,rr,k<<1|1));
	}
	int query(int _l,int _r){
		l=_l;r=_r;return _query(0,SIZE-1,1);
	}
}modular;
int ans=0,real_n;
inline int get_max(int l,int r){
	r=min(r,real_n);
	return sum.query(l,r)-sum.query(l,l);
}
void solve(int st){
	for(int i=1;i<=n/m;i++){
		if(a[st+(i-1)*m]==-inf)continue;
//		cerr<<st<<" "<<i<<" "<<pre[st+(i-1)*m]-pre[st-1]-k*i<<" "<<modular.query(0,i-1)<<" "<<get_max(st+(i-1)*m,st+i*m-1)<<" "<<pre[st+(i-1)*m]-pre[st-1]-k*i-modular.query(0,i-1)+get_max(st+(i-1)*m,st+i*m-1)<<endl;
		ans=max(ans,pre[st+(i-1)*m]-pre[st-1]-k*i-modular.query(0,i-1)+get_max(st+(i-1)*m,st+i*m-1));
	}
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;real_n=n;
	for(int i=1;i<=n;i++){
		cin>>a[i]; 
	}
	while(n%m){
		a[++n]=-inf;
	}
	for(int i=1;i<=n;i++){
		pre[i]=pre[i-1]+a[i];
		sum.set(i,pre[i]);
	}
	modular.set(0,0);
	for(int st=1;st<=m;st++){
		vector<int>value(n/m+5,0);
		for(int pos=st;pos<=n;pos+=m){
			value[(pos-1)/m+1]=pre[pos+m-1]-pre[pos-1]-k;
		}
		for(int i=1;i<=n/m;i++)value[i]=value[i-1]+value[i];
		for(int i=1;i<=n/m;i++){
			modular.set(i,value[i]);
		}
		solve(st);
	}
	cout<<ans<<endl;
	return 0;
}