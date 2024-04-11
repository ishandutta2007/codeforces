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
const int inf=2e9;
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
int modpow(int x,int y,int md=mod){if(y==0)return 1;int ret=modpow(x,y>>1,md);ret=(ll)ret*ret%md;if(y&1)ret=(ll)ret*x%md;return ret;}
int n;
int a[100005];
int solve(int l,int r,int bt){
	if(l>r)return -inf;
	if(bt==-1)return 0;
	int L=l-1,R=r+1;
	while(R-L>1){
		int mid=(L+R)/2;
		if(a[mid]&(1<<bt)){
			R=mid;
		}else{
			L=mid;
		}
	}
	int v1=solve(l,L,bt-1);
	int v2=solve(R,r,bt-1);
	if(v1==-inf||v2==-inf){
		return v1+v2+inf;
	}else{
		return max(min(v1,v2)+(1<<bt),max(v1,v2));
	}
}
signed main(){
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1); 
	cout<<solve(1,n,30)<<endl;
	return 0;
}