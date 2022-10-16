/*
Though leaves are many , the root is one.
Through all the lying days of my youth
I swayed my leaves and flowers in the sun.
Now I may wither into the truth.
	  	  	- William Butler Yeats
*/
//#pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline") //Optimization flags
//#pragma GCC option("arch=native","tune=native","no-zero-upper") //Enable AVX
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
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
inline int Rand(){return rand()*32768+rand();}
int n;
int a[100005];
int one[100005];
vector<int>occ[55];
int main(){
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	int tot=n+1;
	set<pair<int,int> >ans; 
	for(int i=n;i>=1;i--){
		if(a[i]==1){
			tot--;one[i]=tot;
			ans.insert(make_pair(tot,i));
			occ[1].push_back(i);
		}
		if(a[i]==2){
			if(!occ[1].size()){
				puts("-1");
				return 0;
			}
			int x=occ[1].back();
			one[i]=one[x];
			ans.insert(make_pair(one[x],i));
			occ[1].pop_back();
			occ[0].push_back(i);
		}
		if(a[i]==3){
			if(!occ[1].size()&&!occ[0].size()){
				puts("-1");
				return 0;
			}
			tot--;one[i]=tot;
			int x=occ[0].size()?occ[0].back():occ[1].back();
			ans.insert(make_pair(tot,i));
			ans.insert(make_pair(tot,x));
			occ[0].size()?occ[0].pop_back():occ[1].pop_back();
			occ[0].push_back(i);
		}
	}
	cout<<ans.size()<<endl;
	for(auto p:ans)cout<<p.first<<" "<<p.second<<endl;
	return 0;
}