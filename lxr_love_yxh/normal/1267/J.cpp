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
int modpow(int x,int y,int md=mod){if(y==0)return 1;int ret=modpow(x,y>>1,md);ret=(ll)ret*ret%md;if(y&1)ret=(ll)ret*x%md;return ret;}
int T,n;
int c[2000005],cnt[2000005];
int CC[2000005];
bool check(int x,int N){
	int div=N/x,rem=N%x;if(rem<=div)return true;return false;
}
int get(int N,int sz){
	return (N+sz)/(sz+1);
}
int solve(vector<int>&vec){
	for(int j=1;j<=n;j++)CC[j]=0;
	for(int i=0;i<vec.size();i++){
		for(int j=1;j<=vec[i];j++)if(check(j,vec[i])){
			CC[j]++;
		}
	}
//	cerr<<vec.size()<<" "<<CC[4]<<endl;
	int ans=0,sz=1;
	for(int i=n;i>=1;i--)if(CC[i]==vec.size()){sz=i;break;}
//	cerr<<"show:"<<sz<<endl;
	for(int i=0;i<vec.size();i++){
		ans+=get(vec[i],sz);
	}
	printf("%d\n",ans);
}
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++)scanf("%d",&c[i]);
		for(int i=1;i<=n;i++)cnt[i]=0;
		for(int i=1;i<=n;i++)cnt[c[i]]++;
		vector<int>vec;
		for(int i=1;i<=n;i++)if(cnt[i])vec.push_back(cnt[i]);
		solve(vec);
	}
	return 0;
}