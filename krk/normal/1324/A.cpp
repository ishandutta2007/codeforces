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
		bool fall = false;
		for (int i = 0; i < n; i++) {
			scanf("%d", &a[i]);
			if (a[i] % 2 != a[0] % 2)
				fall = true;
		}
		printf("%s\n", fall? "NO": "YES");
	}
    return 0;
}