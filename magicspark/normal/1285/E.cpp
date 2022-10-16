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
int modpow(int x,int y,int md=mod){if(y==0)return 1;int ret=modpow(x,y>>1,md);ret=(ll)ret*ret%md;if(y&1)ret=(ll)ret*x%md;return ret;}
int T,n;
map<int,int>mp;
int l[200005],r[200005];
vector<pair<int,int> >v[800005];
int has[800005],cnt[200005];
int main(){
	cin>>T;
	for(int t=1;t<=T;t++){
		cin>>n;
//		n=10;
		for(int i=1;i<=n;i++){
			cin>>l[i]>>r[i];
//			l[i]=rand();r[i]=max(rand(),l[i]);
		}
		mp.clear();
		for(int i=1;i<=n;i++){
			mp[l[i]];mp[r[i]];
			cnt[i]=0;
		}
		int now=0;
		for(auto &p:mp)p.second=++now;
		for(int i=1;i<=n;i++){
//			cerr<<mp[l[i]]<<" "<<mp[r[i]]<<endl;
			l[i]=mp[l[i]]*2;
			r[i]=mp[r[i]]*2;
		}
		now*=2;
		for(int i=0;i<=now;i++)v[i].clear();
		set<pair<int,int> >s;
		for(int i=1;i<=n;i++){
			v[l[i]].push_back(make_pair(r[i],i));
		}
		int ans=0;
		has[0]=0;has[now+1]=-1;int pre=0;
		for(int i=1;i<=now;i++){
			for(auto p:v[i]){
				s.insert(p);
			}
			//state of i
			if(s.empty())has[i]=-1;
			if(s.size()==1)has[i]=s.begin()->second;
			if(s.size()>1)has[i]=inf;
			while(!s.empty()&&s.begin()->first==i)s.erase(s.begin());
			cerr<<i<<" "<<has[i]<<endl;
		}
		for(int i=2;i<=now+1;i++){
			if(has[i]==-1&&has[i-1]!=-1)ans++;
		}
		int i;
		vector<int>all;
		for(i=1;i<=now;){
			if(has[i]==inf){
				i++;continue;
			}
			if(has[i]==-1){
				i++;continue;
			}
			int r=i;
			while(r<=now&&has[r]==has[i])r++;
			r--;
			if(has[i-1]==inf&&has[r+1]==inf)cnt[has[r]]++;
			if(has[i-1]!=inf&&has[r+1]!=inf)cnt[has[r]]=-1;
			i=r+1;
		}
//		cerr<<"show vector:";
//		for(int i=0;i<all.size();i++)cerr<<all[i]<<" ";cerr<<endl;
//		cerr<<"show answer:"<<ans<<endl;
		int res=ans-1;
		for(int i=1;i<=n;i++){
//			cerr<<i<<" "<<cnt[i]<<endl;
			res=max(res,ans+cnt[i]);
		}
		cout<<res<<endl;
//		system("pause");
	}
	return 0;
}