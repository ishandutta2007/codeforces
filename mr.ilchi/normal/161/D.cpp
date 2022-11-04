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

const int maxN = 50 * 1000 + 10;
const int maxK = 500 + 10;

bool mark[maxN];
int n,k;
int par[maxN];
int dis[maxN][maxK];
vector <int> adj[maxN];

void dfs (int v){
	
	mark[v] = true;

	dis[v][0] = 1;

	for (int i=0; i<(int)adj[v].size(); i++){
		int tmp = adj[v][i];
		if (!mark[tmp]){
			par[tmp] = v;
			dfs (tmp);
			for (int j=1; j<=k; j++)
				dis[v][j]+= dis[tmp][j-1];
		}
	}
}

int main(){
	
	cin >> n >> k;

	for (int i=1; i<n; i++){
		int x,y; cin >> x >> y;
		adj[x].push_back (y);
		adj[y].push_back (x);
	}

	dfs(1);

	ll sum = 0;

	for (int i=1; i<=n; i++){
		sum+= dis[i][k];
		int past = i;
		int now = par[i];
		for (int j=1; now!=0 && j<=k; j++){
			sum+= dis[now][k-j];
			if (k-j-1>=0)
				sum-= dis[past][k-j-1];
			past = now;
			now = par[now];
		}
	}

	cout << sum / 2 << endl;

	return 0;
}