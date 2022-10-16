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
int n,d,m;
int a[100005];
signed main(){
	vector<int>v1,v2;
	cin>>n>>d>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]<=m)v1.push_back(a[i]);
		else v2.push_back(a[i]);
	}
	sort(v1.rbegin(),v1.rend());
	sort(v2.rbegin(),v2.rend());
	ll ans=0;
	if(v2.size())ans+=v2[0],v2.erase(v2.begin());
	else ans+=v1[0],v1.erase(v1.begin());
	n--;
	for(int i=1;i<v1.size();i++)v1[i]+=v1[i-1];
	for(int i=1;i<v2.size();i++)v2[i]+=v2[i-1];
	int cur=v1.size()?v1.back():0ll;
	v1.insert(v1.begin(),0);
	for(int i=0;i<v2.size();i++){
		if(n-(d+1)*(i+1)<0)break;
		cur=max(cur,v2[i]+v1[min((int)v1.size()-1,n-(d+1)*(i+1))]);
	}
	cout<<ans+cur<<endl;
	return 0;
}