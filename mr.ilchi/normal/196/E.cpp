/*
 * in the name of god
 *
 *
 *
 *
 *
 *
 *
 *
 */

#include <iostream>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <complex>
#include <ctime>
#include <vector>
#include <queue>
#include <stack>
#include <deque>
#include <set>
#include <map>
#include <utility>
#if ( _WIN32 || __WIN32__ )
    #define LLD "%I64d"
#else
    #define LLD "%lld"
#endif
using namespace std;	
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef complex<double> point;
typedef long double ldb;

const int maxN = 100000 + 10;

int n,e,k;
int p[maxN],par[maxN],ppar[maxN];
ll dis[maxN];
vector <int> adj[maxN],cost[maxN];

struct cmp{
	bool operator () (const int &A , const int &B){
		return (dis[A]!=dis[B]) ? (dis[A]<dis[B]) : (A<B); 
	}
};

ll dij (){
	for (int i=1; i<=n; i++)
		dis[i] = (1ll<<60);
	set <int,cmp> SET;
	for (int i=1; i<=k; i++){
		par[p[i]] = i;
		dis[p[i]] = 0;
		SET.insert(p[i]);
	}
	while (!SET.empty()){
		int begin = *SET.begin(); SET.erase(begin);
		for (int i=0; i<(int)adj[begin].size(); i++){
			int tmp = adj[begin][i];
			ll  DIS = dis[begin] + cost[begin][i];
			if (DIS < dis[tmp]){
				SET.erase(tmp);
				dis[tmp] = DIS; par[tmp] = par[begin];
				SET.insert(tmp);
			}
		}
	}
	return dis[1];
}

int root (int x){
	return (ppar[x]!=x) ? (ppar[x]=root(ppar[x])) : (x);
}

ll kruskal(){
	for (int i=1; i<=k; i++)
		ppar[i] = i;
	vector < pair< ll, pii > > edge;
	for (int i=1; i<=n; i++)
		for (int j=0; j<(int)adj[i].size(); j++) if (par[i]<par[adj[i][j]])
			edge.push_back(make_pair(dis[i]+dis[adj[i][j]]+cost[i][j],pii(par[i],par[adj[i][j]])));
	for (int i=1; i<=k; i++)
		ppar[i] = i;
	sort(edge.begin(),edge.end());
	ll ret = 0;
	for (int i=0; i<(int)edge.size(); i++) if (root(edge[i].second.first)!=root(edge[i].second.second)){
		ret+= edge[i].first;
		ppar[root(edge[i].second.second)] = root(edge[i].second.first);
	}
	return ret;
}

int main(){
	scanf("%d%d" , &n, &e);
	for (int i=1; i<=e; i++){
		int x,y,w; scanf("%d%d%d", &x, &y, &w);
		adj[x].push_back(y);
		adj[y].push_back(x);
		cost[x].push_back(w);
		cost[y].push_back(w);
	}
	scanf("%d" , &k);
	for (int i=1; i<=k; i++)
		scanf("%d" , &p[i]);
	dij();
	printf ("%I64d", dis[1] + kruskal()); printf("\n");
	return 0;
}