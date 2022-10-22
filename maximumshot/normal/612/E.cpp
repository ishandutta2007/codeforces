#include <iostream>
#include <vector>
#include <algorithm>
#include <time.h>
#include <set>
#include <string>
#include <tuple>
#include <fstream>
#include <stdio.h>

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

	int n;

	scanf("%d", &n);

	vec< int > p(n);
	for(int i = 0;i < n;i++) scanf("%d", &p[i]), p[i]--;

	vec< vec< vec< int > > > a(n + 1); 
	vec< int > t, q(n, -1);
	vec< char > used(n, 0);

	for(int i = 0;i < n;i++) {
		if(used[p[i]]) continue;
		int v = p[i];
		t.clear();
		while(!used[v]) {
			t.push_back(v);
			used[v] = 1;
			v = p[v];
		}
		a[(int)t.size()].push_back(t);
	}


	/*cout << '\n';
	for(auto i : a) {
		for(auto j : i) cout << j << ' ';
		cout << '\n';
	}
	cout << '\n';*/

	for(int sz = 2;sz <= n;sz += 2) {
		if((int)a[sz].size() % 2) {
			puts("-1"); 
			return true;
		}	
	}
	
	for(int sz = 1;sz <= n;sz++) {
		if(a[sz].empty()) continue;

		if(sz == 1) {
			for(auto i : a[sz]) {
				q[i[0]] = i[0];
			}
			continue;
		}

		if(sz % 2) {
			int d = sz / 2;

			for(auto i : a[sz]) {
				for(int j = 0;j <= d;j++) {
					q[i[j]] = i[(j + d + 1) % sz];
					q[i[(j + d + 1) % sz]] = i[j + 1];
				}
			}
		}else {
			
			for(int it = 0;it < (int)a[sz].size();it += 2) {
				// it, it + 1

				for(int id = 0;id < sz;id++) {
					int u, v;

					u = a[sz][it][id];
					v = a[sz][it + 1][id];
					q[u] = v;
					
					u = a[sz][it + 1][id];
					v = a[sz][it][(id + 1) % sz];
					q[u] = v;
				}
			}

		}
	}

	for(auto i : q) printf("%d ", i + 1);
	puts("");

	return true;
}

int main() {

	//while(solve());
	solve();
	
	return 0;
}