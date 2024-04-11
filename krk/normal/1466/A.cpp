#include <bits/stdc++.h>
using namespace std;

const int Maxn = 105;

int T;
int n;
int x[Maxn];

int main()
{
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
			scanf("%d", &x[i]);
		set <int> S;
		for (int i = 0; i < n; i++)
			for (int j = i + 1; j < n; j++)
				S.insert(x[j] - x[i]);
		printf("%d\n", int(S.size()));
	}
    return 0;
}