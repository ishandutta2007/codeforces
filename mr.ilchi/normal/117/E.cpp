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

bool heavy[MAXN],cyc[MAXN];
int n,que,nc,use=1,edge,cnt;
int par[MAXN],nex[MAXN],root[MAXN],ind[MAXN],hei[MAXN],mark[MAXN],sz[MAXN];
vector <int> cycle,Q;
vector <int> adj[MAXN],child[MAXN];

struct segmentTree{
	int n;
	vector <bool> lamp;
	vector <int> dp;
	segmentTree(){}
	segmentTree(int _n){
		n = _n;
		for (int i=0; true; i++) if (n<=(1<<i)){
			dp.resize(1<<(i+1),0);
			lamp.resize(1<<(i+1),false);
			break;
		}
	}
	void go (int root, int st, int fn, int lo, int hi){
		if (hi<st || fn<lo)
			return;
		if (lo<=st && fn<=hi){
			lamp[root]=!lamp[root];
			dp[root] = fn-st+1-dp[root];
			return;
		}
		int mid = (st+fn)/2;
		int lef = root*2;
		int rig = root*2+1;
		go(root*2,st,mid,lo,hi);
		go(root*2+1,mid+1,fn,lo,hi);
		dp[root] = dp[lef]+dp[rig];
		if (lamp[root])
			dp[root] = fn-st+1-dp[root];
	}
}store[MAXN];

void getCycle (int v){
	mark[v] = use;
	for (int i=0; i<(int)adj[v].size(); i++){
		int tmp = adj[v][i];
		if (mark[tmp]!=use){
			par[tmp] = v;
			getCycle(tmp);
		}
		else if (mark[tmp]==use && tmp!=par[v] && !cyc[v]){
			int cur = v;
			while (cur!=par[tmp]){
				cyc[cur]=true;
				cycle.push_back(cur);
				cur = par[cur];
			}
			nc = (int)cycle.size();
		}
	}
}

void dfs (int v, int r){
	Q.push_back(v);
	mark[v] = use;
	root[v] = r;
	sz[v] = 1;
	for (int i=0; i<(int)adj[v].size(); i++){
		int tmp = adj[v][i];
		if (mark[tmp]!=use && !cyc[tmp]){
			par[tmp] = v;
			dfs(tmp,r);
			sz[v]+=sz[tmp];
			child[v].push_back(tmp);
		}
	}
	for (int i=0; i<(int)child[v].size(); i++)
		heavy[child[v][i]] = (sz[child[v][i]]*2>sz[v]);
}

void add (int x){
	while (x!=par[x]){
		int &tmp = store[ind[x]].dp[1]; 
		edge-=tmp;
		store[ind[x]].go(1,1,store[ind[x]].n,1,hei[x]);
		edge+= tmp;
		x = nex[x];
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin >> n >> que;
	for (int i=1; i<=n; i++){
		int x,y; cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	getCycle(1); use++;
//	for (int i=0; i<(int)cycle.size(); i++)
//		cerr << cycle[i] << ' '; cerr << endl;
	store[0] = segmentTree(nc);
	for (int i=0; i<(int)cycle.size(); i++){
		par[cycle[i]]=cycle[i];
		Q.clear();
		dfs(cycle[i],i); use++;
		for (int j=(int)Q.size()-1; j>0; j--) if (nex[Q[j]]==0){
			int cur = Q[j];
			vector <int> have;
			while (cur!=cycle[i] && heavy[cur]==heavy[Q[j]]){
				have.push_back(cur);
				cur = par[cur];
		//		break;
				if (heavy[Q[j]]==false)
					break;
			}
			cnt++;
			store[cnt] = segmentTree((int)have.size());
			for (int k=0; k<(int)have.size(); k++){
				nex[have[k]] = cur;
				hei[have[k]] = (int)have.size()-k;
				ind[have[k]] = cnt;
			}
	//		cerr << " : " ;
	//		for (int i=0; i<(int)have.size(); i++)
	//			cerr << have[i] << ' '; cerr << endl;
		}
	}
	for (int o=1; o<=que; o++){
		int x,y; cin >> x >> y;
		add(x); x=root[x];
		add(y); y=root[y];
		if (x!=y){
			int len1 = (y-x+nc) % nc;
			int len2 = (x-y+nc) % nc;
			if ((len1>len2) || (len1==len2 && cycle[(x+1)%nc]>cycle[(x-1+nc)%nc]))
				swap(x,y);
			y=(y-1+nc)%nc;
			edge-= store[0].dp[1];
			if (x<=y) 
				store[0].go(1,0,nc-1,x,y);
			else{
				store[0].go(1,0,nc-1,x,nc-1);
				store[0].go(1,0,nc-1,0,y);
			}
			edge+= store[0].dp[1];
		}
		cout << n-edge+(store[0].dp[1]==nc) << endl;
	}	
	return 0;
}