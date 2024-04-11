#include <bits/stdc++.h>
using namespace std;

#define MAXN 100005

int N, G;
int V[MAXN];

struct {
	int p, t, x;
} A[MAXN];

struct NODE{
	int add, mx;
	NODE *left, *right;
} *root;

NODE *make_tree(int s, int e)
{
	NODE *ret = new NODE();
	if (s == e) return ret;
	int m = s+e >> 1;
	ret->left = make_tree(s, m);
	ret->right = make_tree(m+1, e);
	return ret;
}

void add(NODE *now, int s, int e, int l, int r, int v)
{
	if (e < l || r < s) return;
	if (l <= s && e <= r){
		now->add += v; now->mx += v;
		return;
	}
	int m = s+e >> 1;
	add(now->left, s, m, l, r, v);
	add(now->right, m+1, e, l, r, v);
	now->mx = max(now->left->mx, now->right->mx) + now->add;
}

int find_rightmost(NODE *now, int s, int e, int bound)
{
	// >= bound
	if (s == e) return s;
	int m = s+e >> 1;
	bound -= now->add;
	if (now->right->mx >= bound) return find_rightmost(now->right, m+1, e, bound);
	return find_rightmost(now->left, s, m, bound);
}

int main()
{
	scanf("%d", &N);
	for (int i=1;i<=N;i++){
		int p, t; scanf("%d%d", &p, &t);
		if (t == 1){
			int x; scanf("%d", &x);
			A[i] = {p, t, x};
		}else A[i] = {p, t, 0};
	}

	root = make_tree(1, N);
	for (int i=1;i<=N;i++){
		if (A[i].t == 1){
			add(root, 1, N, 1, A[i].p, 1);
			V[A[i].p] = A[i].x;
		}
		else add(root, 1, N, 1, A[i].p, -1);
		if (root->mx < 1){ puts("-1"); continue; }
		int t = find_rightmost(root, 1, N, 1);
		printf("%d\n", V[t]);
	}
}