/*
Though leaves are many , the root is one.
Through all the lying days of my youth
I swayed my leaves and flowers in the sun.
Now I may wither into the truth.
*/
//#pragma GCC optimize("Ofast,no-stack-protector")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
//#pragma GCC target("avx,tune=native")
#include<bits/stdc++.h>
//#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
//using namespace __gnu_pbds;
const int inf=0x3f3f3f3f;
const double eps=1e-6;
const int mod=1000000007;
typedef long long ll;
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
inline string getstr(string &s,int l,int r){string ret="";for(int i=l;i<=r;i++)ret.push_back(s[i]);return ret;}
int modpow(int x,int y,int md=mod){if(y==0)return 1;int ret=modpow(x,y>>1,md);ret=(ll)ret*ret%md;if(y&1)ret=(ll)ret*x%md;return ret;}
int n,q;
int a[200005],last[200005];
int low[200005],to[200005];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	cin>>q;
	memset(low,-1,sizeof low);
	for(int test=1;test<=q;test++){
		int type;cin>>type;
		if(type==1){
			int x,v;cin>>x>>v;
			a[x]=v;last[x]=test;
		}else{
			cin>>low[test];
		}
	}
	low[q+1]=-inf;to[q+1]=-inf;
	for(int i=q;i>=0;i--){
		if(~low[i]){
			to[i]=max(to[i+1],low[i]);
		}else{
			to[i]=to[i+1];
		}
	}
	for(int i=1;i<=n;i++){
		a[i]=max(a[i],to[last[i]]);
		cout<<a[i]<<" ";
	}
	return 0;
}