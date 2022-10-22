#include <cstdio>
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <deque>
#include <algorithm>
using namespace std;

typedef long double ld;
typedef pair <ld, ld> ldld;

const int Maxk = 52;

int n, k;
ld A[Maxk], X[Maxk], B[Maxk];
deque <ldld> Q[Maxk];

ld Eval(const ldld &p, ld A, ld X, ld B, ld x) { return p.first + A + X * p.second + (p.second + B) * x; }

ld Get(int ind, ld x)
{
	while (Q[ind].size() >= 2 && Eval(Q[ind][0], A[ind], X[ind], B[ind], x) > Eval(Q[ind][1], A[ind], X[ind], B[ind], x))
		Q[ind].pop_front();
	return Eval(Q[ind][0], A[ind], X[ind], B[ind], x);
}

ld GetX(const ldld &a, const ldld &b, ld X)
{
	return (b.first + X * b.second - a.first - X * a.second) / (a.second - b.second);
}

void Insert(int ind, ldld p)
{
	p.second = p.second - B[ind];
	p.first = p.first - A[ind] - X[ind] * p.second;
	while (Q[ind].size() >= 1 && p.first + A[ind] + X[ind] * p.second <= Q[ind].back().first + A[ind] + X[ind] * Q[ind].back().second)
		Q[ind].pop_back();
	while (Q[ind].size() >= 2) {
		ld x1 = GetX(p, Q[ind].back(), X[ind]);
		ld x2 = GetX(Q[ind][Q[ind].size() - 2], Q[ind].back(), X[ind]);
		if (x1 <= x2) Q[ind].pop_back();
		else break;
	}
	Q[ind].push_back(p);
}

int main()
{
	scanf("%d %d", &n, &k);
	for (int i = 0; i <= k; i++)
		Q[i].push_back(ldld(0, 0));
	for (int i = 0; i + 1 < n; i++) {
		int t; scanf("%d", &t);
		for (int j = k - 1; j >= 0; j--) {
			ld my = 1.0l / t;
			ld got = Get(j, my) + 1;
			B[j] += t; A[j] += B[j] * my; X[j] += my;
			Insert(j + 1, ldld(got, 0));
		}
	}
	int t; scanf("%d", &t);
	ld my = 1.0l / t;
	cout << fixed << setprecision(15) << Get(k - 1, my) + 1 << endl;
	return 0;
}