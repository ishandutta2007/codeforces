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
int T,n,k,a[100005];
bool hv[100005];
int calc(int x){
	int tot=0;
	for(int i=0;i<x;i++)if(!hv[i])tot++;
//	cerr<<x<<" "<<tot<<" "<<k<<endl;
	if(tot>k)return inf;
	map<int,int>cnt;
	for(int i=1;i<=n;i++)if(a[i]>=x)cnt[a[i]]++;
	int s=x,cur=k;
	vector<int>all;
	for(auto p:cnt){
		s++;
		if(p.first>x)all.push_back(p.second);
	}
	sort(all.begin(),all.end());
	for(int i=0;i<all.size();i++){
		cur-=all[i];if(cur<0)break;s--;
	}
//	cerr<<x<<" "<<s-x<<endl;
	return s-x;
}
int main(){
	ios::sync_with_stdio(0);
	cin>>T;
	while(T--){
		memset(hv,0,sizeof hv);
		cin>>n>>k;
		for(int i=1;i<=n;i++)cin>>a[i];
		for(int i=1;i<=n;i++)if(a[i]<=1e5+3)hv[a[i]]=1;
		sort(a+1,a+n+1);
		int l=0,r=n+5;
		while(r-l>5){
			int mid=(l+r)/2;
//			cerr<<mid<<" "<<calc(mid)<<endl;
			if(calc(mid)==inf)r=mid;
			else l=mid;
//			cerr<<l<<" "<<r<<endl;
		}
		int ans=inf;
		for(int i=l;i<=r;i++)ans=min(ans,calc(i));
		cout<<ans<<endl;
	}
	return 0;
}