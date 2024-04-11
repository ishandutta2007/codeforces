#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 100005;

int T;
int n;
int w[Maxn];
vector <int> neigh[Maxn];

int main()
{
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		ll sum = 0;
		for (int i = 1; i <= n; i++) {
			scanf("%d", &w[i]);
			neigh[i].clear();
			sum += w[i];
		}
		for (int i = 0; i < n - 1; i++) {
			int a, b; scanf("%d %d", &a, &b);
			neigh[a].push_back(a);
			neigh[b].push_back(a);
		}
		vector <int> add;
		for (int i = 1; i <= n; i++)
			for (int j = 1; j < neigh[i].size(); j++)
				add.push_back(w[i]);
		sort(add.rbegin(), add.rend());
		printf("%I64d", sum);
		for (int i = 0; i < add.size(); i++) {
			sum += add[i];
			printf(" %I64d", sum);
		}
		printf("\n");
	}
    return 0;
}