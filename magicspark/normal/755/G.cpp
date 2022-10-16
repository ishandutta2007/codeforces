/*
Though leaves are many , the root is one.
Through all the lying days of my youth
I swayed my leaves and flowers in the sun.
Now I may wither into the truth.
	  	  	- William Butler Yeats
*/
//#pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline") //Optimization flags
//#pragma GCC option("arch=native","tune=native","no-zero-upper") //Enable AVX
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2")
#include<bits/stdc++.h>
//#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
//using namespace __gnu_pbds;
const int inf=0x3f3f3f3f;
const double eps=1e-9;
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
namespace NTT{
int n,m,N=1;
int w[2<<18],iw[2<<18];
const int g=3;
int rev[2<<17];
void init(){
	w[1]=modpow(3,(mod-1)/(2<<17));
	iw[1]=modpow(w[1],mod-2);
	w[0]=iw[0]=1;
	for(int i=2;i<(2<<17);i++){
		w[i]=(ll)w[i-1]*w[1]%mod;
		iw[i]=(ll)iw[i-1]*iw[1]%mod;
	}
}
void ntt(int *a,int len,int inv){
	int L=log2(len);
	for(int i=0;i<len;i++)rev[i]=0;
	for(int i=0;i<len;i++){
		rev[i]=(rev[i>>1]>>1)|((i&1)<<(L-1));
		if(rev[i]<i)swap(a[i],a[rev[i]]);
	}
	int tot=18;
	for(int i=1;i<len;i<<=1){
		tot--;
		for(int j=0;j<len;j+=(i<<1)){
			for(int k=0;k<i;k++){
				if(tot<0)cerr<<len<<" "<<inv<<endl;
				int y=inv==1?w[k<<tot]:iw[k<<tot];
				y=(ll)y*a[j+k+i]%mod;
				a[j+k+i]=(a[j+k]-y+mod)%mod;
				a[j+k]=(a[j+k]+y)%mod;
			}
		}
	}
}
int a[2<<17],b[2<<17];
vector<int>convolution(vector<int>va,vector<int>vb){
//	freopen("input.txt","r",stdin);
	n=(int)va.size()-1;m=(int)vb.size()-1;N=1;
	for(int i=0;i<=n;i++)a[i]=va[i];
	for(int i=0;i<=m;i++)b[i]=vb[i];
	while(N<=n+m)N<<=1;
	for(int i=n+1;i<N;i++)a[i]=0;
	for(int i=m+1;i<N;i++)b[i]=0;
	ntt(a,N,1);ntt(b,N,1);
	for(int i=0;i<N;i++)a[i]=(ll)a[i]*b[i]%mod;
	ntt(a,N,-1);
	int inv=modpow(N,mod-2);
	vector<int>ret;
	for(int i=0;i<=n+m;i++)ret.push_back(1ll*a[i]*inv%mod);
	while(ret.size()>32768)ret.pop_back();
//	for(auto u:va)cerr<<u<<" ";cerr<<endl;
//	for(auto u:vb)cerr<<u<<" ";cerr<<endl;
//	for(auto u:ret)cerr<<u<<" ";cerr<<endl;
	return ret;
}
}
#define data rubgnoirwngfpr
int n,k;
struct data{
	vector<int>v[3];
	data(){v[0].clear();v[1].clear();v[2].clear();}
};
vector<int>convolution(vector<int>v1,vector<int>v2){
	vector<int>ret(v1.size()+v2.size()-1,0);
	for(int i=0;i<v1.size();i++){
		for(int j=0;j<v2.size();j++){
			ret[i+j]=(ret[i+j]+1ll*v1[i]*v2[j])%mod;
		}
	}
	return ret;
}
void add(vector<int>&v1,vector<int>v2,int shift){
	if(shift==1)v2.insert(v2.begin(),0);
	while(v1.size()<v2.size())v1.push_back(0);
	for(int i=0;i<v2.size();i++)v1[i]=(v1[i]+v2[i])%mod;
}
data get(int n){
	//v[0]: n
	//v[1]: n-1
	//v[2]: n-2
	if(n==1){
		data ret;
		ret.v[0].push_back(1);
		ret.v[0].push_back(1);
		ret.v[1].push_back(1);
		ret.v[2].push_back(0);
		return ret;
	}
	auto tmp=get(n/2);
	auto v0=tmp.v[0],v1=tmp.v[1],v2=tmp.v[2];
	data ret;
	add(ret.v[0],NTT::convolution(v0,v0),0);
	add(ret.v[0],NTT::convolution(v1,v1),1);
	add(ret.v[1],NTT::convolution(v0,v1),0);
	add(ret.v[1],NTT::convolution(v1,v2),1);
	add(ret.v[2],NTT::convolution(v1,v1),0);
	add(ret.v[2],NTT::convolution(v2,v2),1);
	if(n&1){
		vector<int>V;
		add(V,ret.v[0],1);
		add(V,ret.v[0],0);
		add(V,ret.v[1],1);
		ret.v[2]=ret.v[1];
		ret.v[1]=ret.v[0];
		ret.v[0]=V;
	}
	return ret;
}
signed main(){
	cin>>n>>k;NTT::init();
	auto got=get(n).v[0];
	for(auto u:got)cerr<<u<<" ";cerr<<endl;
	for(int i=1;i<=k;i++){
		if(i<got.size())cout<<got[i]<<" ";
		else cout<<0<<" ";
	}
	return 0;
}