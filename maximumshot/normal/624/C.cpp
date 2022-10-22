#include <iostream>
#include <vector>
#include <algorithm>
#include <time.h>
#include <set>
#include <string>
#include <tuple>
#include <fstream>
#include <stdio.h>
#include <cstring>
#include <map>
#include <queue>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()
#define mp make_pair
#define mt make_tuple

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef pair< int, int > pii;

const int inf = 1000000000;
const ll inf64 = 1ll * inf * inf;
const double pi = acos(-1.0);

bool solve() {

	int n, m;

	cin >> n >> m;

	string a(n, '?');

	vec< vec< int > > g(n, vec< int >(n));

	for(int u, v, i = 0;i < m;i++) {
		cin >> u >> v;
		u--, v--;
		g[u][v] = g[v][u] = 1;
	}

	for(int i = 0;i < n;i++) {
		for(int j = 0;j < n;j++) {
			if(i == j) continue;
			if(g[i][j]) continue;
			if(a[i] == '?' && a[j] == '?') {
				a[i] = 'a';
				a[j] = 'c';
			}else if(a[i] == '?' && a[j] != '?') {
				a[i] = (a[j] == 'a'?'c' : 'a');
			}else if(a[i] != '?' && a[j] == '?') {
				a[j] = (a[i] == 'a'?'c' : 'a');
			}
		}
	}

	for(int i = 0;i < n;i++) {
		if(a[i] == '?') a[i] = 'b';
	}

	for(int i = 0;i < n;i++) {
		for(int j = 0;j < n;j++) {
			if(i == j) continue;
			if(abs(a[i] - a[j]) <= 1 && !g[i][j]) {
				cout << "No\n";
				return true;
			}
			if(abs(a[i] - a[j]) == 2 && g[i][j]) {
				cout << "No\n";
				return true;
			}
		}
	}

	cout << "Yes\n" << a << '\n';

	return true;
}

int main() {

	//while(solve());
	solve();
	
	return 0;
}