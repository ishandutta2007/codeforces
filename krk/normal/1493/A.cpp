#include <bits/stdc++.h>
using namespace std;

int T;
int n, k;

int main()
{
	scanf("%d", &T);
	while (T--) {
		scanf("%d %d", &n, &k);
		vector <int> res;
		for (int i = 1; i <= n; i++) if (2 * i >= k && i != k)
			res.push_back(i);
		printf("%d\n", int(res.size()));
		if (res.empty()) printf("\n");
		else for (int i = 0; i < res.size(); i++)
				printf("%d%c", res[i], i + 1 < res.size()? ' ': '\n');
	}
    return 0;
}