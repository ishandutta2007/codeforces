/*
Though leaves are many , the root is one.
Through all the lying days of my youth
I swayed my leaves and flowers in the sun.
Now I may wither into the truth.
	  	  	- William Butler Yeats
*/
//#pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline") //Optimization flags
//#pragma GCC option("arch=native","tune=native","no-zero-upper") //Enable AVX
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2")
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
vector<int>G[100005];
bitset<10005>bs[10005];
int t,n,m,k,x[100005],y[100005],deg[100005],ind[100005];
queue<int>q;
bool solve1(){
	q=queue<int>();
	for(int i=1;i<=n;i++){
		if(deg[i]<k)q.push(i);
	}
	while(!q.empty()){
		int x=q.front();q.pop();
		for(auto to:G[x]){
			deg[to]--;
			if(deg[to]==k-1){
				q.push(to);
			}
		}
	}
	int cnt=0;
	for(int i=1;i<=n;i++)if(deg[i]>=k)cnt++;
	if(!cnt)return 0;
	printf("1 %d\n",cnt);
	for(int i=1;i<=n;i++)if(deg[i]>=k){
		printf("%d ",i);
	}
	printf("\n");
	return 1;
}
set<int>s[100005];
set<pair<int,int> >e;
bool check(int x){
	vector<int>all(1,x);
	for(auto v:s[x])all.push_back(v);
	if(k<20){
		for(int i=0;i<all.size();i++)for(int j=i+1;j<all.size();j++)if(!e.count(make_pair(all[i],all[j])))return 0;
	}else{
		for(auto v:all)if(!ind[v])return 0;
		for(int i=0;i<all.size();i++)for(int j=i+1;j<all.size();j++)if(!bs[ind[all[i]]][ind[all[j]]])return 0;
	}
	printf("2\n");
	for(auto v:all)printf("%d ",v);
	printf("\n");
	assert(all.size()==k);
}
bool solve2(){
	q=queue<int>();
	for(int i=1;i<=n;i++)deg[i]=0;
	for(int i=1;i<=n;i++)s[i].clear();
	for(int i=1;i<=m;i++){
		deg[x[i]]++;deg[y[i]]++;
		s[x[i]].insert(y[i]);
		s[y[i]].insert(x[i]);
	}
	for(int i=1;i<=n;i++){
		if(deg[i]<k)q.push(i);
	}
	while(!q.empty()){
		int x=q.front();q.pop();
		if(s[x].size()==k-1){
			if(check(x))return 1;
		}
		for(auto to:G[x]){
			s[to].erase(x);
			deg[to]--;
			if(deg[to]==k-1){
				q.push(to);
			}
		}
	}
	return 0;
}
int main(){
	scanf("%d",&t);
	while(t--){
		e.clear();
		scanf("%d%d%d",&n,&m,&k);
		for(int i=1;i<=n;i++)deg[i]=0;
		for(int i=1;i<=n;i++)G[i].clear();
		for(int i=1;i<=m;i++){
			scanf("%d%d",&x[i],&y[i]);
			deg[x[i]]++;deg[y[i]]++;
			e.insert(make_pair(x[i],y[i]));
			e.insert(make_pair(y[i],x[i]));
			G[x[i]].push_back(y[i]);
			G[y[i]].push_back(x[i]);
		}
		if(k>=20){
			int tot=0;
			for(int i=1;i<=n;i++)ind[i]=0;
			for(int i=1;i<=n;i++){
				if(deg[i]>=k-1){
					ind[i]=++tot;
				}
			}
			assert(tot<=10000);
			for(int i=1;i<=m;i++){
				if(ind[x[i]]&&ind[y[i]]){
					bs[ind[x[i]]].set(ind[y[i]]);
					bs[ind[y[i]]].set(ind[x[i]]);
				}
			}
		}
		if(!solve1()&&!solve2())printf("-1\n");
		if(k>=20)for(int i=1;i<=m;i++){
			if(ind[x[i]]&&ind[y[i]]){
				bs[ind[x[i]]].reset(ind[y[i]]);
				bs[ind[y[i]]].reset(ind[x[i]]);
			}
		}
	}
	return 0;
}