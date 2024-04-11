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
int n,sz=0;
int to[1000005],ans[1000005];
bool vis[1000005];
vector<int>id[1000005];
void dfs(int x){
	vis[x]=1;sz++;
	if(!vis[to[x]])dfs(to[x]);
}
vector<int>all;
bool used[1000005];
void get_v(int x){
	used[x]=1;all.push_back(x);
	if(!used[to[x]])get_v(to[x]);
}
int pos[1000005],val[1000005];
void solve1(int x){
	all.clear();
	get_v(x);
	for(int i=0;i<all.size();i++){
		if(i+i<all.size()){
			int v=i+i+1;
			pos[v]=i;val[i]=v;
		}else{
			int v=i-(int)(all.size())/2;v*=2;
			pos[v]=i;val[i]=v;
		}
	}
	for(int i=0;i<all.size();i++){
		ans[all[i]]=all[pos[(val[i]%(int)all.size())+1]];
//		cerr<<all[i]<<" --> "<<all[pos[(val[i]%(int)all.size())+1]]<<endl;
	}
}
vector<int>v1,v2;
void solve2(int x,int y){
	all.clear();get_v(x);v1=all;
	all.clear();get_v(y);v2=all;
	for(int i=0;i<v1.size();i++){
//		cerr<<i<<" "<<v1[i]<<endl;
		ans[v1[i]]=v2[(i+1)%(int)v2.size()];
	}
	for(int i=0;i<v2.size();i++){
//		cerr<<i<<" "<<v2[i]<<endl;
		ans[v2[i]]=v1[i];
	}
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&to[i]);
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			sz=0;
			dfs(i);
			id[sz].push_back(i);
		}
	}
	for(int i=1;i<=n;i++){
		if(!id[i].size())continue;
		if(i&1){
			for(int j=0;j<id[i].size();j++){
				solve1(id[i][j]);
			}
		}else{
			if(id[i].size()%2){
				puts("-1");
				return 0;
			}
			for(int j=0;j<id[i].size();j+=2){
				solve2(id[i][j],id[i][j+1]);
			}
		}
	}
	for(int i=1;i<=n;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}