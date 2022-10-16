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
int n;
pair<int,char>p[200005];
signed main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>p[i].first>>p[i].second;
	}
	sort(p+1,p+n+1);
	vector<int>vv;
	for(int i=1;i<=n;i++){
		if(p[i].second=='P'){
			vv.push_back(i);
		}
	}
	int ans=0;
	if(!vv.size()){
		int mx=-inf,mn=inf;
		for(int i=1;i<=n;i++){
			if(p[i].second=='R')mx=max(mx,p[i].first),mn=min(mn,p[i].first);
		}
		if(mx!=-inf)ans+=mx-mn;mx=-inf;mn=inf;
		for(int i=1;i<=n;i++){
			if(p[i].second=='B')mx=max(mx,p[i].first),mn=min(mn,p[i].first);
		}
		if(mx!=-inf)ans+=mx-mn;
		cout<<ans<<endl;
		return 0;
	}
	int r=inf,b=inf;
	for(int i=1;i<vv[0];i++){
		if(p[i].second=='B')b=min(b,p[i].first);
		else r=min(r,p[i].first);
	}
	if(r<inf)ans+=p[vv[0]].first-r;
	if(b<inf)ans+=p[vv[0]].first-b;
	r=-inf;b=-inf;
	for(int i=vv.back()+1;i<=n;i++){
		if(p[i].second=='B')b=max(b,p[i].first);
		else r=max(r,p[i].first);
	}
	if(r>-inf)ans+=r-p[vv.back()].first;
	if(b>-inf)ans+=b-p[vv.back()].first;
	for(int i=0;i+1<vv.size();i++){
		vector<int>R(1,p[vv[i]].first),B(1,p[vv[i]].first);int res=0;
		for(int j=vv[i]+1;j<vv[i+1];j++){
			if(p[j].second=='R')R.push_back(p[j].first);
			else B.push_back(p[j].first);
		}
		R.push_back(p[vv[i+1]].first);B.push_back(p[vv[i+1]].first);
		res+=p[vv[i+1]].first-p[vv[i]].first;res*=2ll;
		int add=vv[i+1]-vv[i];
		int sub=0,cur=p[vv[i+1]].first-p[vv[i]].first;cur*=3ll; 
		for(int t=0;t+1<R.size();t++){
			sub=max(sub,R[t+1]-R[t]);
		}
		cur-=sub;sub=0;
		for(int t=0;t+1<B.size();t++){
			sub=max(sub,B[t+1]-B[t]);
		}
		cur-=sub;
		res=min(res,cur);
		ans+=res;
//		cerr<<i<<" "<<res<<endl;
	}
	cout<<ans<<endl;
	return 0;
}