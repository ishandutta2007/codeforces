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
using namespace std;

typedef pair <int, int> ii;

const int Inf = 1000000000;
const int Maxm = 100005;

int n, c, d;
ii A[Maxm][2], B[Maxm][2];
int res = -Inf;

void Insert(ii A[], ii val)
{
	if (val.first > A[0].first) A[1] = A[0], A[0] = val;
	else if (val.first > A[1].first) A[1] = val;
}

ii Get(ii A[], int forb)
{
	if (A[0].second == forb) return A[1];
	return A[0];
}

int main()
{
	scanf("%d %d %d", &n, &c, &d);
	fill((ii*)A, (ii*)A + Maxm * 2, ii(-Inf, -Inf));
	fill((ii*)B, (ii*)B + Maxm * 2, ii(-Inf, -Inf));
	for (int i = 0; i < n; i++) {
		int b, p; char typ; scanf("%d %d %c", &b, &p, &typ);
		if (typ == 'C') Insert(A[p], ii(b, i));
		else Insert(B[p], ii(b, i));
	}
	for (int i = 0; i + 1 < Maxm; i++)
		for (int j = 0; j < 2; j++) {
			Insert(A[i + 1], A[i][j]);
			Insert(B[i + 1], B[i][j]);
		}
	res = max(res, Get(A[c], -1).first + Get(B[d], -1).first);
	for (int i = 0; i <= c; i++) {
		ii got = Get(A[i], -1);
		ii got2 = Get(A[c - i], got.second);
		res = max(res, got.first + got2.first);
	}
	for (int i = 0; i <= d; i++) {
		ii got = Get(B[i], -1);
		ii got2 = Get(B[d - i], got.second);
		res = max(res, got.first + got2.first);
	}
	if (res < 0) res = 0;
	printf("%d\n", res);
	return 0;
}