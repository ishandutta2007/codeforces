#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <string>
#include <cstring>
#include <sstream>
#include <algorithm>
#pragma comment(linker, "/STACK:16000000")
using namespace std;

const int Maxn = 100005;

int n;
int val[Maxn], L[Maxn], R[Maxn];
int in[Maxn], root;
set <int> S[Maxn];
int my[Maxn];

void Merge(int a, int b)
{
	if (S[my[a]].size() < S[my[b]].size()) swap(a, b);
	for (set <int>::iterator it = S[my[b]].begin(); it != S[my[b]].end(); it++)
		S[my[a]].insert(*it);
	S[my[b]].clear(); my[b] = my[a];
}

void remEnd(set <int> &S, int val)
{
	set <int>::iterator it = S.end();
	while (it != S.begin()) {
		it--;
		if (*it > val) S.erase(it++);
		else break;
	}
}

void remSt(set <int> &S, int val)
{
	set <int>::iterator it = S.begin();
	while (it != S.end())
		if (val > *it) S.erase(it++);
		else break;
}

void Traverse(int v)
{
	my[v] = v; S[my[v]].insert(val[v]);
	if (L[v] != -1) {
		Traverse(L[v]); remEnd(S[my[L[v]]], val[v]);
		Merge(v, L[v]);
	}
	if (R[v] != -1) {
		Traverse(R[v]); remSt(S[my[R[v]]], val[v]);
		Merge(v, R[v]);
	}
}

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d %d %d", &val[i], &L[i], &R[i]);
		if (L[i] != -1) in[L[i]]++;
		if (R[i] != -1) in[R[i]]++;
	}
	root = 1;
	while (in[root]) root++;
	Traverse(root);
	int ans = 0;
	for (int i = 1; i <= n; i++)
		ans += S[my[root]].find(val[i]) == S[my[root]].end();
	printf("%d\n", ans);
	return 0;
}