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

const int Maxn = 200005;
const int Maxm = 105;

int n, q, m;
int a[Maxn];
int t[Maxn], l[Maxn], r[Maxn];
ii imp[Maxm];
int res[Maxm];

int main()
{
	scanf("%d %d %d", &n, &q, &m);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	for (int i = 1; i <= q; i++)
		scanf("%d %d %d", &t[i], &l[i], &r[i]);
	for (int i = 1; i <= m; i++) {
		scanf("%d", &imp[i].first); imp[i].second = i;
	}
	for (int i = q; i > 0; i--)
		if (t[i] == 1) {
			for (int j = 1; j <= m; j++)
				if (l[i] <= imp[j].first && imp[j].first <= r[i])
					if (imp[j].first == l[i]) imp[j].first = r[i];
					else imp[j].first--;
		} else for (int j = 1; j <= m; j++)
				if (l[i] <= imp[j].first && imp[j].first <= r[i])
					imp[j].first = l[i] + r[i] - imp[j].first;
	for (int i = 1; i <= m; i++)
		res[imp[i].second] = a[imp[i].first];
	for (int i = 1; i <= m; i++)
		printf("%d%c", res[i], i + 1 <= m? ' ': '\n');
	return 0;
}