#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005;

int T;
int n;
vector <int> inds[Maxn];

int main()
{
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		for (int i = 0; i <= n; i++)
			inds[i].clear();
		for (int i = 1; i <= n; i++) {
			int a; scanf("%d", &a);
			inds[a].push_back(i);
		}
		int res = -1;
		for (int i = 0; i <= n; i++)
			if (inds[i].size() == 1) { res = inds[i][0]; break; }
		printf("%d\n", res);
	}
    return 0;
}