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
#pragma comment(" -Wl,--stack=1024000000")
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
int t,n;ll s;
int l[200005],r[200005];
bool check(int x){
	int need=(n+1)/2;
	ll cost=0,cnt=0;
	for(int i=1;i<=n;i++){
		if(l[i]>=x){
			cost+=l[i];cnt++;
		}
		if(r[i]<x){
			cost+=l[i];
		}
	}
	vector<pair<int,int> >hop;
	for(int i=1;i<=n;i++){
		if(l[i]<x&&r[i]>=x){
			hop.push_back(make_pair(l[i],r[i]));
		}
	}
	sort(hop.begin(),hop.end());
	reverse(hop.begin(),hop.end());
	for(int i=0;i<hop.size();i++){
		if(cnt<need){
			cost+=x;cnt++;
		}else{
			cost+=hop[i].first;
		}
	}
	return cnt>=need&&cost<=s;
}
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d%I64d",&n,&s);
		while(n%2==0);
		for(int i=1;i<=n;i++)scanf("%d%d",&l[i],&r[i]);
		int L=-1,R=1e9+5;
		while(R-L>1){
			int mid=(L+R)/2;
			if(check(mid))L=mid;
			else R=mid;
		}
		printf("%d\n",L);
	}
	return 0;
}