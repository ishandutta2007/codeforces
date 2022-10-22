#include <bits/stdc++.h>
using namespace std;

const int Maxn = 100005;

int T;
int n;
int P[Maxn];
bool tk[Maxn];

int main()
{
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		fill(tk + 1, tk + n + 1, false);
		for (int i = 0; i < n; i++)
			scanf("%d", &P[i]);
		bool was = false;
		int val = n, pnt = n;
		while (val > 0)
			if (tk[val]) val--;
			else {
				int mem = pnt--;
				while (P[pnt] != val) pnt--;
				for (int i = pnt; i < mem; i++) {
					if (was) printf(" ");
					else was = true;
					printf("%d", P[i]);
					tk[P[i]] = true;
				}
			}
		printf("\n");
	}
    return 0;
}