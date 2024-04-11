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
vec< int > a, p, c;
vec< vec< int > > g;

void read() {
	scanf("%d", &n);
	a.resize(n + 1);
	for(int i = 1;i <= n;i++) scanf("%d", &a[i]);
	p.resize(n + 1);
	c.resize(n + 1);
	g.resize(n + 1);
	for(int i = 2;i <= n;i++) scanf("%d %d", &p[i], &c[i]), g[p[i]].push_back(i);
}

vec< ll > s;

void dfs(int v) {
	if(v == 1) {
		s[v] = 0;
	}else {
		s[v] = s[p[v]] + c[v];
	}
	for(auto to : g[v]) dfs(to);
} 

void precalc() {
	s.resize(n + 1);
	dfs(1);
}

set< pair< ll, int > > q;
// hs[v], v

vec< char > mark;

void go(int v) {
	ll s_min = q.empty() ? inf64 : q.begin()->first;
	if(s_min < s[v] - a[v]) mark[v] = 1;
	q.insert(mp(s[v], v));
	for(auto to : g[v]) go(to);
	q.erase(mp(s[v], v));
}

void pr(int v) {
	if(v > 1) mark[v] |= mark[p[v]];
	for(auto to : g[v]) pr(to);
}

bool solve() {
		
	read();
	precalc();

	mark.resize(n + 1);
	go(1);

	pr(1);

	int res = 0;

	for(int i = 1;i <= n;i++) res += mark[i];

	printf("%d\n", res);

	return true;
}

int main() {

	//while(solve());
	solve();

	return 0;
}