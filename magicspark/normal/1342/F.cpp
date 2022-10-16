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
const double eps=1e-9;
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
int T,n,a[22],ans;
int sum[1<<15],dp[18][1<<15][15];
pair<int,int>pre[18][1<<15][15];
bool check(){
	int ret=inf;
	for(int i=0;i<n;i++)ret=min(ret,dp[ans][(1<<n)-1][i]);
	return ret<inf;
}
void calc(){
//	cerr<<"show: "<<ans<<endl;//system("pause"); 
	auto f=dp[ans],g=dp[ans+1];auto h=pre[ans+1];
	for(int i=0;i<(1<<n);i++)for(int j=0;j<n;j++)if(f[i][j]!=inf){
//		cerr<<i<<" "<<j<<" "<<f[i][j]<<endl;
		int full=(1<<n)-1-i;
		for(int mask=full;mask;mask=(mask-1)&full){
			int pos=j;
			while(pos<n&&(!(mask&(1<<pos))))pos++;
			if(pos==n||sum[mask]<=f[i][j])continue;
			g[i|mask][pos]=min(g[i|mask][pos],sum[mask]);
			if(g[i|mask][pos]==sum[mask])h[i|mask][pos]=make_pair(i,j);
		}
	}
}
int main(){
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=0;i<n;i++)cin>>a[i],sum[1<<i]=a[i];
		for(int lvl=1;lvl<=n+2;lvl++)for(int i=0;i<(1<<n);i++)for(int j=0;j<n;j++)dp[lvl][i][j]=inf;
		for(int i=1;i<(1<<n);i++)sum[i]=sum[i-(i&-i)]+sum[i&-i];
		for(int i=1;i<(1<<n);i++){
			int pos=0;
			while(!(i&(1<<pos)))pos++;
			dp[1][i][pos]=sum[i];
		}
		ans=1;
		while(check()){
			calc();ans++;
		}
		int f1=ans-1,f2=(1<<n)-1,f3;
		for(int i=0;i<n;i++)if(dp[f1][f2][i]<inf)f3=i;
		vector<pair<int,int> >masks;
		while(f1>1){
			masks.push_back(make_pair(f2^pre[f1][f2][f3].first,f3));
			auto p=pre[f1][f2][f3];
			f2=p.first;f3=p.second;f1--;
		}
		masks.push_back(make_pair(f2,f3));
		vector<int>cur;
		vector<pair<int,int> >fans;
		for(int i=0;i<n;i++)cur.push_back(i);
		while(masks.size()){
			auto p=masks.back();
			cerr<<p.first<<" "<<p.second<<endl;
			bool vis=0;
			int pos=-1;
			for(int i=0;i<cur.size();i++)if(cur[i]==p.second)pos=i; 
			for(int i=0;i<cur.size();i++){
				if(i!=pos&&(p.first&(1<<cur[i]))){
					fans.push_back(make_pair(pos,i));
					cur.erase(cur.begin()+i);vis=1;break;
				}
			}
			if(!vis)masks.pop_back();
		}
		cout<<fans.size()<<endl;
		for(auto p:fans)cout<<p.second+1<<" "<<p.first+1<<endl;
	}
	return 0;
}