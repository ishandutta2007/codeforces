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

const int LMAX = 800800;
char buff[LMAX];

int n;
vec< string > a, b;

void read() {
	scanf("%d", &n);
	a.resize(n);
	b.resize(n);
	for(int i = 0;i < n;i++) {
		scanf("%s", &buff);
		a[i] =  buff;
	}
	for(int i = 0;i < n;i++) {
		scanf("%s", &buff);
		b[i] = buff;
	}
}

// bor begin
vec< map< char, int > > bor; // 
vec< vec< int > > hob, sch;
int sz;
// bor end

// add begin
map< char , int > add_map;
vec< int > add_vec;
// add end

void init_bor() {
	sz = 1;
	bor.push_back(add_map);
	hob.push_back(add_vec);
	sch.push_back(add_vec);
}

void add_string(int i) {
	int v = 0;
	char c;
	for(int j = 0;j < (int)b[i].size();j++) {
		c = b[i][j];
		if(!bor[v].count(c)) {
			bor[v][c] = sz++;
			bor.push_back(add_map);
			hob.push_back(add_vec);
			sch.push_back(add_vec);
		}
		v = bor[v][c];
	}
	hob[v].push_back(i);
}

void add_sch(int i) {
	int v = 0;
	char c;
	for(int j = 0;j < (int)a[i].size();j++) {
		c = a[i][j];
		if(!bor[v].count(c)) break;
		else v = bor[v][c];
	}
	sch[v].push_back(i);
}

vec< pii > ans;
int cost = 0;

void dfs(int v, int pr) {
	for(auto it : bor[v]) {
		int to = it.second;
		dfs(to, pr + 1);
		//if((int)sch[v].size() < (int)sch[to].size()) swap(sch[v], sch[to]);
		for(auto cur : sch[to]) sch[v].push_back(cur);
		//sch[to].clear();
		//if((int)hob[v].size() < (int)hob[to].size()) swap(hob[v], hob[to]);
		for(auto cur : hob[to]) hob[v].push_back(cur);
		//hob[to].clear();
	}

	while(!hob[v].empty() && !sch[v].empty()) {
		int _u, _v;
		_u = sch[v].back();
		sch[v].pop_back();
		_v = hob[v].back();
		hob[v].pop_back();
		ans.push_back(mp(_u + 1, _v + 1));
		cost += pr;
	}
}

bool solve() {

	read();
	init_bor();

	for(int i = 0;i < n;i++) add_string(i);
	for(int i = 0;i < n;i++) add_sch(i);
	
	dfs(0, 0);

	printf("%d\n", cost);

	for(auto cur : ans) printf("%d %d\n", cur.first, cur.second);

	return true;
}

int main() {

	//while(solve());
	solve();	
	
	return 0;
}