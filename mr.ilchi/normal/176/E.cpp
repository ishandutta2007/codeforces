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

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef complex<double> point;
typedef long double ldb;

const int maxN = 100 * 1000 + 10;

int n,Count,que;
int h[maxN],id[maxN];
int par[maxN][20];
ll  sum[maxN];
vector <int> adj[maxN],cost[maxN];

struct cmp{
	bool operator () (const int &a , const int &b){
		return id[a]<id[b];
	}
};
set <int,cmp> sit;

typedef set<int,cmp>::iterator iter;

iter nex (iter it) { it++; if (it==sit.end()) it = sit.begin(); return it; }
iter bak (iter it) { if (it==sit.begin()) it = sit.end(); it--; return it; }

void dfs (int v, int hei){
	
	Count++; id[v] = Count; h[v] = hei;

	if (v==1) for (int i=0; i<=17; i++) par[v][i] = 1;

	for (int i=0; i<(int)adj[v].size(); i++){
		int tmp = adj[v][i];
		if (id[tmp]==0){
			par[tmp][0] = v;
			for (int j=1; j<=17; j++)
				par[tmp][j] = par[par[tmp][j-1]][j-1];
			sum[tmp] = sum[v] + cost[v][i];
			dfs (tmp,hei+1);
		}
	}
}

ll lca (int a, int b){

	int aa = a , bb = b;

	if (h[a]<h[b]) swap(a,b);

	for (int i=17; i>=0; i--) if (h[par[a][i]]>=h[b]) a = par[a][i];
	for (int i=17; i>=0; i--) if (par[a][i]!=par[b][i]) a=par[a][i] , b=par[b][i];

	if (a!=b) a=par[a][0] , b=par[b][0];

	return sum[aa]-sum[a] + sum[bb]-sum[b];
}

int main(){

	scanf ("%d" , &n);

	for (int i=1; i<n; i++){
		int e1,e2,we; scanf ("%d%d%d" , &e1, &e2, &we);
		adj [e1].push_back(e2);
		adj [e2].push_back(e1);
		cost[e1].push_back(we);
		cost[e2].push_back(we);
	}
	
	dfs (1,0);

	scanf ("%d" , &que);
	
	ll sum = 0;

	for (int o=1; o<=que; o++){
		char ch; 
		scanf (" %c" , &ch);
		if (ch=='?')
			printf ("%I64d\n",sum>>1);
		if (ch=='+'){
			int v; scanf ("%d" , &v);
			if (sit.empty())
				sit.insert(v);
			else if ((int)sit.size()==1){
				sum = 2 * lca(*sit.begin(),v);
				sit.insert(v);
			}
			else{
				sit.insert(v);
				iter it = sit.find(v);
				iter it1= bak(it);
				iter it2= nex(it);
				sum+= lca(*it , *it1);
				sum+= lca(*it , *it2);
				sum-= lca(*it1, *it2);
			}
		}
		if (ch=='-'){
			int v; scanf ("%d" , &v);
			if ((int)sit.size()<3){
				sit.erase(v);
				sum = 0;
			}
			else{
				iter it = sit.find(v);
				iter it1 = bak(it);
				iter it2 = nex(it);
				sum-= lca(*it , *it1);
				sum-= lca(*it , *it2);
				sum+= lca(*it1, *it2);
				sit.erase(it);
			}
		}
	}

	return 0;
}