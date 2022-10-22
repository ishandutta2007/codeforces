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
#include <bitset>
#include <list>

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
const double pi = acos(-1.0);

bool solve() {

	int n, m;
	scanf("%d %d", &n, &m);

	vec< int > p(n + 1), pos(n + 1);
	for(int i = 1;i <= n;i++) scanf("%d", &p[i]), pos[p[i]] = i;

	vec< int > tor(n + 1, n);

	for(int u, v, i = 0;i < m;i++) {
		scanf("%d %d", &u, &v);
		if(pos[u] > pos[v]) swap(u, v);
		tor[pos[u]] = min(tor[pos[u]], pos[v] - 1);
	}

	for(int i = n;i > 1;i--) {
		tor[i - 1] = min(tor[i - 1], tor[i]);
	}
	
	ll res = 0;

	for(int i = 1;i <= n;i++) res += max(0, tor[i] - i + 1);

	cout << res << '\n';

	return true;
}

int main() {
		
	//while(solve());
	solve();

	return 0;
}