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
int n,m;
string s[22];
int a[22][22];
int dp[1<<20];
int cnt[30];
inline void upd(int &x,int y){
	if(y<x)x=y;
}
int main(){
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>s[i];s[i]=" "+s[i];
	}
	for(int i=0;i<n;i++){
		for(int j=1;j<=m;j++){
			cin>>a[i][j];
		}
	}
	memset(dp,inf,sizeof dp);
	dp[0]=0;
	for(int i=1;i<=m;i++){
		for(int mask=0;mask<(1<<n);mask++){
			for(int j=0;j<n;j++){
				if(mask&(1<<j))continue;
				upd(dp[mask|(1<<j)],dp[mask]+a[j][i]);
			}
		}
		vector<pair<int,int> >trans;//mask,cost
		for(int j=0;j<26;j++){
			vector<int>values;
			pair<int,int>p;
			for(int _=0;_<n;_++){
				if(s[_][i]=='a'+j){
					p.first|=(1<<_);
					values.push_back(a[_][i]);
				}
			}
			sort(values.begin(),values.end());
			for(int i=0;i+1<values.size();i++){
				p.second+=values[i];
			}
			trans.push_back(p);
		}
		for(int mask=0;mask<(1<<n);mask++){
			for(auto p:trans){
				upd(dp[mask|p.first],dp[mask]+p.second);
			}
		}
	}
	cout<<dp[(1<<n)-1]<<endl;
	return 0;
}