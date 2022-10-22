#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 200005;
const int Inf = 1000000000;

int T;
int n, m;
int a[Maxn];

int main()
{
	scanf("%d", &T);
	while (T--) {
		scanf("%d %d", &n, &m);
		for (int i = 0; i < n; i++)
			scanf("%d", &a[i]);
		vector <int> V1, V2;
		for (int i = 0; i < n; i++) {
			int b; scanf("%d", &b);
			if (b == 1) V1.push_back(a[i]);
			else V2.push_back(a[i]);
		}
		sort(V1.rbegin(), V1.rend());
		sort(V2.rbegin(), V2.rend());
		ll fr = 0;
		for (int i = 0; i < V1.size(); i++)
			fr += V1[i];
		int res = Inf;
		int pnt = 0;
		while (pnt < V2.size() && fr < m)
			fr += V2[pnt++];
		if (fr >= m) res = V1.size() + 2 * pnt;
		for (int i = int(V1.size()) - 1; i >= 0; i--) {
			fr -= V1[i];
			while (pnt < V2.size() && fr < m)
				fr += V2[pnt++];
			if (fr >= m) res = min(res, i + 2 * pnt);
		}
		printf("%d\n", res >= Inf? -1: res);
	}
    return 0;
}