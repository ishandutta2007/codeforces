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

const int maxN = 100 * 1000 + 10;

bool mark[maxN];
int n,e,mod;
vector <int> adj[maxN];

inline int dfs (int v){
	mark[v] = true;
	int ret = 1;
	for (int i=0; i<(int)adj[v].size(); i++){
		int tmp = adj[v][i];
		if (!mark[tmp])
			ret+= dfs(tmp);
	}
	return ret;
}

int main(){
	
	ios_base::sync_with_stdio(false);

	cin >> n >> e >> mod;

	for (int i=1; i<=e; i++){
		int e1,e2; cin >> e1 >> e2;
		adj[e1].push_back (e2);
		adj[e2].push_back (e1);
	}

	vector <int> comp;

	for (int i=1; i<=n; i++) if (!mark[i])
		comp.push_back(dfs(i));

	if ((int)comp.size()==1){
		cout << (1%mod) << endl;
		return 0;
	}

	ll ans = 1;

	for (int i=1; i<=(int)comp.size()-2; i++)
		ans = ((ll)ans * (ll)n)%mod;	

	for (int i=0; i<(int)comp.size(); i++)
		ans = ((ll)ans * (ll)comp[i])%mod;

	cout << ans << endl;

	return 0;
}