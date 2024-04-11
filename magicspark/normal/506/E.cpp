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
#pragma comment("-Wl,--stack=1024000000")
//#include<ext/push_back_ds/assoc_container.hpp>
using namespace std;
//using namespace __gnu_push_backds;
const int inf=0x3f3f3f3f;
const double eps=1e-9;
const int mod=10007;
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
namespace BM{
const int N = 10010;
ll h[N];
int n,m;
ll fp(ll a,ll k){
	ll ans=1;
	for(;k;k>>=1,a=a*a%mod)
		if(k&1) ans=a*ans%mod;
	return ans;
}
void BM(ll *a,int n,vector<ll>&ans){
	ans.clear();
	vector<ll> lst;
	int w=0;ll delta=0;
	for(int i=1;i<=n;i++){
		ll tmp=0;
		for(int j=0;j<ans.size();j++)
			tmp=(tmp+a[i-1-j]*ans[j])%mod;
		if((a[i]-tmp)%mod==0) continue;
		if(!w){
			w=i;delta=a[i]-tmp;
			for(int j=i;j;j--) ans.push_back(0);
			continue;
		}
		vector<ll> now=ans;
		ll mul=(a[i]-tmp)*fp(delta,mod-2)%mod;
		if(ans.size()<lst.size()+i-w) ans.resize(lst.size()+i-w);
		ans[i-w-1]=(ans[i-w-1]+mul)%mod;
		for(int j=0;j<lst.size();j++) ans[i-w+j]=(ans[i-w+j]-mul*lst[j]%mod+mod)%mod;
		if(now.size()-i<lst.size()-w){
			lst=now;w=i;delta=a[i]-tmp;
		}
	}
}
ll calc(int m,vector<ll>&coef,ll*h){
	if(m<=coef.size()) return h[m];
	int k=coef.size();
	static ll f[N],g[N],res[N],p[N];
	p[0]=-1;
	for(int i=1;i<=k;i++) p[i]=coef[i-1];
	for(int i=0;i<=2*k;i++) f[i]=g[i]=0;
	f[0]=1;
	if(k>1) g[1]=1;
	else g[0]=p[1];
	auto mul = [&](ll *a,ll *b,ll *c){
		for(int i=0;i<=2*k;i++) res[i]=0;
		for(int i=0;i<k;i++)
			for(int j=0;j<k;j++)
				res[i+j]=(res[i+j]+a[i]*b[j])%mod;
		for(int i=2*k;i>=k;i--)
			if(res[i]%mod)
				for(int j=k;~j;j--)
					res[i-j]=(res[i-j]+res[i]*p[j])%mod;
		for(int i=0;i<2*k;i++) c[i]=res[i];
		return 0;
	};
	for(;m;m>>=1,mul(g,g,g))
		if(m&1) mul(f,g,f);
	ll ans=0;
	for(int i=0;i<k;i++)
		ans=(ans+h[i+1]*f[i])%mod;
	return ans;
}
void solve(vector<int>all,int tar){
	n=all.size();m=tar;
	for(int i=1;i<=n;i++)h[i]=all[i-1];
	vector<ll> ans;BM(h,n,ans);
	for(auto &x:ans)x=(x+mod)%mod;
	for(auto x:ans)cerr<<(x+mod)%mod<<' ';cerr<<endl;
	cout<<(calc(m,ans,h)+mod)%mod<<'\n';
	exit(0);
}
}
int n,m,f[1005][205][205],ans[1005],sub[1005];
string s;
inline void add(int &x,int y){
	x+=y;if(x>=mod)x-=mod;
}
int main(){
	cin>>s;n=s.size();cin>>m;
	f[0][0][n-1]=1;
	for(int i=1;i<=1000;i++){
		for(int l=0;l<n;l++)for(int r=l;r<n;r++){
			if(s[l]==s[r]){
				add(f[i][l][r],25*f[i-1][l][r]%mod);
				if(r-l<=1)add(ans[i],f[i-1][l][r]),add(sub[i],(l+1==r)*f[i-1][l][r]);
				else add(f[i][l+1][r-1],f[i-1][l][r]);
			}else{
				add(f[i][l][r],24*f[i-1][l][r]%mod);
				add(f[i][l+1][r],f[i-1][l][r]);
				add(f[i][l][r-1],f[i-1][l][r]);
			}
		}
		add(ans[i],26*ans[i-1]%mod);
	}
	if((n+m)&1)for(int i=1;i<=1000;i++)(ans[i]+=mod-sub[i])%=mod;
	vector<int>all;
	for(int i=1;i<=1000;i++)all.push_back(ans[i]);
	if((n+m-1)/2<1000){
		cout<<all[(n+m-1)/2]<<endl;
		return 0;
	}
	BM::solve(all,(n+m-1)/2);
	return 0;
}