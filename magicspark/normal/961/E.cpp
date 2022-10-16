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
int modpow(int x,int y,int md=mod){int ret=1;do{if(y&1)ret=(ll)ret*x%md;x=(ll)x*x%md;}while(y>>=1);return ret;}
struct bit{
	int arr[200005],n=2e5+2;
	void add(int x,int y){
		int i;
		for(i=x;i<=n;i+=(i&-i)){
			arr[i]+=y;
		}
	}
	int query(int x){
		int i,ans=0;
		for(i=x;i;i-=(i&(-i))){
			ans+=arr[i];
		}
		return ans;
	}
}bit;
int n,a[200005];
vector<int>v[200005];
int main(){
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i],a[i]=min(a[i],n);
	for(int i=1;i<=n;i++)bit.add(i,1);
	for(int i=1;i<=n;i++)v[a[i]].push_back(i);
	ll ans=0;
	for(int i=1;i<=n;i++){
		if(bit.query(i)-bit.query(i-1)==1)bit.add(i,-1);
		ans+=bit.query(a[i]);
		for(auto x:v[i])if(x>i)bit.add(x,-1);
	}
	cout<<ans<<endl;
	return 0;
}