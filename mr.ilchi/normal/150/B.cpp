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

const int maxN = 2000 + 10;
const int mod = 1000 * 1000 * 1000 + 7;

bool mark[maxN];
int n,m,k;
vector <int> adj[maxN];

int POWER (int x, int y){
	
	if (y==0)
		return 1;

	ll tmp = POWER(x,y/2); tmp*=tmp; tmp%=mod;

	if (y & 1)
		return (tmp * x)%mod;

	return tmp;
}

void dfs (int v){
	mark[v]=true;
	for (int i=0; i<(int)adj[v].size(); i++) if (!mark[adj[v][i]])
		dfs(adj[v][i]);
}

int main(){
	
	cin >> n >> m >> k;

	for (int i=1; i+k-1<=n; i++){
		
		for (int j=i,z=i+k-1; j<z; j++,z--){
			adj[j].push_back (z);
			adj[z].push_back (j);
		}
	}

	int comp = 0;

	for (int i=1; i<=n; i++) if (!mark[i]){
		dfs(i);
		comp++;
	}
	
	cout << POWER(m,comp) << endl;
	
	return 0;
}