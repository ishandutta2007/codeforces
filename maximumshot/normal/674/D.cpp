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
#include <stack>
#include <math.h>
#include <unordered_map>
#include <array>

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

int n, q;
vec< ll > t, sum;
vec< int > f, k;

multiset< ll > tree;
vec< multiset< ll > > g;
multiset< ll > :: iterator fnd;

ll get_own(int i) {
	return sum[i] + t[i] - 1ll * (k[i] + 1) * (t[i] / ll(k[i] + 2));
}

ll get_all(int i) {
	return get_own(i) + t[f[i]] / ll(k[f[i]] + 2);
}

void del(int i) {
	if(!g[i].empty()) {
		ll delt = t[i] / ll(k[i] + 2), mn, mx;
		mn = *g[i].begin() + delt;
		mx = *(--g[i].end()) + delt;
		tree.erase(tree.lower_bound(mn));
		tree.erase(tree.lower_bound(mx));
	}
}

void ins(int i) {
	if(!g[i].empty()) {
		ll delt = t[i] / ll(k[i] + 2), mn, mx;
		mn = *g[i].begin() + delt;
		mx = *(--g[i].end()) + delt;
		tree.insert(mn);
		tree.insert(mx);
	}
}

bool solve() {
		
	scanf("%d %d", &n, &q);

	t.resize(n + 1);

	for(int i = 1;i <= n;i++) scanf("%I64d", &t[i]);

	f.resize(n + 1);
	k.resize(n + 1);

	for(int i = 1;i <= n;i++) {
		scanf("%d", &f[i]);
		k[f[i]]++;
	}

	sum.resize(n + 1);

	for(int i = 1;i <= n;i++) {
		sum[f[i]] += t[i] / ll(k[i] + 2);
	}

	g.resize(n + 1);

	for(int i = 1;i <= n;i++) {
		g[f[i]].insert(get_own(i));
	}

	for(int i = 1;i <= n;i++) {
		if(!g[i].empty()) {
			ll delt = t[i] / ll(k[i] + 2);
			tree.insert(*g[i].begin() + delt);
			tree.insert(*(--g[i].end()) + delt);
		}
	}

	for(int type, i, j, iter = 0;iter < q;iter++) {
		scanf("%d", &type);

		if(type == 1) {
			
			scanf("%d %d", &i, &j);

			vec< int > diff;

			diff.push_back(i);
			diff.push_back(f[i]);
			diff.push_back(f[f[i]]);
			diff.push_back(f[f[f[i]]]);
			diff.push_back(j);
			diff.push_back(f[j]);
			diff.push_back(f[f[j]]);

			sort(ALL(diff));
			diff.resize(unique(ALL(diff)) - diff.begin());

			for(auto v : diff) {
				del(v);
			}

			for(auto v : diff) {
				g[f[v]].erase(g[f[v]].lower_bound(get_own(v)));
			}

			sum[f[f[i]]] -= t[f[i]] / ll(k[f[i]] + 2);
			sum[f[j]] -= t[j] / ll(k[j] + 2);

			k[f[i]]--;
			k[j]++;

			sum[f[f[i]]] += t[f[i]] / ll(k[f[i]] + 2);
			sum[f[j]] += t[j] / ll(k[j] + 2);

			sum[f[i]] -= t[i] / ll(k[i] + 2);
			sum[j] += t[i] / ll(k[i] + 2);
			
			f[i] = j;

			for(auto v : diff) {
				g[f[v]].insert(get_own(v));
			}

			for(auto v : diff) ins(v);

		}else if(type == 2) {
			scanf("%d", &i);
			printf("%I64d\n", get_all(i));
		}else {
			printf("%I64d %I64d\n", *tree.begin(), *(--tree.end()));
		}
	}

	return true;
}

int main() {
	
	//while(solve());
	solve();

	return 0;
}