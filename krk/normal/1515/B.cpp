#include <bits/stdc++.h>
using namespace std;

const int Inf = 1000000000;

set <int> S;
int T;
int n;

int main()
{
	for (int i = 1; i * i <= Inf; i++)
		S.insert(i * i);
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		if (n % 2 == 0 && S.count(n / 2) || n % 4 == 0 && S.count(n / 4))
			printf("YES\n");
		else printf("NO\n");
	}
    return 0;
}