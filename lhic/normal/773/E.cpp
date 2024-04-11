#pragma comment(linker, "/STACK:1000000000")
#define _CRT_SECURE_NO_WARNINGS
#define _SCL_SECURE_NO_WARNINGS
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
#include <fstream>
#include <random>

#define mp make_pair
#define pb push_back

using ll = long long;
using ld = long double;

using namespace std;


mt19937 mt;

struct Node {
	Node* left;
	Node* right;
	int worst;
	int size;
	int key;
	unsigned int prior;

	Node(int x)
		: left (nullptr)
		, right (nullptr)
		, key (x)
		, prior(mt())
		, size(1)
		, worst(x)
	{
	}


};

using PNode = Node*;

const int MAXN = 500001;
const int INF = MAXN * 5;
PNode root = nullptr;

int Size(PNode t) {
	return (t ? (t->size) : 0);
}

int Worst(PNode t) {
	return (t ? (t->worst) : INF);
}


void Update(PNode t) {
	int ls = Size(t->left), rs = Size(t->right);
	t->worst = min(min(Worst(t->left) + rs + 1, t->key + rs), Worst(t->right));
	t->size = ls + rs + 1;
}

void Split(PNode t, PNode& l, PNode& r, int key) {
	if (!t) {
		l = r = nullptr;
		return;
	}
	if (t->key >= key) {
		r = t;
		Split(t->left, l, r->left, key);
	} else {
		l = t;
		Split(t->right, l->right, r, key);
	}
	Update(t);
}

void SplitFind(PNode t, PNode& l, PNode& r, int left = 0) {
	if (!t) {
		l = r = nullptr;
		return;
	}
	int ls = left + Size(t->left);
	if (-ls > t->key) {
		l = t;
		SplitFind(t->right, l->right, r, ls + 1);
	} else {
		r = t;
		SplitFind(t->left, l, r->left, left);
	}
	Update(t);
}


PNode Merge(PNode l, PNode r) {
	if (!l) return r;
	if (!r) return l;
	PNode t;
	if (l->prior > r->prior) {
		t = l;
		t->right = Merge(l->right, r);
	} else {
		t = r;
		t->left = Merge(l, r->left);
	}
	Update(t);
	return t;
}

void insert(int x) {
	PNode n1, n2;
	Split(root, n1, n2, x);
	root = Merge(Merge(n1, new Node(x)), n2);
}

int calcans() {
	PNode n1, n2;
	SplitFind(root, n1, n2, 0);
	int ans = min(-Size(n1) + Size(n2), Worst(n2));
	root = Merge(n1, n2);
	return ans;
}

int main() {
	//freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(0); cout.setf(ios::fixed); cout.precision(20);
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int x;
		scanf("%d", &x);
		insert(x);
		printf("%d\n", calcans());
	}
	return 0;
}