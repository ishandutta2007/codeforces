#include <iostream>
#include <cmath>
#include <math.h>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <tuple>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()
#define mp make_pair
#define mt make_tuple 

typedef long long ll;
typedef double ld;
typedef unsigned long long ull;

const ll inf = 1000000000ll;
const ll inf64 = inf * inf;
const ll base = inf + 7;

inline void read(string & s) {
	char buffer[1010];
	scanf("%s", &buffer);
	s = buffer;
}

int n, m, k;

vec< string > a;

void read() {
	scanf("%d %d %d", &n, &m, &k);
	a.resize(n);
	for(int i = 0;i < n;i++) read(a[i]);
}

vec< int > size, par, sum;

int find(int x) {
	return (par[x] == x?x : par[x] = find(par[x]));
}

void merge(int x, int y) {
	int px = find(x);
	int py = find(y);

	if(size[px] == size[py]) {
		par[py] = px;
		size[px]++;
		sum[px] += sum[py];
	}else {
		if(size[px] < size[py]) swap(px, py);
		par[py] = px;
		sum[px] += sum[py];
	}
}

void precalc() {
	size.resize(n * m);
	par.resize(n * m);
	sum.resize(n * m);

	for(int i = 0;i < n * m;i++) {
		size[i] = 0;
		par[i] = i;
		sum[i] = 0;
	}

	for(int i = 0;i < n;i++) {
		for(int j = 0;j < m;j++) {
			if(a[i][j] == '*') continue;
			for(int di = -1;di <= 1;di++) {
				for(int dj = -1;dj <= 1;dj++) {
					if(di == 0 && dj == 0) continue;
					if(di != 0 && dj != 0) continue;
					int toi, toj;
					toi = i + di;
					toj = j + dj;
					if(toi < 0 || toi >= n) continue;
					if(toj < 0 || toj >= m) continue;
					if(a[toi][toj] == '*') sum[i * m + j]++; 
				}
			}
		}
	}

	for(int i = 0;i < n;i++) {
		for(int j = 0;j + 1 < m;j++) {
			if(a[i][j] == '.' && a[i][j + 1] == '.') {
				int id1 = i * m + j;
				int id2 = i * m + j + 1;
				if(find(id1) != find(id2)) merge(id1, id2);
			}
		}
	}

	for(int j = 0;j < m;j++) {
		for(int i = 0;i + 1 < n;i++) {
			if(a[i][j] == '.' && a[i + 1][j] == '.') {
				int id1 = i * m + j;
				int id2 = (i + 1) * m + j;
				if(find(id1) != find(id2)) merge(id1, id2);
			}
		}
	}
}

bool solve()
{
	read();	
	precalc();

	for(int x, y;k;k--) {
		scanf("%d %d", &x, &y);
		x--, y--;
		int p = find(x * m + y);
		printf("%d\n", sum[p]);
	}

	return true;
} 

int main() {

	//while(solve());
	solve();	

	return 0;
}