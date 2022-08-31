#include <iostream>
#include <fstream>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <bitset>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cassert>
#include <queue>


typedef long long ll;
typedef long double ld;

using namespace std;

const int MAXN = 300000;


int cl[MAXN];
int was1[MAXN];
int was2[MAXN];

int n, m;

set<pair<int, int> > ss1;
set<pair<int, int> > ss2;

vector<int> eds1[MAXN];
vector<int> eds2[MAXN];
int fl[MAXN];

int lst = 0;


int go1[MAXN];
int go2[MAXN];

void dfs1(int v) {
	was1[v] = 1;
	for (int i = 0; i < (int)eds1[v].size(); ++i) {
		int u = eds1[v][i];
		int u2 = abs(u) - 1;
		if (was2[u2])
			continue;
		ss2.erase(make_pair(go2[u2], u2));
		--go2[u2];
		ss2.insert(make_pair(go2[u2], u2));
	}
}


void dfs2(int v) {
	was2[v] = 1;
	for (int i = 0; i < (int)eds2[v].size(); ++i) {
		int u = eds2[v][i];
		int u2 = abs(u) - 1;
		if (was1[u2])
			continue;
		ss1.erase(make_pair(go1[u2], u2));
		--go1[u2];
		ss1.insert(make_pair(go1[u2], u2));
		if ((cl[v] == 0 && u < 0) || (cl[v] == 1 && u > 0))
			dfs1(u2);
	}
}



int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++i) {
		int k;
		scanf("%d", &k);
		go1[i] = k;
		for (int j = 0; j < k; ++j) {
			int a;
			scanf("%d", &a);
			eds1[i].push_back(a);
			if (a < 0) {
				a = -a;
				--a;
				fl[a] |= 1;
				eds2[a].push_back(-(i + 1));
			}
			else {
				--a;
				fl[a] |= 2;
				eds2[a].push_back(i + 1);
			}
		}
	}
	for (int i = 0; i < m; ++i)
		go2[i] = eds2[i].size();
	for (int i = 0; i < m; ++i) {
		if (fl[i] == 0) {
			cl[i] = 0;
			was2[i] = 1;
		}
		else if (fl[i] == 1) {
			cl[i] = 0;
			dfs2(i);
		}
		else if (fl[i] == 2) {
			cl[i] = 1;
			dfs2(i);
		}
	}
	for (int i = 0; i < n; ++i)
		ss1.insert(make_pair(go1[i], i));
	for (int i = 0; i < m; ++i)
		ss2.insert(make_pair(go2[i], i));
	int ch = 1;
	while (true) {
		ch = 0;
		while (!ss1.empty() && ss1.begin()->first <= 1) {
			ch = 1;
			int x = ss1.begin()->second;
			ss1.erase(ss1.begin());
			if (was1[x])
				continue;
			was1[x] = 1;
			int fll = 0;
			for (int j = 0; j < (int)eds1[x].size(); ++j) {
				int u = eds1[x][j];
				if (was2[abs(u) - 1])
					continue;
				fll = 1;
				if (u < 0) {
					cl[abs(u) - 1] = 0;
					dfs2(abs(u) - 1);
				}
				else {
					cl[abs(u) - 1] = 1;
					dfs2(abs(u) - 1);
				}
			}
			if (!fll) {
				cout << "NO\n";
				return 0;
			}
		}
		while (!ss2.empty() && ss2.begin()->first <= 1) {
			ch = 1;
			int x = ss2.begin()->second;
			ss2.erase(ss2.begin());
			if (was2[x])
				continue;
			was2[x] = 1;
			for (int j = 0; j < (int)eds2[x].size(); ++j) {
				int u = eds2[x][j];
				if (was1[abs(u) - 1])
					continue;
				if (u < 0) {
					cl[x] = 0;
					dfs2(x);
				}
				else {
					cl[x] = 1;
					dfs2(x);
				}
			}
		}
		if (!ch) {
			while (lst < n) {
				if (was1[lst]) {
					++lst;
					continue;
				}
				int fll = 0;
				for (int j = 0; j < (int)eds1[lst].size(); ++j) {
					int u = eds1[lst][j];
					int u2 = abs(u) - 1;
					if (was2[u2])
						continue;
					fll = 1;
					if (u < 0) {
						cl[u2] = 0;
						dfs2(u2);
					}
					else {
						cl[u2] = 1;
						dfs2(u2);
					}
					break;
				}
				if (!fll) {
					cout << "NO\n";
					return 0;
				}
				++lst;
				break;
			}
			if (lst == n)
				break;
		}
	}
	printf("YES\n");
	for (int i = 0; i < m; ++i)
		printf("%d", cl[i]);
	return 0;
}