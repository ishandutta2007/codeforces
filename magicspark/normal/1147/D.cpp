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
#define int long long
//#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
//using namespace __gnu_pbds;
const int inf=0x3f3f3f3f;
const double eps=1e-6;
const int mod=998244353;
typedef long long ll;
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
inline string getstr(string &s,int l,int r){string ret="";for(int i=l;i<=r;i++)ret.push_back(s[i]);return ret;}
int modpow(int x,int y,int md=mod){if(y==0)return 1;int ret=modpow(x,y>>1,md);ret=(ll)ret*ret%md;if(y&1)ret=(ll)ret*x%md;return ret;}
string s;
vector<pair<int,int> >g[2005];//to,xor
int value[2005];
int LEN=0;
bool error=0;
void add_edge(int x,int y,int cost){
	g[x].push_back(make_pair(y,cost));
	g[y].push_back(make_pair(x,cost));
}
void dfs(int x){
	if(error)return;
	for(auto p:g[x]){
		if(~value[p.first]&&value[p.first]!=value[x]^p.second)error=1;
		if(error)return;
		if(~value[p.first])continue;
		value[p.first]=value[x]^p.second;
		dfs(p.first);
	}
}
int calc(int len){
    LEN=len;
	memset(value,-1,sizeof value);
	int Maxa=(len)/2;
	int Maxb=((int)s.size()-1)/2;
	swap(Maxa,Maxb);
	for(int i=0;i<=2002;i++)g[i].clear();
	value[0]=1;value[1001]=1;
	for(int i=0;i<s.size();i++){
		if(s[i]=='?')continue;
		int posa=(i<=Maxa?i:((int)s.size()-i-1));
		int posb=(i<=Maxb?i:(len-i));
		if(i>len){
		    if(~value[posa]&&value[posa]!=s[i]-'0')return 0;
		    value[posa]=s[i]-'0';
		    continue;
		}
		add_edge(posa,posb+1001,s[i]-'0');
	}
	int ret=1;error=0;
	for(int i=1;i<=2002;i++){
	    if(~value[i])dfs(i);
	}
	for(int i=1;i<=2002;i++){
		if(((0<=i&&i<=Maxa)||(1001<=i&&i<=1001+Maxb))&&value[i]==-1){
			value[i]=0;
			(ret*=2)%=mod;
			dfs(i);
		}
		if(error)return 0;
	}
	return ret;
}
signed main(){
	cin>>s;reverse(s.begin(),s.end());
	int ans=0;
	for(int len=0;len<s.size();len++){
//	    cout<<len<<" "<<calc(len)<<endl;
		(ans+=calc(len))%=mod;
	}
	cout<<ans<<endl;
	return 0;
}