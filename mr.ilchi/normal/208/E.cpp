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

int n,mytime,que;
int p[MAXN],hei[MAXN],lo[MAXN],hi[MAXN];
int par[MAXN][22];
vector <int> adj[MAXN];
vector <pii> Q[MAXN];

void dfs(int v,int h){
	mytime++; lo[v]=mytime; hei[v] = h;
	par[v][0] = (p[v]==0) ? (v) : (p[v]);
	for (int i=1; i<20; i++)
		par[v][i] = par[par[v][i-1]][i-1];
	for (int i=0; i<(int)adj[v].size(); i++)
		dfs(adj[v][i],h+1);
	mytime++; hi[v]=mytime;
	Q[hei[v]].push_back(pii(lo[v],hi[v]));
}

int main(){
	scanf("%d" , &n);
	for (int i=1; i<=n; i++){
		scanf("%d" , &p[i]);
		adj[p[i]].push_back(i);
	}
	for (int i=1; i<=n; i++) if (p[i]==0)
		dfs(i,0);
	scanf("%d",&que);
	for (int o=1; o<=que; o++){
		int v,p; scanf("%d%d",&v,&p);
		if (p>hei[v]){
			printf("0\n"); continue;
		}
		for (int i=19; i>=0; i--) if (p & (1<<i))
			v = par[v][i];
		printf("%d\n" , upper_bound(Q[hei[v]+p].begin(),Q[hei[v]+p].end(),pii(hi[v],-1)) - upper_bound(Q[hei[v]+p].begin(),Q[hei[v]+p].end(),pii(lo[v],-1))-1);
	}
	return 0;
}