#include <stdio.h>
#include <math.h>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
using namespace std;

vector<int> G[100100];
int N, D[100100], U[100100], X, P, Q;
int S[100100], E[100100], C, V[100100], O[100100], chk[100100];

void dfs(int x, int l)
{
	D[x] = D[l] + 1;
	if (D[X] < D[x]) X = x;
	for (auto &y : G[x]) if (y != l) dfs(y, x);
}

void make(int x, int l)
{
	U[x] = l;
	D[x] = D[l] + 1;

	if (x != Q && G[x].size() == 1)
	{
		S[x] = E[x] = C;
		V[C] = D[x] - 1;
		O[C] = x;
		C++;
	}
	else {
		S[x] = N+1;
		E[x] = -1;
	}
	for (auto &y : G[x]) if (y != l) {
		make(y, x);
		if (S[x] > S[y]) S[x] = S[y];
		if (E[x] < E[y]) E[x] = E[y];
	}
}

const int Z = 1 << 17;
struct node {
	int sum, max, pos;

	node operator +(node t) {
		node r;
		r.sum = sum + t.sum;
		if (max < sum + t.max) {
			r.max = sum + t.max;
			r.pos = t.pos;
		}
		else {
			r.max = max;
			r.pos = pos;
		}
		return r;
	}
}IT[Z*2];

void push(int x, int p)
{
	x += Z;
	IT[x].sum += p; IT[x].max += p; x /= 2;
	while (x) {
		IT[x] = IT[x * 2] + IT[x * 2 + 1];
		x /= 2;
	}
}

void proc()
{
	scanf("%d", &N);
	for (int i = 1; i < N; i++) {
		int x, y; scanf("%d %d", &x, &y);
		G[x].push_back(y);
		G[y].push_back(x);
	}

	X = 0, dfs(1, 0); P = X;
	X = 0, dfs(P, 0); Q = X;

	int sum = 1, k = 1;
	printf("%d", 1);

	make(Q, 0);

	for (int i = 0; i < C; i++) IT[i + Z] = { 0,0,i };
	for (int i = C; i < Z; i++) IT[i + Z] = { -1,-1,-1 };
	for (int i = Z - 1; i >= 1; i--) IT[i] = IT[i * 2] + IT[i * 2 + 1];

	for (int i = 0; i < C; i++) {
		push(i, V[i]);
		push(i+1, -V[i]);
	}

	chk[Q] = 1;
	while (k < N) {
		if (IT[1].max > 0) {
			sum += IT[1].max;
			int x = O[IT[1].pos];
			while (!chk[x]) {
				chk[x] = 1;
				push(S[x], -1);
				push(E[x] + 1, 1);
				x = U[x];
			}
		}
		printf(" %d", sum);
		k++;
	}
}

int main()
{
#ifdef __LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	proc();
	return 0;
}