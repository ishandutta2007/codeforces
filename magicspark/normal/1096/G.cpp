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
const int mod=998244353;
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
int n,k;
int a[1<<20],b[1<<20],rev[1<<20],w[1<<20],iw[1<<20];
void ntt_init(){
	const int size=1<<20;
	w[0]=iw[0]=1;
	w[1]=modpow(3,(mod-1)/size);
	iw[1]=modpow(w[1],mod-2);
	for(int i=2;i<(1<<20);i++){
		w[i]=(ll)w[i-1]*w[1]%mod;
		iw[i]=(ll)iw[i-1]*iw[1]%mod;
	}
}
void ntt(vector<int>&a,int len,int inv){
	int L=log2(len);
	for(int i=0;i<len;i++){
		rev[i]=(rev[i>>1]>>1)|((i&1)<<(L-1));
		if(i<rev[i])swap(a[i],a[rev[i]]);
	}
	int tot=20;
	for(int i=1;i<len;i<<=1){
		tot--;
		for(int j=0;j<len;j+=(i<<1)){
			for(int k=0;k<i;k++){
				int p1=j+k,p2=j+k+i;
				int x=a[p1],y=(ll)a[p2]*(inv==1?w[k<<tot]:iw[k<<tot])%mod;
				a[p1]=x+y;a[p2]=x-y;
				if(a[p1]>=mod)a[p1]-=mod;
				if(a[p2]<0)a[p2]+=mod;
			}
		}
	}
}
vector<int>mul(vector<int>a,vector<int>b){
	int N=1;
	while(N<=a.size()+b.size())N<<=1;
	a.resize(N,0);
	b.resize(N,0);
	ntt(a,N,1);
	ntt(b,N,1);
	vector<int>ret(N,0);
	for(int i=0;i<N;i++){
		ret[i]=(ll)a[i]*b[i]%mod;
	}
	int inv=modpow(N,mod-2,mod);
	ntt(ret,N,-1);
	for(int i=0;i<N;i++)ret[i]=(ll)ret[i]*inv%mod;
	while(ret.back()==0)ret.pop_back();
	return ret;
}
int mask;
int main(){
	ntt_init(); 
	cin>>n>>k;
	for(int i=0;i<k;i++){
		int x;cin>>x;mask|=(1<<x);
	}
	vector<int>poly;
	for(int i=0;i<=9;i++){
		poly.push_back((mask>>i)&1);
	}
	vector<int>p={1};
	int pw=n/2;
	do{
		if(pw&1)p=mul(p,poly);
		poly=mul(poly,poly);
	}while(pw>>=1);
	int ans=0;
	for(int i=0;i<p.size();i++){
		ans+=(ll)p[i]*p[i]%mod;
		ans%=mod;
	}
	cout<<ans<<endl;
	return 0;
}