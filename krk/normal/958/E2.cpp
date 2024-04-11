#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;
typedef pair <int, ii> iii;

const int Maxn = 500005;

int k, n;
int a[Maxn];
int sum[Maxn];
set <int> S;
priority_queue <iii> Q;
int res;

int main()
{
	scanf("%d %d", &k, &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	sort(a + 1, a + n + 1);
	for (int i = 2; i <= n; i++)
		sum[i] = a[i] - a[i - 1] + sum[i - 2];
	for (int i = 1; i <= n; i++) {
		S.insert(i);
		if (i + 1 <= n) Q.push(iii(-(a[i + 1] - a[i]), ii(i, i + 1)));
	}
	for (int i = 0; i < k; i++) {
		int d = -Q.top().first;
		ii p = Q.top().second; Q.pop();
		if (S.find(p.first) == S.end() || S.find(p.second) == S.end()) { i--; continue; }
		res += d;
		S.erase(p.first); S.erase(p.second);
		set <int>::iterator it1 = S.lower_bound(p.first);
		if (it1 != S.begin()) {
			it1--;
			set <int>::iterator it2 = S.upper_bound(p.second);
			if (it2 != S.end()) {
				int tot = a[*it2] - a[*it1];
				int nw = sum[*it2] - sum[*it1 - 1];
				int cand = nw - (tot - nw);
				Q.push(iii(-cand, ii(*it1, *it2)));
			}
		}
	}
	printf("%d\n", res);
	return 0;
}