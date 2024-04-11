#include <iostream>
#include <sstream>
#include <fstream>
#include <stdio.h>
#include <iomanip>

#include <vector>
#include <algorithm>
#include <set>
#include <string>
#include <cstring>
#include <tuple>
#include <map>
#include <queue>
#include <bitset>
#include <list>
#include <stack>
#include <unordered_map>
#include <array>

#include <complex>
#include <time.h>
#include <math.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()
#define mp make_pair
#define mt make_tuple

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef pair< int, int > pii;
typedef pair< double, double > pdd;

const int inf = 1000 * 1000 * 1000;
const ll inf64 = 1ll * inf * inf;

void no() {
	cout << "no\n";
	exit(0);
}

void yes() {
	cout << "yes\n";
	exit(0);
}

bool solve() {
			
	int n, m;

	cin >> n >> m;

	if(m != n - 1) no();

	vec< vec< int > > g(n + 1);

	for(int i = 1;i <= m;i++) {
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	vec< char > vis(n + 1);
	queue< int > q;

	vis[1] = 1;
	q.push(1);

	while(!q.empty()) {
		int v = q.front();
		q.pop();
		for(int to : g[v]) {
			if(!vis[to]) {
				vis[to] = 1;
				q.push(to);
			}		
		}
	}

	for(int i = 1;i <= n;i++) {
		if(!vis[i]) no();
	}

	yes();

	return true;
}

int main() {
	
	//while(solve());
	solve();

	return 0;
}