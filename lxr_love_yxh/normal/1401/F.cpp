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
int n,m,a[1<<18];
ll f[1<<19],mask;
void init(){
	for(int i=0;i<(1<<n);i++)f[i+(1<<n)]=a[i];
	for(int i=(1<<n)-1;i>=1;i--)f[i]=f[i<<1]+f[i<<1|1];
}
ll query(int l,int r,int k,int ql,int qr,int lvl){
	if(r<ql||qr<l)return 0;
	if(ql<=l&&r<=qr){
		return f[k];
	}
	int mid=(l+r)/2,L=(mask>>lvl)&1,R=1-L;
	return query(l,mid,k<<1|L,ql,qr,lvl-1)+query(mid+1,r,k<<1|R,ql,qr,lvl-1);
}
void set_v(int x,int k){
	x+=(1<<n);f[x]=k;
	while(x!=1){
		x>>=1;
		f[x]=f[x<<1]+f[x<<1|1];
	}
}
int main(){
	cin>>n>>m;
	for(int i=0;i<(1<<n);i++){
		cin>>a[i];
	}
	init();
	while(m--){
		int type;
		cin>>type;
		if(type==1){
			int x,k;cin>>x>>k;x--;
			x^=mask;set_v(x,k);
		}
		if(type==2){
			int k;cin>>k;
			mask^=(1<<k)-1;
		}
		if(type==3){
			int k;cin>>k;
			mask^=1<<k;
		}
		if(type==4){
			int l,r;cin>>l>>r;l--;r--;
			cout<<query(0,(1<<n)-1,1,l,r,n-1)<<endl;
		}
	}
	return 0;
}