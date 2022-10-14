#include<bits/stdc++.h>
#define int long long
#define ls(x) ((x)<<1)
#define rs(x) ((x)<<1|1)
using namespace std;
int const N=800010,K=200000,MOD=998244353;
int t,n,m,tr[N],x[N],y[N];
set<int>ans,opr;
namespace combin{
	int fac[N],inv[N];
	int qpow(int x,int y){
		return y?qpow(x*x%MOD,y>>1)*(y&1?x:1)%MOD:1;
	}
	int C(int n,int m){
		return n<m||m<0?0:fac[n]*inv[m]%MOD*inv[n-m]%MOD;
	}
	void init(){
		fac[0]=fac[1]=inv[0]=inv[1]=1;
		for(int i=2;i<N;i++)
			fac[i]=fac[i-1]*i%MOD;
		inv[N-1]=qpow(fac[N-1],MOD-2);
		for(int i=N-1;i>1;i--)
			inv[i-1]=inv[i]*i%MOD;
	}
}
void update(int x){
	tr[x]=tr[ls(x)]+tr[rs(x)];
}
void build(int x,int l,int r){
	if(l==r){
		tr[x]=1;
		return;
	}
	int mid=(l+r)>>1;
	build(ls(x),l,mid);
	build(rs(x),mid+1,r);
	update(x);
}
void modify(int x,int l,int r,int p,int k){
	if(l==r){
		tr[x]=k;
		return;
	}
	int mid=(l+r)>>1;
	if(p<=mid)
		modify(ls(x),l,mid,p,k);
	else
		modify(rs(x),mid+1,r,p,k);
	update(x);
}
int query(int x,int l,int r,int k){
	if(l==r)
		return l;
	int mid=(l+r)>>1;
	return k<=tr[ls(x)]?query(ls(x),l,mid,k):
		query(rs(x),mid+1,r,k-tr[ls(x)]);
}
signed main(){
	ios::sync_with_stdio(0);
	build(1,1,K),combin::init();
	for(cin>>t;t--;){
		cin>>n>>m;
		ans.clear(),opr.clear();
		for(int i=1;i<=m;i++)
			cin>>x[i]>>y[i];
		for(int i=m;i>=1;i--){
			int t=query(1,1,K,y[i]);
			modify(1,1,K,t,0),opr.insert(t);
			ans.insert(query(1,1,K,y[i]));
		}
		for(int i:opr)
			modify(1,1,K,i,1);
		cout<<combin::C(2*n-1-ans.size(),n)<<"\n";
	}
}