#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005;

int T;
int n;
int a[Maxn];
bool Lok[Maxn], Rok[Maxn];
int Llft[Maxn], Rlft[Maxn];

int main()
{
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
			scanf("%d", &a[i]);
		Lok[0] = true; Llft[0] = 0;
		for (int i = 1; i <= n; i++) {
			Lok[i] = Lok[i - 1] && Llft[i - 1] <= a[i];
			if (Lok[i]) Llft[i] = a[i] - Llft[i - 1];
		}
		if (Lok[n] && Llft[n] == 0) { printf("YES\n"); continue; }
		Rok[n + 1] = true; Rlft[n + 1] = 0;
		for (int i = n; i > 0; i--) {
			Rok[i] = Rok[i + 1] && Rlft[i + 1] <= a[i];
			if (Rok[i]) Rlft[i] = a[i] - Rlft[i + 1];
		}
		bool found = false;
		for (int i = 1; i + 1 <= n && !found; i++)
			if (Lok[i - 1] && Rok[i + 2] && Llft[i - 1] <= a[i + 1] && Rlft[i + 2] <= a[i]) {
				int A = a[i + 1] - Llft[i - 1];
				int B = a[i] - Rlft[i + 2];
				found = A == B;
			}
		printf("%s\n", found? "YES": "NO");
	}
    return 0;
}