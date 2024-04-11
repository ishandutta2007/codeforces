//#pragma GCC optimize("Ofast,no-stack-protector")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
//#pragma GCC target("avx,tune=native")
#include<bits/stdc++.h>
#define int long long
//#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
//using namespace __gnu_pbds;
const int inf=0x3f3f3f3f3f3f3f3f;
const double eps=1e-6;
const int mod=1000000007;
typedef long long ll;
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
inline string getstr(string &s,int l,int r){string ret="";for(int i=l;i<=r;i++)ret.push_back(s[i]);return ret;}
int modpow(int x,int y,int md=mod){if(y==0)return 1;int ret=modpow(x,y>>1,md);ret=(ll)ret*ret%md;if(y&1)ret=(ll)ret*x%md;return ret;}
int m,n;
const int big=314000000;
vector<int>from[100005];
struct edge{
	int st,deg;
	map<int,int>mp;
	int val;
}e[100005];
vector<edge>g[100005];
int dist[100005];
set<pair<int,int> >S;
int Min[100005],Max[100005];
set<int>all;
int dfs(int x,int from=-1){
	if(Max[x]!=-233&&x!=from)return Max[x];
	int qaq=Max[x];
	if(all.count(x)){
		if(qaq!=-2&&qaq!=-233&&from!=x){
			cout<<"error1:"<<x<<" "<<from<<" "<<qaq<<" "<<-2<<endl;
		}
		Max[x]=-2;
		return -2;
	}
	all.insert(x);
	for(auto E:g[x]){
		int now=0,ok=1;
		for(auto p:E.mp){
			if(Max[p.first]==-1){
				ok=0;
			}
		}
		if(!ok)continue;
		for(auto p:E.mp){
			int tmp=dfs(p.first,x);
			if(tmp==-2){
				now=-2;
				break;
			}
			tmp*=p.second;
			now+=tmp;
			now=min(now,big);
		}
		if(now==-2){
			if(qaq!=-2&&qaq!=-233&&from!=x){
				cout<<"error2:"<<x<<" "<<qaq<<" "<<-2<<endl;
			}
			Max[x]=-2;all.erase(all.find(x));
			return Max[x];
		}
		Max[x]=max(Max[x],min(big,now+E.val));
	}
	all.erase(all.find(x));
	return Max[x];
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>m>>n;
	for(int i=1;i<=m;i++){
		cin>>e[i].st;
		int _;cin>>_;
		while(_--){
			int x;cin>>x;
			if(x==-1){
				e[i].val++;
			}else{
				e[i].deg++;
				e[i].mp[x]++;
				from[x].push_back(i);
			}
		}
		g[e[i].st].push_back(e[i]);
	}
	memset(dist,inf,sizeof dist);
	for(int i=1;i<=m;i++){
		if(!e[i].deg&&e[i].val<dist[e[i].st]){
			dist[e[i].st]=e[i].val;
			S.insert(make_pair(dist[e[i].st],e[i].st));
		}
	}
	while(!S.empty()){
		int now=S.begin()->second,len=S.begin()->first;
		S.erase(S.begin());
		if(dist[now]!=len)continue;
		for(auto x:from[now]){
			e[x].deg--;
//			cerr<<now<<" "<<e[x].st<<" "<<e[x].deg<<endl;
			if(!e[x].deg){
				int cur=0;
				for(auto p:e[x].mp){
					cur+=p.second*dist[p.first];
					cur=min(cur,big);
				}
				cur+=e[x].val;cur=min(cur,big);
				if(cur<dist[e[x].st]){
					dist[e[x].st]=cur;
					S.insert(make_pair(cur,e[x].st));
				}
			}
		}
	}
	for(int i=1;i<=n;i++)Max[i]=-233;
	for(int i=1;i<=n;i++){
//		cerr<<i<<" "<<dist[i]<<endl;
		if(dist[i]==inf){
			Min[i]=-1;Max[i]=-1;
		}else{
			Min[i]=dist[i];
		}
	}
	for(int i=1;i<=n;i++){
		if(Max[i]==-233){
			Max[i]=dfs(i);
		}
	}
	for(int i=1;i<=n;i++){
		cout<<Min[i]<<" "<<Max[i]<<endl;
	}
	return 0;
}