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

const int NMAX = 1010;
char buff[NMAX];

int n, m;
vec< string > mat;

void move(int & mask, int cnt = 1) {
	for(int iter = 0;iter < cnt;iter++) {
		int x = (8 & mask?1 : 0);
		mask &= 7;
		mask <<= 1;
		mask |= x;
	}
}

int get_mask(pii v) {
	char c = mat[v.first][v.second];
	int mask = 0;
	if(c == '+') mask = 15;
	else if(c == '-') mask = (1 << 0) | (1 << 2);
	else if(c == '|') mask = (1 << 1) | (1 << 3);
	else if(c == '^') mask = 1 << 1;
	else if(c == '>') mask = 1 << 2;
	else if(c == '<') mask = 1 << 0;
	else if(c == 'v') mask = 1 << 3;
	else if(c == 'L') mask = 15 ^ 1;
	else if(c == 'R') mask = 15 ^ 4;
	else if(c == 'U') mask = 15 ^ 2;
	else if(c == 'D') mask = 15 ^ 8;
	else mask = 0;
	return mask;
} 

bool can(int ty, pii u, pii v) {
	int m1, m2;
	m1 = get_mask(u); 
	m2 = get_mask(v);
	move(m1, ty);
	move(m2, ty);
	if(u.first == v.first && u.second + 1 == v.second) { // toRight
		m1 = (m1 & 4?1 : 0);
		m2 = (m2 & 1?1 : 0);
	}else if(u.first == v.first && u.second - 1 == v.second) { // toLeft
		m1 = (m1 & 1?1 : 0);
		m2 = (m2 & 4?1 : 0);
	}else if(u.second == v.second && u.first - 1 == v.first) { // toUp
		m1 = (m1 & 2?1 : 0);
		m2 = (m2 & 8?1 : 0);
	}else { // toDown
		m1 = (m1 & 8?1 : 0);
		m2 = (m2 & 2?1 : 0);
	}
	return (m1 == 1 && m2 == 1);
}

void genTo(vec< pair< int, pii > > & g, int ty, pii v) {
	g.clear();
	g.push_back(mp((ty + 1) % 4, v));
	for(int di = -1;di <= 1;di++) {
		for(int dj = -1;dj <= 1;dj++) {
			if(di == 0 && dj == 0) continue;
			if(di != 0 && dj != 0) continue;
			int toi, toj;
			toi = v.first + di;
			toj = v.second + dj;
			if(toi < 0 || toi >= n || toj < 0 || toj >= m) continue;
			if(can(ty, v, mp(toi, toj))) g.push_back(mp(ty, mp(toi, toj)));
		}
	}
} 

bool solve() {
	
	scanf("%d %d", &n, &m);

	mat.resize(n);

	for(int i = 0;i < n;i++) {
		scanf("%s", &buff);
		mat[i] = buff;
	}

	pii s, f;

	cin >> s.first >> s.second;
	cin >> f.first >> f.second;

	s.first--;
	s.second--;
	f.first--;
	f.second--;

	vec< vec< vec< int > > > d(4, vec< vec< int > >(n, vec< int >(m, inf)));
	queue< pair< int, pii > > q;
	pair< int, pii > tmp;
	vec< pair< int, pii > > g;

	q.push(mp(0, s));
	d[0][s.first][s.second] = 0;
	
	while(!q.empty()) {
		tmp = q.front();
		q.pop();
		int ty = tmp.first;
		pii v = tmp.second;
		genTo(g, ty, v);
		auto dv = d[ty][v.first][v.second];
		for(auto cur : g) {
			auto & dto = d[cur.first][cur.second.first][cur.second.second];
			if(dto > dv + 1) {
				dto = dv + 1;
				q.push(cur);
			}
		}
	}

	int res = inf;

	for(int i = 0;i < 4;i++) {
		res = min(res, d[i][f.first][f.second]);
	}

	printf("%d\n", res == inf?-1 : res);

	return true;
}

int main() {
	
	//while(solve());
	solve();

	return 0;
}