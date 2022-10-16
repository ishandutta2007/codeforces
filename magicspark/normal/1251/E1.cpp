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
int t,n;
vector<int>m[200005];
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(int i=0;i<n;i++)m[i].clear();
		ll sum=0,ans=1e18,now=0;
		for(int i=1;i<=n;i++){
			int a,b;scanf("%d%d",&a,&b);
			m[a].push_back(b);sum+=b;
		}
		multiset<int>S;
		for(int i=n-1;i>=0;i--){
			for(int j=0;j<m[i].size();j++){
				S.insert(m[i][j]);now+=m[i][j];
			}
			//at least i people was chosen
			//pq should have size no more than (n-i)
			while(S.size()>n-i){
				int x=*S.begin();now-=x;S.erase(S.begin());
			}
			ans=min(ans,sum-now);
		}
		printf("%I64d\n",ans);
	}
	return 0;
}