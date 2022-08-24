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
const int MAXN = 3100;

int n, m;
vector<int> eds[MAXN];
vector<int> reds[MAXN];

vector<pair<int, int> > go[MAXN];
vector<pair<int, int> > rgo[MAXN];
int dd[MAXN];
int ddg[MAXN][MAXN];


void bfs(int v) {
	for (int i = 0; i < n; ++i)
		dd[i] = -1;
	dd[v] = 0;
	queue<int> qu;
	qu.push(v);
	while (!qu.empty()) {
		int x = qu.front();
		qu.pop();
		for (int u: eds[x])
			if (dd[u] == -1)
				dd[u] = dd[x] + 1, qu.push(u);
	}
}


void rbfs(int v) {
	for (int i = 0; i < n; ++i)
		dd[i] = -1;
	dd[v] = 0;
	queue<int> qu;
	qu.push(v);
	while (!qu.empty()) {
		int x = qu.front();
		qu.pop();
		for (int u: reds[x])
			if (dd[u] == -1)
				dd[u] = dd[x] + 1, qu.push(u);
	}
}


int main() {
	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;
		--a;
		--b;
		eds[a].push_back(b);
		reds[b].push_back(a);
	}
	for (int i = 0; i < n; ++i) {
		bfs(i);
		int mn1 = i, mn2 = i, mn3 = i;
		for (int j = 0; j < n; ++j) {
			if (i == j)
				continue;
			if (dd[j] == -1)
				continue;
			if (dd[mn3] < dd[j])
				mn3 = j;
			if (dd[mn3] > dd[mn2])
				swap(mn2, mn3);
			if (dd[mn2] > dd[mn1])
				swap(mn1, mn2);
		}
		go[i].push_back(make_pair(mn1, dd[mn1]));
		go[i].push_back(make_pair(mn2, dd[mn2]));
		go[i].push_back(make_pair(mn3, dd[mn3]));
		for (int j = 0; j < n; ++j)
			ddg[i][j] = dd[j];
		rbfs(i);
		mn1 = i, mn2 = i, mn3 = i;
		for (int j = 0; j < n; ++j) {
			if (i == j)
				continue;
			if (dd[j] == -1)
				continue;
			if (dd[mn3] < dd[j])
				mn3 = j;
			if (dd[mn3] > dd[mn2])
				swap(mn2, mn3);
			if (dd[mn2] > dd[mn1])
				swap(mn1, mn2);
		}
		rgo[i].push_back(make_pair(mn1, dd[mn1]));
		rgo[i].push_back(make_pair(mn2, dd[mn2]));
		rgo[i].push_back(make_pair(mn3, dd[mn3]));
	}
	int bst = -1;
	int ba = 0, bb = 0, bc = 0, bd = 0;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j) {
			if (i == j)
				continue;
			if (ddg[i][j] == -1)
				continue;
			for (int i1 = 0; i1 < (int)rgo[i].size(); ++i1)
				for (int j1 = 0; j1 < (int)go[j].size(); ++j1) {
					if (rgo[i][i1].second <= 0)
						continue;
					if (go[j][j1].second <= 0)
						continue;
					int a = rgo[i][i1].first;
					int b = go[j][j1].first;
					if (a == b || a == j || b == i)
						continue;
					int sum = ddg[a][i] + ddg[i][j] + ddg[j][b];
					if (sum > bst) {
						ba = a;
						bb = i;
						bc = j;
						bd = b;
						bst = sum;
					}
				}
		}
	cout << ba + 1 << " " << bb + 1 << " " << bc + 1 << " " << bd + 1 << "\n";
	return 0;
}