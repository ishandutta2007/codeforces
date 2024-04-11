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

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()
#define mp make_pair
#define mt make_tuple

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef pair< int, int > pii;

const int inf = 1000 * 1000 * 1000;
const ll inf64 = 1ll * inf * inf;
const double pi = acos(-1.0);

bool solve() {
	
	int n;
	string x;

	cin >> n;
	
	vec< char > ch;
	vec< string > mas;
	vec< int > pos(26, -1);

	for(int i = 0;i < n;i++) {
		cin >> x;
		for(auto j : x) ch.push_back(j);
		mas.push_back(x);
	}

	sort(ALL(ch));
	ch.resize(unique(ALL(ch)) - ch.begin());

	int sz = (int)ch.size();

	vec< vec< int > > g(sz), f(sz);

	for(int i = 0;i < sz;i++) pos[ch[i] - 'a'] = i;

	for(auto s : mas) {
		for(int i = 0;i + 1 < (int)s.size();i++) {
			int u, v;
			u = pos[s[i] - 'a'];
			v = pos[s[i + 1] - 'a'];
			g[u].push_back(v);
			f[v].push_back(u);
		}
	}
	
	for(int i = 0;i < sz;i++) {
		sort(ALL(g[i]));
		g[i].resize(unique(ALL(g[i])) - g[i].begin());
		sort(ALL(f[i]));
		f[i].resize(unique(ALL(f[i])) - f[i].begin());
	}
	
	vec< char > used(sz);

	for(int i = 0;i < sz;i++) {
		if(used[i] || !f[i].empty()) continue;
		for(int v = i;;) {
			used[v] = 1;
			cout << ch[v];
			if(g[v].empty()) break;
			else v = g[v][0];
		}
	}
	
	cout << '\n';

	return true;
}

int main() {

	//while(solve());
	solve();	
	
	return 0;
}