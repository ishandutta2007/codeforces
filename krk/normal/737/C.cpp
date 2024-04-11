#include <cstdio>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

const int Maxn = 200005;

int n, s;
int A[Maxn];
vector <int> seq;

int main()
{
	scanf("%d %d", &n, &s);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &A[i]);
		if (i != s) seq.push_back(A[i]);
	}
	if (n == 1) { printf("%d\n", int(A[s] != 0)); return 0; }
	sort(seq.begin(), seq.end());
	int res = Maxn;
	int a = 0, b = 0;
	int pnt = 0;
	while (pnt < seq.size() && seq[pnt] == 0) { pnt++; b++; }
	for (int i = 1; i < Maxn; i++) {
		int opnt = pnt;
		while (pnt < seq.size() && seq[pnt] == i) pnt++;
		if (pnt == opnt) a++;
		res = min(res, int(A[s] != 0) + max(a, b + int(seq.size()) - pnt));
	}
	printf("%d\n", res);
	return 0;
}