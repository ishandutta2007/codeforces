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
set<int>mx,mn;
int n;
int a[1000005];
vector<pair<int,int> >Mx,Mn;
vector<int>buc[1000005];
int main(){
	scanf("%d",&n);
	mx.insert(0);mn.insert(0);
	mx.insert(n+1);mn.insert(n+1);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		mx.insert(i);mn.insert(i);
		buc[a[i]].push_back(i);
	}
	for(int i=1e6;i>=1;i--){
		for(int j=0;j<buc[i].size();j++){
			Mx.push_back(make_pair(i,buc[i][j]));
		}
	}
	for(int i=1;i<=1e6;i++){
		for(int j=0;j<buc[i].size();j++){
			Mn.push_back(make_pair(i,buc[i][j]));
		}
	}
	ll ans=0;
	for(int i=0;i<Mx.size();i++){
		set<int>::iterator itr=mx.find(Mx[i].second);
		ans-=(ll)(Mx[i].second-*prev(itr))*(ll)(*next(itr)-Mx[i].second)*(ll)(Mx[i].first);
		mx.erase(itr);
	}
	for(int i=0;i<Mn.size();i++){
		set<int>::iterator itr=mn.find(Mn[i].second);
		ans+=(ll)(Mn[i].second-*prev(itr))*(ll)(*next(itr)-Mn[i].second)*(ll)(Mn[i].first);
		mn.erase(itr);
	}
	cout<<ans<<endl;
	return 0;
}