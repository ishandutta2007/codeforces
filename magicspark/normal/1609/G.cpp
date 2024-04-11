/*
Though leaves are many , the root is one.
Through all the lying days of my youth
I swayed my leaves and flowers in the sun.
Now I may wither into the truth.
	  	  	- William Butler Yeats
*/
#pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline") //Optimization flags
#pragma GCC option("arch=native","tune=native","no-zero-upper") //Enable AVX
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2")
#include<bits/stdc++.h>
#define int long long
#pragma comment("-Wl,--stack=1024000000")
//#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
//using namespace __gnu_pbds;
const int inf=0x3f3f3f3f;
const double eps=1e-9;
const int mod=1000000007;
typedef long long ll;
#ifndef LOCAL
#define cerr if(0)cout
#define eprintf(...) 0
#else
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#endif
inline string getstr(string &s,int l,int r){string ret="";for(int i=l;i<=r;i++)ret.push_back(s[i]);return ret;}
int modpow(int x,int y,int md=mod){int ret=1;do{if(y&1)ret=(ll)ret*x%md;x=(ll)x*x%md;}while(y>>=1);return ret;}
inline int Rand(){return rand()*32768+rand();}
int n,m,q,a[105],b[100005],pos[105];
#define SIZE 131072
int ans1,ans2;
struct SGT{
	int f[SIZE<<1],sum1[SIZE<<1],sum2[SIZE<<1],tag[SIZE<<1],id[SIZE<<1],len[SIZE<<1];
	SGT(){
		memset(f,inf,sizeof f);
		for(int i=0;i<SIZE;i++)id[i+SIZE]=i,len[i+SIZE]=1;
		for(int i=SIZE-1;i>=1;i--)id[i]=id[i<<1]+id[i<<1|1],len[i]=len[i<<1]+len[i<<1|1];
	}
	void update(int x,int v){
		x+=SIZE;sum1[x]=v;sum2[x]=v*(x-SIZE);f[x]=v;
		while(x!=1){
			x>>=1;
			sum1[x]=sum1[x<<1]+sum1[x<<1|1];
			sum2[x]=sum2[x<<1]+sum2[x<<1|1];
			f[x]=min(f[x<<1],f[x<<1|1]);
		}
	}
	void pushdown(int k){
		if(tag[k]){
			tag[k<<1]+=tag[k];
			tag[k<<1|1]+=tag[k];
			tag[k]=0;
		}
	}
	void pushup(int k){
		sum1[k]=0;sum2[k]=0;f[k]=9e18;
		for(int i=(k<<1);i<(k+1<<1);i++){
			sum1[k]+=sum1[i]+tag[i]*len[i];
			sum2[k]+=sum2[i]+tag[i]*id[i];
			f[k]=min(f[k],f[i]+tag[i]); 
		}
	}
	void add(int l,int r,int k,int ql,int qr,int qv){
		if(qr<l||r<ql)return;
		if(ql<=l&&r<=qr){
			tag[k]+=qv;
			return;
		}
		pushdown(k);
		add(l,(l+r)/2,k<<1,ql,qr,qv);
		add((l+r)/2+1,r,k<<1|1,ql,qr,qv);
		pushup(k);
	}
	void query(int l,int r,int k,int ql,int qr){
		if(qr<l||r<ql)return;
		if(ql<=l&&r<=qr){ans1+=sum1[k]+tag[k]*len[k];ans2+=sum2[k]+tag[k]*id[k];return;}
		pushdown(k);
		query(l,(l+r)/2,k<<1,ql,qr);
		query((l+r)/2+1,r,k<<1|1,ql,qr);
		pushup(k);
	}
	int search(int l,int r,int k,int val){
		if(l==r)return l;
		int mid=(l+r)/2;
		int ret;val-=tag[k];
		if(f[k<<1|1]+tag[k<<1|1]>val)ret=search(l,mid,k<<1,val);
		else ret=search(mid+1,r,k<<1|1,val);
		return ret;
	}
}T;
int ask(int l,int r,int lvl){
	if(l>r)return 0;int ret=0;
//	cerr<<l<<" "<<r<<" "<<lvl<<endl;
//	for(int i=l;i<=r;i++)ret+=b[i];ret*=(lvl+r);
	ans1=ans2=0;T.query(0,SIZE-1,1,l,r);
	ret+=ans1*(lvl+r);ret-=ans2;
//	for(int i=l;i<=r;i++)ret-=b[i]*i;
	return ret;
}
int base=0;
signed main(){
	ios::sync_with_stdio(0);
	cin>>n>>m>>q;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=m;i++)cin>>b[i];
	for(int i=n;i>=1;i--)a[i]-=a[i-1];
	for(int i=m;i>=1;i--)b[i]-=b[i-1];
	base=(a[1]+b[1]);a[1]=0;b[1]=0;
	T.update(0,0);for(int i=1;i<=m;i++)T.update(i,b[i]);
	while(q--){
		int tp,k,d;cin>>tp>>k>>d;
		if(tp==1){
			for(int i=n-k+1;i<=n;i++)a[i]+=d;
		}else{
			if(k==m)base+=d;
			T.add(0,SIZE-1,1,max(2ll,m-k+1),SIZE-1,d);
		}
		if(a[1])base+=a[1],a[1]=0;
//		for(int i=1;i<=n;i++)cerr<<a[i]<<" ";cerr<<endl;
//		for(int i=1;i<=m;i++)cerr<<b[i]<<" ";cerr<<endl;
//		cerr<<"----------"<<endl;
		for(int i=1;i<=n;i++)pos[i]=T.search(0,SIZE-1,1,a[i]);
//		for(int i=1;i<=n;i++)cerr<<pos[i]<<" ";cerr<<endl;
		int ans=0;
		for(int i=1;i<=n;i++)ans+=(n+m-i-pos[i]+1)*a[i];
		pos[0]=0;pos[n+1]=m;
		for(int i=0;i<=n;i++){
			ans+=ask(pos[i]+1,pos[i+1],m-pos[i+1]+1+n-i);
		}
		cout<<ans+base*(n+m-1)<<endl;
	}
	return 0;
}