#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 200005;
const int Maxm = 5000005;

int n;
ii a[Maxn];
ii my[Maxm];
ii seq[Maxn];
int slen;

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i].first);
		a[i].second = i + 1;
	}
	sort(a, a + n);
	int p1 = 0;
	while (p1 + 1 < n && a[p1].first != a[p1 + 1].first) p1++;
	int p2 = p1 + 2;
	while (p2 + 1 < n && a[p2].first != a[p2 + 1].first) p2++;
	if (p2 + 1 < n) {
		printf("YES\n");
		printf("%d %d %d %d\n", a[p1].second, a[p2].second, a[p1 + 1].second, a[p2 + 1].second);
		return 0;
	}
	ii spec1 = ii(0, 0), spec2;
	for (int i = 0; i < n; i++)
		if (i + 1 >= n || a[i].first != a[i + 1].first)
			seq[slen++] = a[i];
		else { spec1 = a[i]; spec2 = a[i + 1]; }
	for (int i = 0; i < slen; i++)
		for (int j = i + 1; j < slen; j++) {
			int sum = seq[i].first + seq[j].first;
			if (my[sum].first) {
				printf("YES\n");
				printf("%d %d %d %d\n", seq[i].second, seq[j].second, my[sum].first, my[sum].second);
				return 0;
			}
			my[sum] = ii(seq[i].second, seq[j].second);
		}
	if (spec1.first) {
		int sum = spec1.first + spec2.first;
		if (my[sum].first) {
			printf("YES\n");
			printf("%d %d %d %d\n", spec1.second, spec2.second, my[sum].first, my[sum].second);
			return 0;
		}
	}
	printf("NO\n");
    return 0;
}