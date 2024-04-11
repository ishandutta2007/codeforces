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

bool mark[MAXN];
int n;
int e1 [MAXN],e2[MAXN],d[MAXN],sz[MAXN],par[MAXN],SIZE[MAXN],pp[MAXN];
ll cost[MAXN];
vector <int> Q;
vector <pii> adj[MAXN];

bool cmp (const int &A, const int &B){
	return d[A]<d[B];
}

int root (int x){
	return par[x]!=x ? par[x]=root(par[x]) : x;
}

bool Union (int x, int y){
	x = root(x);
	y = root(y);
	if (x==y)
		return false;
	if (sz[x]<sz[y])
		swap(x,y);
	par[y] = x;
	sz [x]+= sz[y]; sz[y]=0;
	return true;
}

void dfs (int v){
	mark[v] = true;
	SIZE[v] = sz[v];
	for (int i=0; i<(int)adj[v].size(); i++){
		int tmp = adj[v][i].first;
		if (!mark[tmp]){
			dfs(tmp);
			SIZE[v]+= SIZE[tmp];
			pp[tmp] = adj[v][i].second;
		}
	}
	Q.push_back(v);
}

int main(){
	cin >> n;
	vector <int> perm;
	for (int i=1; i<n; i++){
		cin >> e1[i] >> e2[i] >> d[i];
		perm.push_back(i);
	}
	sort(perm.begin(),perm.end(),cmp);
	for (int i=1; i<=n; i++){
		par[i] = i;
		sz [i] = 1;
	}
	ll MAX = 0;
	for (int i=0; i<(int)perm.size(); i++){
		int j = i;
		while (j<(int)perm.size() && d[perm[i]]==d[perm[j]]){
			adj[root(e1[perm[j]])].push_back(pii(root(e2[perm[j]]),perm[j]));
			adj[root(e2[perm[j]])].push_back(pii(root(e1[perm[j]]),perm[j]));
			j++;
		}
		for (int k=i; k<j; k++) if (!mark[root(e1[perm[k]])]){
			Q.clear();
			pp [root(e1[perm[k]])] = -1;
			dfs(root(e1[perm[k]]));
			int tot = SIZE[root(e1[perm[k]])];
			for (int z=0; z<(int)Q.size(); z++) if (pp[Q[z]]!=-1){
				cost[pp[Q[z]]] = 2 * (ll)SIZE[Q[z]] * (tot - SIZE[Q[z]]);
				MAX = max(MAX,cost[pp[Q[z]]]);
			}
		}
		for (int k=i; k<j; k++){
			adj [root(e1[perm[k]])].clear();
			adj [root(e2[perm[k]])].clear();
			mark[root(e1[perm[k]])] = false;
			mark[root(e2[perm[k]])] = false;
		}
		for (int k=i; k<j; k++)
			Union(e1[perm[k]],e2[perm[k]]);
		i = j-1;
	}
	cout << MAX << ' ' << count(cost+1,cost+n,MAX) << endl;
	for (int i=1; i<n; i++) if (cost[i]==MAX)
		cout << i << ' ';
	cout << endl;
	return 0;
}