/*
Though leaves are many , the root is one.
Through all the lying days of my youth
I swayed my leaves and flowers in the sun.
Now I may wither into the truth.
	  	  	- William Butler Yeats
*/
#pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline") //Optimization flags
#pragma GCC option("arch=native","tune=native","no-zero-upper") //Enable AVX
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2")
#include<bits/stdc++.h>
//#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
//using namespace __gnu_pbds;
const int inf=0x3f3f3f3f;
const double eps=1e-6;
const int mod=1e9+7;
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
int n,dist[200005],len[200005],id[200005],lmt[200005];
vector<int>g[200005];
bool cmp(int x,int y){
	return dist[x]>dist[y];
}
int main(){
	memset(dist,inf,sizeof dist);
	ios::sync_with_stdio(0);
	cin>>n;
	for(int i=1;i<n;i++){
		int x,y;cin>>x>>y;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	int k;cin>>k;queue<int>q;
	for(int i=1;i<=k;i++){
		int x;cin>>x;dist[x]=0;q.push(x);
	}
	while(!q.empty()){
		int x=q.front();q.pop();
		for(auto to:g[x])if(dist[to]==inf){
			dist[to]=dist[x]+1;q.push(to);
		}
	}
	memset(len,0,sizeof len);
	memcpy(lmt,dist,sizeof lmt);
	for(int i=1;i<=n;i++)id[i]=i;
	sort(id+1,id+n+1,cmp);
	queue<pair<int,int> >qq;
	for(int i=1;i<=n;i++){
		int xx=id[i];
		qq.push(make_pair(lmt[xx],xx));
		len[xx]=lmt[xx];
		while(!qq.empty()){
			int x=qq.front().second,cur=qq.front().first;qq.pop();
			len[x]=max(len[x],cur);
			for(auto to:g[x])if(len[to]<cur-1&&cur>1){
				dist[to]=max(dist[to],lmt[xx]);
				qq.push(make_pair(cur-1,to));
			}
		}
	}
	for(int i=1;i<=n;i++)cout<<dist[i]<<" ";
	return 0;
}