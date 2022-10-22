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

bool solve() {

	ios_base :: sync_with_stdio(0);
	cin.tie(0);

	int q;

	cin >> q;

	map< pair< ll, ll>, ll > cost;

	while(q--) {
		int ty;

		cin >> ty;

		if(ty == 1) {
			ll u, v, w, p;
			cin >> u >> v >> w;

			while(u != v) {
			//	cout << u << ' ' << v << '\n';
				if(u > v) {
					p = u / 2;
					cost[mp(p, u)] += w;
					u = p;
				}else {
					p = v / 2;
					cost[mp(p, v)] += w;
					v = p;
				}
			}
		}else {
			ll u, v, p;
			cin >> u >> v;
			ll res = 0;

			while(u != v) {
				if(u > v) {
					p = u / 2;
					res += cost[mp(p, u)];
					u = p;
				}else {
					p = v / 2;
					res += cost[mp(p, v)];
					v = p;
				}
			}

			cout << res << '\n';
		}
	}

	return true;
}

int main() {
	
	//while(solve());
	solve();

	return 0;
}