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
int n,m,r,a[33],b[33],k[33],p[33],ans=-1ll<<60;
void step0(){
	for(int i=1;i<=n;i++)a[i]^=b[i];
}
void step1(){
	int tmp[33]={};
	for(int i=1;i<=n;i++){
		tmp[i]=a[p[i]]+r;
	}
	memcpy(a,tmp,sizeof a);
}
void dfs(int x,int lst){
	if(x%2==(m+1)%2){
		int cur=0;
		for(int i=1;i<=n;i++)cur+=k[i]*a[i];
		ans=max(ans,cur);
		if(x==m+1)return;
	}
	int arr[33];
	memcpy(arr,a,sizeof a);
	if(lst==1){
		step0();
		dfs(x+1,0);
		memcpy(a,arr,sizeof arr);
	}
	step1();
	dfs(x+1,1);
	memcpy(a,arr,sizeof a);
}
signed main(){
	cin>>n>>m>>r;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)cin>>b[i];
	for(int i=1;i<=n;i++)cin>>k[i];
	for(int i=1;i<=n;i++)cin>>p[i];
	dfs(1,1);
	cout<<ans<<endl;
	return 0;
}