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

int n, m;
vec< vec< int > > g, a;

void read() {
	scanf("%d %d", &n, &m);	
	g.resize(n + 1);
	for(int u, v, i = 0;i < n - 1;i++) {
		scanf("%d %d", &u, &v);
		g[u].push_back(v);
		g[v].push_back(u);
	}
}

vec< int > tmp;

void dfs(int v, int par = 1) {
	tmp.push_back(v);
	for(auto to : g[v]) if(to != par) dfs(to, v);
}

bool solve() {

	read();

	for(auto to : g[1]) {
		dfs(to);
		a.push_back(tmp);
		tmp.clear();
	}

	int at_one = 0;
	int cnt_list = (int)a.size();

	vec< int > id_list(n + 1), pos(n + 1), all(n);
	vec< vec< int > > s(cnt_list);

	for(int i = 0;i < cnt_list;i++) {
		for(int j = 0;j < (int)a[i].size();j++) {
			int v = a[i][j];
			id_list[v] = i;
			pos[v] = j;
		}
		s[i].resize((int)a[i].size());
	}

	for(int ty, v, x, d;m;m--) {
		scanf("%d %d", &ty, &v);

		int idl, ps;
		idl = id_list[v];
		ps  = pos[v];

		if(ty == 0) {
			scanf("%d %d", &x, &d);

			if(v == 1) {
				at_one += x;
				for(int j = 0;j < n;j |= (j + 1)) all[j] += x;
				for(int j = d;j < n;j |= (j + 1)) all[j] -= x;
			}else {

				if(ps + 1 - d >= 0) {
					if(ps + 1 - d == 0) at_one += x;
					int l, r;
					l = max(0, ps - d);
					r = min((int)a[idl].size() - 1, ps + d);
					for(int j = l;j < (int)a[idl].size();j |= (j + 1)) s[idl][j] += x;
					for(int j = r + 1;j < (int)a[idl].size();j |= (j + 1)) s[idl][j] -= x;
				}else {
					int t = d - ps - 1;
				
					// all : [0 .. t - 1]
					for(int j = 0;j < n;j |= (j + 1)) all[j] += x;
					for(int j = t;j < n;j |= (j + 1)) all[j] -= x;

					// own : [t .. ps + d]
					for(int j = t;j < (int)a[idl].size();j |= (j + 1)) s[idl][j] += x;
					for(int j = ps + d + 1;j < (int)a[idl].size();j |= (j + 1)) s[idl][j] -= x;

					at_one += x;
				}
			}

		}else {
		
			if(v == 1) printf("%d\n", at_one);
			else {
				int ans = 0;
				for(int j = ps;j >= 0;j = (j & (j + 1)) - 1) ans += s[idl][j] + all[j];
				printf("%d\n", ans);
			}

		}
	}

	return true;
}

int main() {

	//while(solve());
	solve();
	
	return 0;
}