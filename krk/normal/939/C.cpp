#include <bits/stdc++.h>
using namespace std;

const int Maxn = 100005;

int n;
int a[Maxn];
int delt[Maxn];

void Add(int beg, int en, int val)
{
	if (beg < en) { delt[beg] += val; delt[en] -= val; }
	else {
		delt[beg] += val; delt[n] -= val;
		delt[0] += val; delt[en] -= val;
	}
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	int s, f; scanf("%d %d", &s, &f); s--; f--;
	for (int i = 0; i < n; i++) {
		Add(s, f, a[i]);
		s = (s - 1 + n) % n, f = (f - 1 + n) % n;
	}
	for (int i = 1; i < n; i++)
		delt[i] += delt[i - 1];
	int best = 0;
	for (int i = 1; i < n; i++)
		if (delt[i] > delt[best]) best = i;
	printf("%d\n", best + 1);
	return 0;
}