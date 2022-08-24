#pragma comment(linker, "/STACK:1000000000")
#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>
#include <queue>
#include <deque>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <bitset>
#include <memory>
#include <cassert>
#include <cstdlib>
#include <cmath>
#include <ctime> 
#include <stack>
#include <iostream>
#include <functional>
#include <fstream>

#define mp make_pair
#define pb push_back

using ll = long long;
using ld = long double;

using namespace std;

const int MAXN = 3001;

struct node {
	int left;
	int right;
	int parent;
	int id;
};

node nodes[MAXN];
int nodec = 1;



bool block[MAXN];
int n;
int sz[MAXN];

int askcount = 0;

int ask(int x, int y, int z) {
	assert(++askcount <= 10 * n);
	cout << y << " " << z << " " << x << endl;
	cout.flush();
	string s;
	cin >> s;
	if (s == "X") return 0;
	if (s == "Y") return 1;
	if (s == "Z") return 2;
}


void addfrom(int curn, int old) {
	int n2 = curn;
	int n1 = n + curn - 1;
	int oldpar = nodes[old].parent;
	nodes[n1] = { old, n2, oldpar, curn };
	nodes[n2] = { 0, 0, n1, curn };
	nodes[old].parent = n1;
	if (oldpar != 0) {
		if (nodes[oldpar].left == old) nodes[oldpar].left = n1;
		else nodes[oldpar].right = n1;
	}
	nodec += 2;
}

bool leav(int x) {
	return nodes[x].left == 0;
}

bool bleav(int x) {
	return block[x] || leav(x);
}


vector <int> visit;

void  dfs1(int v) {
	if (bleav(v)) {
		sz[v] = 1;
		return;
	}
	visit.push_back(v);
	sz[v] = 1;
	dfs1(nodes[v].left);
	dfs1(nodes[v].right);
	sz[v] += sz[nodes[v].left];
	sz[v] += sz[nodes[v].right];
}



void add(int curid, int curroot) {
	if (bleav(curroot)) {
		addfrom(curid, curroot);
		return;
	}

	visit.clear();
	dfs1(curroot);
	int tot = sz[curroot];
	int ms = curroot;
	for (int i = 0; i < visit.size(); i++) {
		int u = visit[i];
		if ((sz[u] * 2 >= tot) && (sz[u] < sz[ms])) {
			ms = u;
		}
	}
	int f = ask(curid, nodes[nodes[ms].left].id, nodes[nodes[ms].right].id);
	block[ms] = true;
	if (f == 0) {
		add(curid, curroot);
	}
	if (f == 1) {
		add(curid, nodes[ms].right);
	}
	if (f == 2) {
		add(curid, nodes[ms].left);
	}
}

int root;


int main() {
	//freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(0); cout.setf(ios::fixed); cout.precision(20);
	cin >> n;
	nodes[nodec++] = node{ 0, 0, 0, 1 };
	root = 1;
	for (int i = 2; i <= n; i++) {
		memset(block, 0, sizeof(block));
		block[0] = true;
		add(i, root);
		while (nodes[root].parent != 0) root = nodes[root].parent;
	}
	cout << -1 << endl;
	nodes[root].parent = -1;
	for (int i = 1; i <= 2 * n - 1; i++) cout << nodes[i].parent << " ";
	cout << endl;
	cout.flush();
	return 0;
}