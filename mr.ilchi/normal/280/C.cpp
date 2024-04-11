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
#include <fstream>
#include <sstream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <map>
#include <complex>
#include <bitset>
#include <iomanip>
#include <utility>

using namespace std;

typedef long long LL;
typedef complex<double> point;
typedef long double ldb;
typedef pair<int,int> pii;

const int MAXN = 100000+10;

bool mark[MAXN];
int n;
vector <int> adj[MAXN];

inline double dfs (int v, int h){
	mark[v] = true;
	double ret = 1.0/(h+1.0);
	for (int i=0; i<(int)adj[v].size(); i++) if (!mark[adj[v][i]])
		ret+= dfs(adj[v][i], h+1);
	return ret;
}

int main(){
	cin >> n;
	for (int i=0; i<n-1; i++){
		int e1,e2; cin >> e1 >> e2; 
		e1--; e2--;
		adj[e1].push_back(e2);
		adj[e2].push_back(e1);
	}
	cout << fixed << setprecision(10) << dfs(0, 0) << endl;
	return 0;
}