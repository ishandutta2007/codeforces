#include <bits/stdc++.h>
using namespace std;

const int Maxn = 105;

int T;
int n;
int A[Maxn];

int main()
{
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
			scanf("%d", &A[i]);
		for (int i = 0; i < n; i++) {
			int a = 0;
			while (a == i) a++;
			int b = 0;
			while (b == a || b == i) b++;
			if (A[i] != A[a] && A[i] != A[b])
				printf("%d\n", i + 1);
		}
	}
    return 0;
}