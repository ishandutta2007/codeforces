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
int n,len,m,t;
int a[200005];
int l[200005],r[200005],d[200005];
vector<pair<int,int> >tr[200005];
int calc(int x){
	int cost=len,to=0;
	for(int i=0;i<=len;i++){
		to=max(to,i-1);
		int mx=to;
		for(auto p:tr[i]){
			if(p.second>x)mx=max(mx,p.first);
		}
		cost+=(mx-to)*2;
		to=mx;
	}
	return cost;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>len>>m>>t;len++;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=m;i++)cin>>l[i]>>r[i]>>d[i],tr[l[i]].push_back(make_pair(r[i],d[i]));
	int L=0,R=2e5+5;
	while(R-L>1){
		int mid=(L+R)/2;
		if(calc(mid)<=t)R=mid;
		else L=mid;
	}
	int tot=0;
	for(int i=1;i<=n;i++)if(a[i]>=R)tot++;
	cout<<tot<<endl;
	return 0;
}