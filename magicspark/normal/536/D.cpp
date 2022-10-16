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
#define int long long
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
int n,m,s,t,val[2005];
vector<int>order,os,ot;
vector<int>ds,dt;
vector<pair<int,int> >g[2005];
int dist[2005];
void dijkstra(int st){
	order.clear();
	memset(dist,inf,sizeof dist);
	set<pair<int,int> >S;
	S.insert(make_pair(0,st));dist[st]=0;
	while(!S.empty()){
		int x=S.begin()->second,len=S.begin()->first;
		S.erase(S.begin());
		if(len!=dist[x])continue;
		order.push_back(x);
		for(int i=0;i<g[x].size();i++){
			int to=g[x][i].first,cost=g[x][i].second;
			if(dist[to]>len+cost){
				dist[to]=len+cost;
				S.insert(make_pair(dist[to],to));
			}
		}
	}
}
//<s,t>
int dps[2005][2005],dpt[2005][2005],max_s[2005][2005],max_t[2005][2005],value_s[2005][2005],value_t[2005][2005];
int ranks[2005],rankt[2005];
int next_s[2005][2005],next_t[2005][2005];
bool occur_s[2005][2005],occur_t[2005][2005];
bool wrong_state[2005][2005];
void init(){
	for(int i=0;i<os.size();i++)ranks[os[i]]=i;
	for(int i=0;i<ot.size();i++)rankt[ot[i]]=i;
	for(int j=0;j<=n;j++){
		for(int i=0;i<j;i++)occur_t[ot[i]][j]=1;
		next_s[n][j]=n;
		for(int i=n-1,p=n;i>=0;i--){
			if(!occur_t[os[i]][j])p=i;
			next_s[i][j]=p;
			value_s[i][j]=value_s[i+1][j]+(p==i?val[os[i]]:0ll);
		}
	}
	for(int i=0;i<=n;i++){
		for(int j=0;j<i;j++)occur_s[i][os[j]]=1;
		next_t[i][n]=n;
		for(int j=n-1,p=n;j>=0;j--){
			if(!occur_s[i][ot[j]])p=j;
			next_t[i][j]=p;
			value_t[i][j]=value_t[i][j+1]+(p==j?val[ot[j]]:0ll);
		}
	}
}
void update(int x,int y){
	if(wrong_state[x][y]){
		max_t[x][y]=max_t[x][y+1]+value_t[x][y]-value_t[x][y+1];
		max_s[x][y]=max_s[x+1][y]+value_s[x][y]-value_s[x+1][y];
	}else{
		max_t[x][y]=max(max_t[x][y+1]+value_t[x][y]-value_t[x][y+1],-dps[x][y]);
		max_s[x][y]=max(max_s[x+1][y]+value_s[x][y]-value_s[x+1][y],-dpt[x][y]);
	}
}
bool used[2005];
void get_wrong_states(){
	memset(used,0,sizeof used);
	for(int i=0;i<n;i++){
		if(used[i])continue;
		int r=i;
		while(r<n&&ds[r]==ds[i]){
			used[r]=1;r++;
		}
		r--;
		//range solve [i,r]
		for(int j=0;j<=n;j++){
			int pos=r;
//			while(pos>=i&&occur_t[j][os[pos]])pos--;
			for(int w=i;w<pos;w++)wrong_state[w][j]=1;
		}
	}
	memset(used,0,sizeof used);
	for(int j=0;j<n;j++){
		if(used[j])continue;
		int r=j;
		while(r<n&&dt[r]==dt[j]){
			used[r]=1;r++;
		}
		r--;
		//range solve [i,r]
		for(int i=0;i<=n;i++){
			int pos=r;
//			while(pos>=j&&occur_s[i][ot[pos]])pos--;
			for(int w=j;w<pos;w++)wrong_state[i][w]=1;
		}
	}
}
void solve(){
	memset(max_s,0xf7,sizeof max_s);
	memset(max_t,0xf7,sizeof max_t);
	memset(dps,0xf7,sizeof dps);
	memset(dpt,0xf7,sizeof dpt);
	for(int i=n;i>=0;i--){
		for(int j=n;j>=0;j--){
			if(!wrong_state[i][j]){
				if(next_s[i][j]==n)dps[i][j]=0;
				else dps[i][j]=(value_s[i][j]-value_s[next_s[i][j]+1][j])+max_s[next_s[i][j]+1][j];
				if(next_t[i][j]==n)dpt[i][j]=0;
				else dpt[i][j]=(value_t[i][j]-value_t[i][next_t[i][j]+1])+max_t[i][next_t[i][j]+1];
			}else{
				cerr<<"wrong state "<<i<<" "<<j<<endl;
			}
			update(i,j);
		}
	}
	if(dps[0][0]>0)puts("Break a heart");
	if(dps[0][0]==0)puts("Flowers");
	if(dps[0][0]<0)puts("Cry");
}
signed main(){
	cin>>n>>m>>s>>t;s--;t--;
	for(int i=0;i<n;i++)cin>>val[i];
	for(int i=1;i<=m;i++){
		int x,y,z;cin>>x>>y>>z;x--;y--;
		g[x].push_back(make_pair(y,z));
		g[y].push_back(make_pair(x,z));
	}
	dijkstra(s);os=order;
	for(int i=0;i<n;i++)ds.push_back(dist[os[i]]); 
	dijkstra(t);ot=order;
	for(int i=0;i<n;i++)dt.push_back(dist[ot[i]]);
	init();
	get_wrong_states();
	solve();
	return 0;
}