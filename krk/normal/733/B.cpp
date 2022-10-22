#include <cstdio>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

const int Maxn = 100005;

int n;
int l[Maxn], r[Maxn];
int L, R;
int best, bi;

int Check(int L, int R) { return abs(L - R); }

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d %d", &l[i], &r[i]);
		L += l[i]; R += r[i];
	}
	best = Check(L, R);
	for (int i = 1; i <= n; i++) {
		int cand = Check(L - l[i] + r[i], R - r[i] + l[i]);
		if (cand > best) { best = cand; bi = i; }
	}
	printf("%d\n", bi);
	return 0;
}