#include <bits/stdc++.h>
using namespace std;

const int Maxn = 105;

int T;
int n;
int a[Maxn];

int main()
{
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		int lef, rig;
		for (int i = 0; i < n; i++) {
			scanf("%d", &a[i]);
			if (a[i] == 1) lef = i;
			else if (a[i] == n) rig = i;
		}
		if (lef > rig) swap(lef, rig);
		printf("%d\n", min(min(n - lef, rig + 1), lef + 1 + n - rig));
	}
    return 0;
}