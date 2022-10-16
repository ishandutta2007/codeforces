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
int T,n,tot;
map<pair<int,int>,int>mp;
pair<int,int>inv[600005];
vector<int>g[600005];
int f[200005][3];
int cnt[200005];
queue<int>Q;
void insert(int x,int y,int z,int ind){
	int &itr1=mp[make_pair(min(x,y),max(x,y))];
	int &itr2=mp[make_pair(min(x,z),max(x,z))];
	int &itr3=mp[make_pair(min(y,z),max(y,z))];
	if(!itr1)itr1=++tot;
	if(!itr2)itr2=++tot;
	if(!itr3)itr3=++tot;
	g[itr1].push_back(ind);
	g[itr2].push_back(ind);
	g[itr3].push_back(ind);
	inv[itr1]=make_pair(x,y);
	inv[itr2]=make_pair(x,z);
	inv[itr3]=make_pair(y,z);
}
int get_id(int x,int i,int j){
	return mp[make_pair(min(f[x][i],f[x][j]),max(f[x][i],f[x][j]))];
}
vector<int>G[200005];
bool used[200005];
void add_edge(int x,int y){
	G[x].push_back(y);
	G[y].push_back(x);
}
void dfs(int x){
	used[x]=1;cout<<x<<" ";
	for(auto to:G[x]){
		if(!used[to])dfs(to);
	}
}
int main(){
	cin>>T;
	while(T--){
		cin>>n;tot=0;mp.clear();
		for(int i=1;i<=n;i++)G[i].clear();
		for(int i=1;i<=n;i++)used[i]=0;
		for(int i=1;i<=n-2;i++){
			cin>>f[i][0]>>f[i][1]>>f[i][2];cnt[i]=3;
			insert(f[i][0],f[i][1],f[i][2],i);
		}
		for(int i=1;i<=tot;i++){
			if(g[i].size()==1){
				cnt[g[i][0]]--;add_edge(inv[i].first,inv[i].second);
				if(cnt[g[i][0]]==1)Q.push(g[i][0]);
			}
		}
		dfs(1);cout<<endl;
		while(!Q.empty()){
			int x=Q.front();Q.pop();cout<<x<<" ";
			for(int i=0;i<2;i++)for(int j=i+1;j<3;j++){
				auto del=g[get_id(x,i,j)].end();
				for(vector<int>::iterator itr=g[get_id(x,i,j)].begin();itr!=g[get_id(x,i,j)].end();itr++)if(x==*itr)del=itr;
				if(del!=g[get_id(x,i,j)].end())g[get_id(x,i,j)].erase(del);
				if(g[get_id(x,i,j)].size()==1){
					cnt[g[get_id(x,i,j)][0]]--;
					if(cnt[g[get_id(x,i,j)][0]]==1){
						Q.push(g[get_id(x,i,j)][0]);
					}
				}
			}
		}
		cout<<endl;
	}
	return 0;
}