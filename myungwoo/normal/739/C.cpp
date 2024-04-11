#include <bits/stdc++.h>
using namespace std;

#define MAXN 300005
typedef long long lld;

int N, Q;
int A[MAXN]; lld B[MAXN];

struct NODE {
	NODE() {
		all = left_hill = right_hill = left_neg = right_pos = size = 0;
		left = right = 0;
	}
	int all, left_hill, right_hill, left_neg, right_pos, size;
	NODE *left, *right;

	void relax() {
		if (!left) return;
		size = left->size + right->size;

		if (left->left_neg == left->size) left_neg = left->size + right->left_neg;
		else left_neg = left->left_neg;
		if (right->right_pos == right->size) right_pos = right->size + left->right_pos;
		else right_pos = right->right_pos;

		left_hill = left->left_hill;
		if (left->left_hill == left->size) left_hill = max(left_hill, left->size + right->left_neg);
		if (left->right_pos == left->size) left_hill = max(left_hill, left->size + right->left_hill);
		right_hill = right->right_hill;
		if (right->right_hill == right->size) right_hill = max(right_hill, right->size + left->right_pos);
		if (right->left_neg == right->size) right_hill = max(right_hill, left->right_hill + right->size);

		all = max({left->all, right->all, left->right_pos + right->left_neg,
			left->right_hill + right->left_neg, left->right_pos + right->left_hill,
			left_hill, right_hill});
		size = left->size + right->size;
	}
} *root;

NODE* build_tree(int s, int e)
{
	NODE *ret = new NODE();
	if (s > e) return ret;
	if (s == e){
		if (B[s] < 0) ret->all = ret->left_hill = ret->right_hill = ret->left_neg = 1;
		if (B[s] > 0) ret->all = ret->left_hill = ret->right_hill = ret->right_pos = 1;
		ret->size = 1;
		return ret;
	}
	int m = s+e >> 1;
	ret->left = build_tree(s, m);
	ret->right = build_tree(m+1, e);
	ret->relax();
	return ret;
}

void update(NODE *now, int s, int e, int t)
{
	if (t < s || e < t) return;
	if (s == e){
		if (B[s] < 0) now->all = now->left_hill = now->right_hill = now->left_neg = 1, now->right_pos = 0;
		if (B[s] > 0) now->all = now->left_hill = now->right_hill = now->right_pos = 1, now->left_neg = 0;
		now->size = 1;
		return;
	}
	int m = s+e >> 1;
	update(now->left, s, m, t);
	update(now->right, m+1, e, t);
	now->relax();
}

int main()
{
	scanf("%d", &N);
	for (int i=1;i<=N;i++) scanf("%d", A+i);
	for (int i=1;i<=N;i++) B[i] = A[i+1] - A[i];
	root = build_tree(1, N-1);
	for (scanf("%d", &Q);Q--;){
		int l, r, v; scanf("%d%d%d", &l, &r, &v);
		B[l-1] += v; B[r] -= v;
		update(root, 1, N-1, l-1);
		update(root, 1, N-1, r);
		printf("%d\n", root->all+1);
	}
}