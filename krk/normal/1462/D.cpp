#include <bits/stdc++.h>
using namespace std;

const int Maxn = 3005;

int T;
int n;
int a[Maxn];

bool Check(int sum)
{
	int cur = 0;
	for (int i = 0; i < n; i++) {
		cur += a[i];
		if (cur == sum) cur = 0;
		else if (cur > sum) return false;
	}
	return true;
}

int main()
{
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		int sum = 0;
		for (int i = 0; i < n; i++) {
			scanf("%d", &a[i]);
			sum += a[i];
		}
		int best = 1;
		for (int i = 2; i <= n; i++) if (sum % i == 0)
			if (Check(sum / i)) best = i;
		printf("%d\n", n - best);
	}
    return 0;
}