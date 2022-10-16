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
int n,k;
int a[100005];
int func(int x,int y){
	return x-3ll*y*y+3ll*y-1ll;
}
pair<int,int>get_lower(int aa,int lmt){
	int l=0,r=aa+1;
	while(r-l>1){
		int mid=(l+r)/2;
		if(func(aa,mid)>=lmt)l=mid;
		else r=mid;
	}
	return make_pair(l,func(aa,l)==lmt?1:0);
}
int calc(int x){
	int ret=0;
	for(int i=1;i<=n;i++){
		ret+=get_lower(a[i],x).first;
	}
//	cerr<<x<<" "<<ret<<endl;
	return ret;
}
int b[200005];
void solve(int v){
	vector<int>vec;int cur=0;
	for(int i=1;i<=n;i++){
		auto got=get_lower(a[i],v);
		if(got.second)vec.push_back(i);
		b[i]=got.first;cur+=got.first;
	}
//	cerr<<cur<<" "<<k<<" "<<vec.size()<<endl;
	while(cur>k){
		b[vec.back()]--;
		vec.pop_back();
		cur--;
	}
	for(int i=1;i<=n;i++)cout<<b[i]<<" ";
}
signed main(){
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>a[i];
	int l=-4e18,r=4e18;
	while(r-l>1){
		int mid=(l+r)/2;
		if(calc(mid)>=k)l=mid;
		else r=mid;
	}
	solve(l);
	return 0;
}