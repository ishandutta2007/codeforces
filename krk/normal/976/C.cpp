#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;
typedef pair <ii, int> iii;

const int Maxn = 300005;

int n;
iii my[Maxn];

bool Less(const iii &a, const iii &b)
{
	if (a.first.first != b.first.first) return a.first.first < b.first.first;
	return a.first.second > b.first.second;
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int l, r; scanf("%d %d", &l, &r);
		my[i] = iii(ii(l, r), i + 1);
	}
	sort(my, my + n, Less);
	for (int i = 0; i + 1 < n; i++)
		if (my[i].first.second >= my[i + 1].first.second) {
			printf("%d %d\n", my[i + 1].second, my[i].second);
			return 0;
		}
	printf("-1 -1\n");
	return 0;
}