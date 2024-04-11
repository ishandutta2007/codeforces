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

#include <time.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()
#define mp make_pair
#define mt make_tuple 

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

const ll inf = 1000000000ll;
const ll inf64 = inf * inf;
const ll base = inf + 7;
const ld pi = acos(-1.0);

int n;
vec< int > c, mx;
vec< ll > ans;
vec< vec< int> > g; 

void read() {
	scanf("%d", &n);
	c.resize(n + 1);
	g.resize(n + 1);
	for(int i = 1;i <= n;i++) {
		scanf("%d", &c[i]);
	}
	for(int u, v, i = 0;i < n - 1;i++) {
		scanf("%d %d", &u, &v);
		g[u].push_back(v);
		g[v].push_back(u);
	}
}

vec< map< int, int> > cnt;
// {cnt, color}

void dfs(int v, int p = -1) {
	cnt[v][c[v]] = 1;
	mx[v] = 1;
	ans[v] = c[v];
	for(auto to : g[v]) {
		if(to == p) continue;
		dfs(to, v);
		if((int)cnt[v].size() < (int)cnt[to].size()) {
			swap(cnt[v], cnt[to]);
			ans[v] = ans[to];
			mx[v] = mx[to];
		}
		for(auto i : cnt[to]) {
			int Color = i.first;
			int Cnt_color = i.second;
			cnt[v][Color] += Cnt_color;
			if(cnt[v][Color] == mx[v]) {
				ans[v] += Color;
			}else if(cnt[v][Color] > mx[v]) {
				mx[v] = cnt[v][Color];
				ans[v] = Color;
			}
		}
	}
}

bool solve() {

	read();

	cnt.resize(n + 1);
	ans.resize(n + 1);
	mx.resize(n + 1, -1);

	dfs(1);

	for(int i = 1;i <= n;i++) printf("%I64d ", ans[i]);

	puts("");

	return true;
}

int main() {
	
	//while(solve());
	solve();	

	return 0;
}