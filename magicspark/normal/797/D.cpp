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
//#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
//using namespace __gnu_pbds;
const int inf=0x3f3f3f3f;
const double eps=1e-6;
const int mod=1000000007;
typedef long long ll;
#ifndef LOCAL
#define cerr if(0)cout
#endif
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
inline string getstr(string &s,int l,int r){string ret="";for(int i=l;i<=r;i++)ret.push_back(s[i]);return ret;}
int modpow(int x,int y,int md=mod){if(y==0)return 1;int ret=modpow(x,y>>1,md);ret=(ll)ret*ret%md;if(y&1)ret=(ll)ret*x%md;return ret;}
int n;
int l[100005],r[100005],v[100005];
set<int>can_find;
void dfs(int x,int L,int R){
	cerr<<x<<" "<<L<<" "<<R<<endl;
	if(L>R)return;
	if(x==-1)return;
	if(L<=v[x]&&v[x]<=R){
		can_find.insert(v[x]);
	}
	dfs(l[x],L,min(v[x]-1,R));
	dfs(r[x],max(L,v[x]+1),R);
}
int cnt[100005];
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>v[i]>>l[i]>>r[i];
		if(~l[i])cnt[l[i]]++;
		if(~r[i])cnt[r[i]]++;
	}
	int root=-1;
	for(int i=1;i<=n;i++)if(!cnt[i])root=i;
	dfs(root,0,1e9);int ans=0;
	for(int i=1;i<=n;i++){
		if(!can_find.count(v[i])){
			ans++;
		}
	}
	cout<<ans<<endl;
	return 0;
}