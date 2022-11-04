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

bool mark[maxN];
int n,e;
int col[maxN];
vector <int> Q;
vector <int> adj[maxN],bak[maxN];

void dfs (int v, int h){
	mark[v] = true;
	col[v] = h;
	for (int i=0; i<(int)adj[v].size(); i++){
		int tmp = adj[v][i];
		if (!mark[tmp])
			dfs (tmp,h+1);
	}
	for (int i=0; i<(int)bak[v].size(); i++){
		int tmp = bak[v][i];
		if (!mark[tmp])
			dfs(tmp,h-1);
	}
	Q.push_back(v);
}

int Abs (int x){
	return max(x,-x);
}

int main(){

	scanf ("%d%d" , &n, &e);

	for (int i=1; i<=e; i++){
		int e1,e2; scanf ("%d%d" , &e1, &e2);
		adj[e1].push_back(e2);
		bak[e2].push_back(e1);
	}

	int ans = -1;
	
	for (int i=1; i<=n; i++) if (!mark[i]){
		
		Q.clear();
		dfs(i,n);
		
		int now = -1;

		for (int i=0; i<(int)Q.size(); i++){
			int v = Q[i];
			for (int j=0; j<(int)adj[v].size(); j++){
				int tmp = adj[v][j];
				if (col[tmp]!=col[v]+1){
					if (now==-1)
						now = Abs(col[tmp]-(col[v]+1));
					else
						now = __gcd(now,Abs(col[tmp]-(col[v]+1)));
				}
			}
			for (int j=0; j<(int)bak[v].size(); j++){
				int tmp = bak[v][j];
				if (col[tmp]!=col[v]-1){
					if (now==-1)
						now = Abs(col[tmp]-(col[v]-1));
					else
						now = __gcd(now,Abs(col[tmp]-(col[v]-1)));
				}
			}
		}

		if (ans==-1)
			ans = now;

		else if (now!=-1)
			ans = __gcd(ans,now);
	}

	if (ans==-1)
		ans = n;

	cout << ans << endl;

	return 0;
}