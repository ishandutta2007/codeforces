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
int n,p;
int a[100005],sum[100005],fk[200005];
int main(){
	cin>>n>>p;
	int mx=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		mx=max(mx,a[i]);
	}
	for(int i=1;i<=n;i++){
		a[i]=max(0,a[i]-mx+n-1);
		cerr<<a[i]<<" ";
		sum[a[i]]++;
	}cerr<<endl;
	for(int i=0;i<=n;i++){
		sum[i]+=sum[i-1];
	}
	for(int i=0;i<n;i++){
		int l=sum[i]-i,r=sum[i];l=max(l,0);
		if(l%p)l=(l/p+1)*p;
		r=r/p*p;
		if(l>r)continue;
		fk[l-(sum[i]-i)]++;fk[r-(sum[i]-i)+p]--;
	}
	for(int i=0;i+p<=2e5;i++)fk[i+p]+=fk[i];
	set<int>ban;ban.clear();
	for(int i=0;i<n;i++){
		if(fk[i]){
			ban.insert(i+mx-n+1);
		}
	}
//	cerr<<ban.size()<<endl;
//	for(auto v:ban)cerr<<v<<" ";cerr<<endl;
//	cout<<n-(int)ban.size()<<endl;
	bool van=0;
	vector<int>fans;
	for(int i=0;i<n;i++){
		if((i+1)%p==0)van=1;
		if(!ban.count(i+mx-n+1)&&!van)fans.push_back(i+mx-n+1);
	}
	cout<<fans.size()<<endl;
	for(auto v:fans)cout<<v<<" ";
	return 0;
}