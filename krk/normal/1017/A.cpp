#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 1005;

bool Less(const ii &a, const ii &b)
{
	if (a.first != b.first) return a.first > b.first;
	return a.second < b.second;
}

int n;
ii a[Maxn];

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 4; j++) {
			int d; scanf("%d", &d);
			a[i].first += d;
		}
		a[i].second = i;
	}
	sort(a, a + n, Less);
	for (int i = 0; i < n; i++)
		if (a[i].second == 0) { printf("%d\n", i + 1); return 0; }
	return 0;
}