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
template<typename T>inline int read(T &x){
    register char c=getchar();register T f=1;x=0;
    while(!isdigit(c)) c=='-'?f=-1:1,c=getchar();
    while(isdigit(c)) x=(x<<3)+(x<<1)+(c^48),c=getchar();
    x*=f;return c=='\n';
}
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
int n,q;
#define SIZE 262144
ll f[SIZE<<1],tag[SIZE<<1];
void set_v(int x,int v){
	x+=SIZE;f[x]=v;
	while(x!=1){
		x>>=1;
		f[x]=min(f[x<<1],f[x<<1|1]);
	}
}
void add(int l,int r,int k,const int &ql,const int &qr,const int &qv){
	if(r<ql||qr<l)return;
	if(ql<=l&&r<=qr){
		tag[k]+=qv;return;
	}
	int mid=(l+r)/2;
	add(l,mid,k<<1,ql,qr,qv);
	add(mid+1,r,k<<1|1,ql,qr,qv);
	f[k]=min(f[k<<1]+tag[k<<1],f[k<<1|1]+tag[k<<1|1]);
}
const ll Linf=1e18;
ll query(int l,int r,int k,const int &ql,const int &qr){
	if(r<ql||qr<l)return Linf;
	if(ql<=l&&r<=qr){return f[k]+tag[k];}
	int mid=(l+r)/2;
	ll vl=query(l,mid,k<<1,ql,qr);
	ll vr=query(mid+1,r,k<<1|1,ql,qr);
//	f[k]=min(f[k<<1]+tag[k<<1],f[k<<1|1]+tag[k<<1|1]);
	return min(vl,vr)+tag[k];
}
int main(){
	read(n);
	for(int i=0;i<n;i++){
		int x;read(x);
		set_v(i,x);
	}
	read(q);
	while(q--){
		int l,r,v;
		read(l);int type=read(r);
		if(type){
			ll ans;
			if(l>r)ans=min(query(0,SIZE-1,1,l,n-1),query(0,SIZE-1,1,0,r));
			else ans=query(0,SIZE-1,1,l,r);
			printf("%I64d\n",ans);
		}else{
			read(v);
			if(l>r)add(0,SIZE-1,1,l,n-1,v),add(0,SIZE-1,1,0,r,v);
			else add(0,SIZE-1,1,l,r,v);
		}
	}
	return 0;
}