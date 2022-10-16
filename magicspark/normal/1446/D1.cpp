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
int n,pos;
int a[200005],val[200005],cnt[200005][105];
vector<int>occ[400005];
int solve(int x){
	memset(val,0,sizeof val);
	for(int i=1;i<=n;i++){
		if(a[i]==pos)val[i]=1;
		if(a[i]==x)val[i]=-1;
	}
	int ret=0;
	for(int i=0;i<400005;i++)occ[i].clear();
	for(int i=0;i<=n;i++)val[i]+=val[i-1],occ[val[i]+200000].push_back(i);
	for(int i=0;i<400005;i++)if(occ[i].size()>=2)ret=max(ret,occ[i].back()-occ[i][0]);
	return ret;
}
int main(){
	ios::sync_with_stdio(0);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		memcpy(cnt[i],cnt[i-1],sizeof cnt[i]);
		cnt[i][a[i]]++;
	}
	int mx=*max_element(cnt[n]+1,cnt[n]+101);
	int tot=0;
	for(int i=1;i<=100;i++){
		if(cnt[n][i]==mx)tot++;
	}
	if(tot>=2){
		cout<<n<<endl;
		return 0;
	}
	for(int i=1;i<=100;i++){
		if(cnt[n][i]==mx)pos=i;
	}
	int ans=0;
	for(int i=1;i<=100;i++){
		if(i!=pos)ans=max(ans,solve(i));
	}
	cout<<ans<<endl;
	return 0;
}