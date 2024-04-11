/*
Though leaves are many , the root is one.
Through all the lying days of my youth
I swayed my leaves and flowers in the sun.
Now I may wither into the truth.
	  	  	- William Butler Yeats
*/
#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
#pragma GCC target("avx,tune=native")
#include<bits/stdc++.h>
#define int long long
#pragma comment(" -Wl,--stack=1024000000")
//#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
//using namespace __gnu_pbds;
const int inf=0x3f3f3f3f3f3f3f3f;
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
int n,k,sz;
pair<int,int>p[1000005];
vector<int>prime;
void init(int x){
	for(int i=2;i*i<=x;i++){
		if(x%i==0){
			while(x%i==0)x/=i;
			prime.push_back(i);
		}
	}
	if(x!=1)prime.push_back(x);
//	for(int i=0;i<prime.size();i++)cerr<<prime[i]<<" ";cerr<<endl;
}
map<vector<int>,vector<int> >Mask;
vector<int>get_mask(int x){
	vector<int>ret;
	for(int i=0;i<prime.size();i++){
		int now=1;
		while(x%prime[i]==0){
			now*=prime[i];x/=prime[i];
		}
		ret.push_back(now);
	}
//	for(int i=0;i<ret.size();i++)cerr<<ret[i]<<" ";cerr<<endl;
	return ret;
}
vector<pair<int,int> >best[2222];
int dp[22][2222],tdp[22][2222];
vector<pair<int,int> >obj[1000005];//<mask,value>
void transform(vector<pair<int,int> >&obj){
	vector<pair<pair<int,int>,int> >upd;
	for(int i=0;i<obj.size();i++){
		const int ori=((1<<sz)-1)^obj[i].first;
		for(register int M=ori;M;M=M-1&ori){
			for(register int j=0;j<sz;j++){
//				cerr<<M<<" "<<obj[i].first<<" "<<obj[i].second<<endl;
				if(dp[j][M]+obj[i].second<tdp[j+1][M|obj[i].first]){
					tdp[j+1][M|obj[i].first]=dp[j][M]+obj[i].second;
					upd.push_back(make_pair(make_pair(j+1,M|obj[i].first),dp[j][M]+obj[i].second));
				}
			}
		}
		for(register int j=0;j<sz;j++){
			const int M=0;
			if(dp[j][M]+obj[i].second<tdp[j+1][M|obj[i].first]){
				tdp[j+1][M|obj[i].first]=dp[j][M]+obj[i].second;
				upd.push_back(make_pair(make_pair(j+1,M|obj[i].first),dp[j][M]+obj[i].second));
			}
		}
	}
	for(int i=0;i<upd.size();i++){
		dp[upd[i].first.first][upd[i].first.second]=upd[i].second;
	}
}
int gcd(int a,int b){
	while(a&&b){
		if(a>b)a%=b;
		else b%=a;
	}
	return a+b;
}
signed main(){
	scanf("%I64d%I64d",&n,&k);
	for(int i=0;i<n;i++)scanf("%I64d",&p[i].second);
	for(int i=0;i<n;i++)scanf("%I64d",&p[i].first);
	sort(p,p+n);int Gcd=0;
	for(int i=0;i<n;i++)Gcd=gcd(p[i].second,Gcd);
	init(Gcd);sz=prime.size();
	for(int i=0;i<n;i++){
		vector<int>mask=get_mask(p[i].second);
		if(Mask[mask].size()<sz){
			Mask[mask].push_back(p[i].first);
		}
	}
	vector<pair<int,vector<int> > >V;
	for(map<vector<int>,vector<int> >::iterator itr=Mask.begin();itr!=Mask.end();itr++){
		for(int j=0;j<itr->second.size();j++)V.push_back(make_pair(itr->second[j],itr->first));
	}
	sort(V.begin(),V.end());
	for(int i=1;i<(1<<sz);i++){
		for(int j=0;j<V.size();j++){
			const vector<int> &v=V[j].second;
			register int val=1;
			for(int l=0;l<sz;l++){
				if(i&(1<<l))val*=v[l];
			}
			if(val<=k){
				best[i].push_back(make_pair(V[j].first,j));
				if(best[i].size()==sz)break;
			}
		}
	}
	for(int i=1;i<(1<<sz);i++){
		for(int j=0;j<best[i].size();j++){
			obj[best[i][j].second].push_back(make_pair(i,best[i][j].first)); 
		}
	}
	memset(dp,inf,sizeof dp);dp[0][0]=0;memcpy(tdp,dp,sizeof tdp);
	for(int i=0;i<V.size();i++)transform(obj[i]);
	int ans=1e18;
	for(int i=0;i<=sz;i++){
		if(dp[i][(1<<sz)-1]<inf){
			ans=min(ans,dp[i][(1<<sz)-1]*i);
		}
	}
	cout<<(ans==1e18?-1ll:ans)<<endl;
	return 0;
}