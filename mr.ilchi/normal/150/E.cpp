/*
 * in the name of god
 *
 *
 *
 *
 *
 *
 *
 */

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <queue>
#include <complex>
#include <stack>
#include <deque>
#include <queue>
#include <iomanip>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef complex<double> point;
typedef long double ldb;

const int MAXN = 100000+10;
const int MAXT = (1<<20);

bool mark[MAXN];
int n,l,r,N,C,lim,lenHave,now;
int a[MAXN],b[MAXN],c[MAXN],sz[MAXN],val[MAXN],dp[MAXT],cent[MAXN];
vector <int> adj[MAXN],wei[MAXN],adjF[MAXN],weiF[MAXN],perm[MAXN],child[MAXN];
pii have[MAXN];

void add (int root, int lo, int hi, int pos, int wh){
	while (true){
		if (dp[root]==-1 || val[dp[root]]<val[pos])
			dp[root] = pos;
		if (lo==hi) 
			return;
		int mid = (lo+hi)/2;
		if (wh<=mid)
			root=root*2, hi=mid;
		else
			root=root*2+1, lo=mid+1;
	}
}

int get (int root, int lo, int hi, int st, int fn){
	if (hi<st || fn<lo)
		return -1;
	if (st<=lo && hi<=fn)
		return dp[root];
	int mid = (lo+hi)/2;
	int f1 = get((root<<1),lo,mid,st,fn);
	int f2 = get((root<<1)+1,mid+1,hi,st,fn);
	if (f1==-1 || f2==-1)
		return max(f1,f2);
	return (val[f1]<val[f2]) ? f2 : f1;
}

pii dfs (const int &v, const int &h, const int &cost){
	mark[v] = true;
	val [v] = cost;
	for (int i=0; i<(int)adj[v].size(); i++){
		if (!mark[adj[v][i]]){
			if (v == C){
				for (int j=0; j<lenHave; j++)
					add(1,0,N,have[j].second,have[j].first);
				lenHave = 0;
			}
			pii ret = dfs(adj[v][i],h+1,cost+((wei[v][i]<lim)?-1:1));
			if (ret!=pii(-1,-1))
				return ret;
		}
		else if (h==1){
			swap(adj[v][(int)adj[v].size()-1],adj[v][i]);
			swap(wei[v][(int)wei[v].size()-1],wei[v][i]);
			adj[v].pop_back(); 
			wei[v].pop_back();
			i--;
		}
	}
	if (v==C)
		return pii(-1,-1);
	have[lenHave++] = pii(h,v);
	int pos = get(1,0,N,l-h,r-h);
	if (pos!=-1 && 0<=val[pos]+cost)
		return pii(v,pos);
	return pii(-1,-1);
}

pii go (int ind){
	N = (int)perm[ind].size();
	for (int i=0; i<=20; i++) if (((int)perm[ind].size()+1)<=(1<<i)){
		for (int j=1; j<=(1<<(i+1)); j++)
			dp[j]=-1;
		break;
	}
	C = cent[ind];
	val[C] = 0; lenHave=0;
	add(1,0,N,C,0);
	for (int i=0; i<(int)perm[ind].size(); i++)
		mark[perm[ind][i]] = false;
	pii ret = dfs(C,0,0);
	if (ret!=pii(-1,-1))
		return ret;
	for (int i=0; i<(int)child[ind].size(); i++){
		pii ret = go(child[ind][i]);
		if (ret!=pii(-1,-1))
			return ret;
	}
	return pii(-1,-1);
}

int findCenter (int v){
	mark[v] = true;
	sz[v] = 1;
	int maxi = 0;
	for (int i=0; i<(int)adj[v].size(); i++) if (!mark[adj[v][i]]){
		int ret = findCenter(adj[v][i]);
		if (ret!=-1)
			return ret;
		sz[v]+=sz[adj[v][i]];
		maxi=max(maxi,sz[adj[v][i]]);
	}
	if (max(maxi,N-sz[v])*2<=N)
		return v;
	return -1;
}

void dfs2 (int v, int h){
	if (h==1)
		now++;
	mark[v] = true;
	for (int i=0; i<(int)adj[v].size(); i++){
		if (!mark[adj[v][i]])
			dfs2(adj[v][i],h+1);	
		else if (h==1){
			swap(adj[v][i],adj[v][(int)adj[v].size()-1]);
			swap(wei[v][i],wei[v][(int)wei[v].size()-1]);
			wei[v].pop_back();
			adj[v].pop_back();
			i--;
		}
	}
	if (h>0)
		perm[now].push_back(v);
}

void build (int cur){
	if (cur == 1){
		now = 1;
		for (int i=1; i<=n; i++) 
			perm[cur].push_back(i);
	}
	N = (int)perm[cur].size();
	for (int i=0; i<(int)perm[cur].size(); i++)
		mark[perm[cur][i]] = 0;
	cent[cur] = findCenter(perm[cur][0]);
	for (int i=0; i<(int)perm[cur].size(); i++)
		mark[perm[cur][i]] = 0;
	int first = now+1;
	dfs2(cent[cur],0);
	for (int i=first; i<=now; i++)
		child[cur].push_back(i);
	for (int i=0; i<(int)child[cur].size(); i++)
		build(child[cur][i]);
}

int main(){
	cin >> n >> l >> r;
	vector <int> store;
	for (int i=1; i<n; i++){
		cin >> a[i] >> b[i] >> c[i];
		adjF[a[i]].push_back(b[i]);
		adjF[b[i]].push_back(a[i]);
		weiF[a[i]].push_back(c[i]);
		weiF[b[i]].push_back(c[i]);
		store.push_back(c[i]);
	}
	sort(store.begin(),store.end()); 
	store.resize(unique(store.begin(),store.end())-store.begin());
	int lo=0,hi=(int)store.size()-1;
	pii res = pii(-1,-1);
	for (int i=1; i<=n; i++)
		adj[i]=adjF[i] , wei[i]=weiF[i];
	build(1);
	while (lo<=hi){
		for (int i=1; i<=n; i++)
			adj[i]=adjF[i] , wei[i]=weiF[i];
		int mid = (lo+hi)/2;
		::lim = store[mid];
		pii ret = go(1);
		if (ret!=pii(-1,-1)){
			res=ret;
			lo=mid+1;
		}
		else
			hi=mid-1;
	}
	cout << res.first << ' ' << res.second << endl;
	return 0;
}