#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <string>
#include <cstring>
#include <sstream>
#include <queue>
#include <iomanip>
#include <algorithm>
#pragma comment(linker, "/STACK:16000000")
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 100005;
const int Maxl = 20;
const int lim = 1000000000;

struct node {
	int num;
	node *lef, *rig;
	node() { num = 0; lef = rig = NULL; }
};

char tmp1[Maxl], tmp2[Maxl];
int q;
map <string, int> ID;
node *arr[Maxn], *tree[Maxn];

int getNum(node *v) { return v? v->num: 0; }

node *getLeft(node *v) { return v? v->lef: NULL; }

node *getRight(node *v) { return v? v->rig: NULL; }

void Add(node *v1, node *v2, int l, int r, int x, int val)
{
	v1->num = getNum(v2) + val;
	v1->lef = getLeft(v2);
	v1->rig = getRight(v2);
	if (l < r) {
		int m = l + r >> 1;
		if (x <= m) {
			v1->lef = new node();
			Add(v1->lef, getLeft(v2), l, m, x, val);
		} else {
			v1->rig = new node();
			Add(v1->rig, getRight(v2), m + 1, r, x, val);
		}
	}
}

int getSum(node *v, int l, int r, int x)
{
	if (!v) return 0;
	if (l == r) return 0;
	else {
		int m = l + r >> 1;
		if (m < x) return getNum(v->lef) + getSum(v->rig, m + 1, r, x);
		else return getSum(v->lef, l, m, x);
	}
}

void Change(node *v1, node *v2, int l, int r, int x, int val)
{
	v1->num = getNum(v2);
	v1->lef = getLeft(v2);
	v1->rig = getRight(v2);
	if (l == r) v1->num = val;
	else {
		int m = l + r >> 1;
		if (x <= m) {
			v1->lef = new node();
			Change(v1->lef, getLeft(v2), l, m, x, val);
		} else {
			v1->rig = new node();
			Change(v1->rig, getRight(v2), m + 1, r, x, val);
		}
	}
}

int getVal(node *v, int l, int r, int x)
{
	if (!v) return -1;
	if (l == r) return v->num;
	else {
		int m = l + r >> 1;
		if (x <= m) return getVal(v->lef, l, m, x);
		else return getVal(v->rig, m + 1, r, x);
	}
}

int getID(const string &s)
{
	map <string, int>::iterator it = ID.find(s);
	if (it == ID.end()) {
		int ind = ID.size();
		ID[s] = ind;
		return ind;
	}
	return it->second;
}

int main()
{
	scanf("%d", &q);
	for (int i = 1; i <= q; i++) {
		scanf("%s", tmp1);
		if (tmp1[0] == 'u') {
			int d; scanf("%d", &d);
			arr[i] = arr[i - 1 - d];
			tree[i] = tree[i - 1 - d];
		} else {
			scanf("%s", tmp2); int a = getID(tmp2);
			if (tmp1[0] == 's') {
				int x; scanf("%d", &x);
				int g = getVal(arr[i - 1], 0, Maxn, a);
				arr[i] = new node(); Change(arr[i], arr[i - 1], 0, Maxn, a, x);
				node *nw = tree[i - 1];
				if (g != -1) { nw = new node(); Add(nw, tree[i - 1], 0, lim, g, -1); }
				tree[i] = new node(); Add(tree[i], nw, 0, lim, x, 1);
			} else if (tmp1[0] == 'r') {
				int g = getVal(arr[i - 1], 0, Maxn, a);
				if (g == -1) { arr[i] = arr[i - 1]; tree[i] = tree[i - 1]; continue; }
				arr[i] = new node(); Change(arr[i], arr[i - 1], 0, Maxn, a, -1);
				tree[i] = new node(); Add(tree[i], tree[i - 1], 0, lim, g, -1);
			} else if (tmp1[0] == 'q') {
				int g = getVal(arr[i - 1], 0, Maxn, a);
				if (g == -1) printf("-1\n");
				else printf("%d\n", getSum(tree[i - 1], 0, lim, g));
				fflush(stdout);
				arr[i] = arr[i - 1];
				tree[i] = tree[i - 1];
			}
		}
	}
	return 0;
}