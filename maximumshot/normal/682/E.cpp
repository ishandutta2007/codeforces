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
#include <complex>

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

int n;
ll S;
vec< pii > a;

bool cmp(pii p1, pii p2) {
	return 1ll * (p1.second - a[0].second) * (p2.first - a[0].first) < 
		1ll * (p2.second - a[0].second) * (p1.first - a[0].first) ;
}

ll mul(pii v1, pii v2) {
	return 1ll * v1.first * v2.second - 1ll * v2.first * v1.second;
}

pii raz(pii A, pii B) {
	return mp(A.first - B.first, A.second - B.second);
}

void convex_hull() {
	sort(ALL(a));
	sort(a.begin() + 1, a.end(), cmp);
	vec< pii > b;
	b.push_back(a[0]);

	for(int i = 1;i < n;i++) {
		
		pii C = a[i], A, B;

		while((int)b.size() > 1) {
			B = b.back();
			b.pop_back();
			A = b.back();
			if(mul(raz(C, B), raz(A, B)) > 0) {
				b.push_back(B);
				break;
			}
		}

		b.push_back(C);

	}

	a = b;
}

ll area(int i, int j, int k) {
	ll res = mul(raz(a[k], a[j]), raz(a[i], a[j]));
	if(res < 0) res = -res;
	return res;
}

bool solve() {
	
	scanf("%d %I64d", &n, &S);

	a.resize(n);
	for(int i = 0;i < n;i++) scanf("%d %d", &a[i].first, &a[i].second);

	convex_hull();

	tuple< ll, int, int, int > res = mt(0, 0, 0, 0);

	int i, j, k;

	i = 0;
	j = 1;
	k = 2;

	n = (int)a.size();

	while(1) {
		while(1) {
			while(area(i, j, k) <= area(i, j, (k + 1) % n)) k = (k + 1) % n;
			if(area(i, j, k) <= area(i, (j + 1) % n, k)) j = (j + 1) % n;
			else break;
		}
		res = max(res, mt(area(i, j, k), i, j, k));
		i = (i + 1) % n;
		if(i == j) j = (j + 1) % n;
		if(j == k) k = (k + 1) % n;
		if(i == 0) break; 
	}

	tie(ignore, i, j, k) = res;

	vec< pii > ans;

	ans.emplace_back(a[i].first - (a[j].first - a[k].first), a[i].second - (a[j].second - a[k].second));
	ans.emplace_back(a[i].first + (a[j].first - a[k].first), a[i].second + (a[j].second - a[k].second));
	ans.emplace_back(a[j].first - (a[i].first - a[k].first), a[j].second - (a[i].second - a[k].second));
	ans.emplace_back(a[j].first + (a[i].first - a[k].first), a[j].second + (a[i].second - a[k].second));
	ans.emplace_back(a[k].first - (a[i].first - a[j].first), a[k].second - (a[i].second - a[j].second));
	ans.emplace_back(a[k].first + (a[i].first - a[j].first), a[k].second + (a[i].second - a[j].second));

	sort(ALL(ans));
	ans.resize(unique(ALL(ans)) - ans.begin());

	for(auto cur : ans) cout << cur.first << ' ' << cur.second << '\n';

	return true;
}

int main() {
	
	//while(solve());
	solve();

	return 0;
}