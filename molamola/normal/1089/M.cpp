#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
#include <math.h>
#include <assert.h>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <string>
#include <algorithm>
#include <iostream>
#include <functional>
#include <unordered_set>
#include <bitset>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define Fi first
#define Se second
#define pb(x) push_back(x)
#define szz(x) (int)x.size()
#define rep(i,n) for(int i=0;i<n;i++)
#define all(x) x.begin(),x.end()
typedef tuple<int, int, int> t3;

int E[12][12];
vector <int> scc[12], v;
int sid[12], color[12], n;
int X[12][12];

void dfs(int x) {
	color[x] = 1;
	for(int i=1;i<=n;i++) if(E[x][i] && color[i] == 0) dfs(i);
	v.pb(x);
}

char ans[50][30][30];

void dfs2(int x, int sn) {
	color[x] = 2;
	sid[x] = sn; scc[sn].pb(x);
	for(int i=1;i<=n;i++) if(E[i][x] && color[i] == 1) dfs2(i, sn);
}

int main() {
	scanf("%d", &n);
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) {
		int x; scanf("%d", &x);
		E[i][j] = x;
	}
	for(int i=1;i<=n;i++) if(color[i] == 0) dfs(i);
	reverse(all(v));
	int snum = 0;
	for(int e : v) if(color[e] == 1) dfs2(e, ++snum);
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) if(E[i][j]) X[sid[i]][sid[j]] = 1;
	int A = 17, B = 11, C = 37;
	printf("%d %d %d\n", A, B, C);
	for(int i=1;i<=C;i++) {
		if(i % 4 != 0) {
			for(int j=1;j<=B;j++) for(int k=1;k<=A;k++) ans[i][j][k] = '.';
		}
		else {
			int xi = i / 4;
			for(int k=1;k<=A;k++) ans[i][1][k] = '#';
			for(int j=2;j<=B;j++) {
				for(int k=1;k<=A;k++) {
					if(k % 2 == 0) ans[i][j][k] = '.';
					else {
						int xk = (k + 1) / 2;
						if(xi == xk) {
							if(j-2 < szz(scc[xi])) ans[i-1][j][k] = '0' + scc[xi][j-2];
							ans[i][j][k] = '#';
						}
						else if(!X[xi][xk]) {
							ans[i][j][k] = (j == 2 ? '#' : '.');
							if(j == 2) {
								ans[i-1][j][k] = '#';
								ans[i-2][1][k] = '#';
							}
						}
						else {
							ans[i][j][k] = (j == 2 ? '#' : '.');
						}
					}
				}
			}
		}
	}
	for(int i=1;i<=C;i++) {
		for(int j=1;j<=B;j++) printf("%s\n", ans[i][j] + 1);
		puts("");
	}
	
	return 0;
}