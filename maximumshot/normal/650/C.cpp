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

const int inf = 1000000000;
const ll inf64 = 1ll * inf * inf;
const double pi = acos(-1.0);

vec< int > crd;
int SZ;

int bp(int x) {
	int bl, br, bm;
	bl = 0;
	br = SZ - 1;
	while(br - bl > 1) {
		bm = (bl + br) / 2;
		if(crd[bm] >= x) br = bm;
		else bl = bm + 1;
	}
	if(crd[bl] == x) return bl;
	else return br;
}

// ---

int n, m;
vec< vec< int > > a;
vec< vec< pii > > pos;

int VALUE;

bool cmp_x(int i, int j) {
	return pos[VALUE][i] < pos[VALUE][j];
}

bool cmp_y(int i, int j) {
	return mp(pos[VALUE][i].second, pos[VALUE][i].first) < 
		mp(pos[VALUE][j].second, pos[VALUE][j].first);
} 

bool solve() {

	scanf("%d %d", &n, &m);

	a.resize(n, vec< int >(m));

	for(int i = 0;i < n;i++) {
		for(int j = 0;j < m;j++) {
			scanf("%d", &a[i][j]);
			crd.push_back(a[i][j]);
		}
	}

	sort(ALL(crd));
	crd.resize(unique(ALL(crd)) - crd.begin());
	SZ = (int)crd.size();

	pos.resize(SZ);

	for(int i = 0;i < n;i++) {
		for(int j = 0;j < m;j++) {
			a[i][j] = bp(a[i][j]);
			pos[a[i][j]].push_back(mp(i, j));
		}
	}

	vec< vec< int > > b(n, vec< int >(m));
	vec< int > mx_str(n), mx_col(m);

	vec< int > perm(n * m), tmp;
	vec< vec< int > > g(n * m);
	bool used[1000100], vis[1000100];
	queue< int > q;

	for(int x = 0;x < SZ;x++) {
		
		VALUE = x;

		int N = (int)pos[x].size();

		for(int i = 0;i < N;i++) {
			perm[i] = i;
			g[i].clear();
		}

		sort(perm.begin(), perm.begin() + N, cmp_x);

		for(int it = 0;it + 1 < N;it++) {
			int u, v;
			u = perm[it];
			v = perm[it + 1];
			if(pos[x][u].first == pos[x][v].first) g[u].push_back(v), g[v].push_back(u);
		}

		sort(perm.begin(), perm.begin() + N, cmp_y);

		for(int it = 0;it + 1 < N;it++) {
			int u, v;
			u = perm[it];
			v = perm[it + 1];
			if(pos[x][u].second == pos[x][v].second) g[u].push_back(v), g[v].push_back(u);
		}

		for(int i = 0;i < N;i++) {
			sort(ALL(g[i]));
			g[i].resize(unique(ALL(g[i])) - g[i].begin());
		}

		for(int i = 0;i < N;i++) used[i] = vis[i] = 0;

		for(int s = 0;s < N;s++) {
			if(used[s]) continue;

			q.push(s);
			used[s] = 1;

			tmp.clear();

			while(!q.empty()) {
				int v = q.front();
				q.pop();
				tmp.push_back(v);
				for(auto to : g[v]) {
					if(!used[to]) used[to] = 1, q.push(to);
				}
			}

			int mx = 1;

			for(int it = 0;it < (int)tmp.size();it++) {
				int v = tmp[it];
				int I, J;
				I = pos[x][v].first;
				J = pos[x][v].second;
				mx = max(mx, mx_str[I] + 1);
				mx = max(mx, mx_col[J] + 1);
			}

			for(int it = 0;it < (int)tmp.size();it++) {
				int v = tmp[it];
				int I, J;
				I = pos[x][v].first;
				J = pos[x][v].second;
				b[I][J] = mx;
				mx_str[I] = max(mx_str[I], mx);
				mx_col[J] = max(mx_col[J], mx);
			}
		}
	} 

	for(int i = 0;i < n;i++) {
		for(int j = 0;j < m;j++) {
			printf("%d ", b[i][j]);
		}
		printf("\n");
	}

	return true;
}

int main() {

	//while(solve());
	solve();	
	
	return 0;
}