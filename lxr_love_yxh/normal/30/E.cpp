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
//#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
//using namespace __gnu_pbds;
const int inf=0x3f3f3f3f;
const double eps=1e-6;
const int mod=1e9+7;
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
string s,rs;
int n,hsh[100005],z[200005],h[100005],pw[100005],ans[100005],mv;
const int base=20050917;
void z_func(string s){
	z[0]=0;int l=0,r=0;
	for(int i=1;i<s.size();i++){
		if(i<=r)z[i]=min(r-i,z[i-l]);
		while(i+z[i]<s.size()&&s[z[i]]==s[i+z[i]])z[i]++;
		if(i+z[i]>r)l=i;r=i+z[i];
	}
}
int get_h1(int l,int r){return (hsh[r]-1ll*hsh[l-1]*pw[r-l+1]%mod+mod)%mod;}
int get_h2(int l,int r){return (h[l]-1ll*h[r+1]*pw[r-l+1]%mod+mod)%mod;}
int main(){
	cin>>s;n=s.size();s=" "+s;rs="";
	for(int i=n;i>=1;i--)rs.push_back(s[i]);
	rs+='#';int st=rs.size()-1;
	for(int i=1;i<=n;i++)rs.push_back(s[i]);
	z_func(rs);
	pw[0]=1;
	for(int i=1;i<=n;i++)pw[i]=1ll*pw[i-1]*base%mod;
	for(int i=1;i<=n;i++)hsh[i]=(1ll*hsh[i-1]*base+s[i])%mod;
	for(int i=n;i>=1;i--)h[i]=(1ll*h[i+1]*base+s[i])%mod;
	for(int i=1;i<=n;i++)ans[i+z[i+st]-1]=max(ans[i+z[i+st]-1],z[i+st]);
	for(int i=n-1;i>=1;i--)ans[i]=max(ans[i],ans[i+1]-1);
	for(int i=1;i<=n;i++)ans[i]=max(ans[i],ans[i-1]);
	int len=0,pos;
	for(int i=1;i<=n;i++){
		int l=0,r=n;
		while(r-l>1){
			int mid=(l+r)/2;
			if(i-mid>=1&&i+mid<=n&&get_h1(i-mid,i)==get_h2(i,i+mid))l=mid;
			else r=mid;
		}
		int tmp=min(ans[i-l-1],n-(i+l));
		len=max(len,tmp*2+l*2+1);
		if(len==tmp*2+l*2+1){
			pos=i;mv=l;
		}
	}
	if(min(ans[pos-mv-1],n-(pos+mv))==0){
		cout<<1<<endl;
		cout<<pos-mv<<" "<<2*mv+1<<endl;
		return 0;
	}
	int suf=min(ans[pos-mv-1],n-(pos+mv));
	for(int i=1;i<=n;i++)if(get_h1(i,i+suf-1)==get_h2(n-suf+1,n)){
		cout<<3<<endl;
		cout<<i<<" "<<suf<<endl;
		cout<<pos-mv<<" "<<2*mv+1<<endl;
		cout<<n-suf+1<<" "<<suf<<endl;
		return 0;
	}
	return 0;
}