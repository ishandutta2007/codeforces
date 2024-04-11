/*
Though leaves are many , the root is one.
Through all the lying days of my youth
I swayed my leaves and flowers in the sun.
Now I may wither into the truth.
	  	  	- William Butler Yeats
*/
//#pragma GCC optimize("Ofast,no-stack-protector")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
//#pragma GCC target("avx,tune=native")
#include<bits/stdc++.h>
#define int long long
#pragma comment("-Wl,--stack=1024000000")
//#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
//using namespace __gnu_pbds;
const int inf=0x3f3f3f3f;
const double eps=1e-6;
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
int n;
int p[200005],a[200005],pos[200005];
struct SegTree{
	#define SIZE 262144
	ll f[SIZE<<1]={},lazy[SIZE<<1]={};
	void addpoint(int pos,int v){
		pos+=SIZE-1; 
		f[pos]=v;
		while(pos){
			pos=pos-1>>1;
			f[pos]=min(f[pos+pos+1],f[pos+pos+2]);
		}
	}
	ll query(int l,int r,int l1=0,int r1=SIZE-1,int k=0){
		//if(l<=l1&&r1<=r)cerr<<l<<" "<<r<<" "<<l1<<" "<<r1<<" "<<k<<" "<<f[k]<<" "<<lazy[k]<<endl;
		if(l<=l1&&r1<=r)return f[k]+lazy[k];
		if(r<l1||r1<l)return (ll)1e18;
		lazy[k+k+1]+=lazy[k];lazy[k+k+2]+=lazy[k];lazy[k]=0;
		int mid=l1+r1>>1;
		ll vl=query(l,r,l1,mid,k+k+1);
		ll vr=query(l,r,mid+1,r1,k+k+2);
		f[k]=min(f[k+k+1]+lazy[k+k+1],f[k+k+2]+lazy[k+k+2]);
		//cerr<<l<<" "<<r<<" "<<l1<<" "<<r1<<" "<<vl<<" "<<vr<<endl;
		return min(vl,vr);
	}
	void addrange(int l,int r,int v,int l1=0,int r1=SIZE-1,int k=0){
		if(l<=l1&&r1<=r){
			//cerr<<l<<" "<<r<<" "<<l1<<" "<<r1<<" "<<k<<" "<<v<<endl;
			lazy[k]+=v;
			return;
		}
		if(l1>r||r1<l)return;
		lazy[k+k+1]+=lazy[k];lazy[k+k+2]+=lazy[k];lazy[k]=0;
		int mid=l1+r1>>1;
		addrange(l,r,v,l1,mid,k+k+1);
		addrange(l,r,v,mid+1,r1,k+k+2);
		f[k]=min(f[k+k+1]+lazy[k+k+1],f[k+k+2]+lazy[k+k+2]);
		return;
	}
}T;
signed main(){
	cin>>n;
	for(int i=1;i<=n;i++)cin>>p[i],pos[p[i]]=i;
	for(int i=1;i<=n;i++)cin>>a[i],T.addrange(i,n,a[i]);
	int cur=0,ans=T.query(1,n-1);
	for(int i=1;i<=n;i++){
		cur+=a[pos[i]];
		T.addrange(pos[i],n,-a[pos[i]]*2ll);
		int val=T.query(1,n-1);
		ans=min(ans,cur+val);
	}
	cout<<ans<<endl;
	return 0;
}