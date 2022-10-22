#include <bits/stdc++.h>
using namespace std;

const int Maxn = 105;
const int Inf = 1000000007;

int T;
int n;
int a[Maxn];
int b[Maxn];

int main()
{
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		int mna = Inf, mnb = Inf;
		for (int i = 0; i < n; i++) {
			scanf("%d", &a[i]);
			mna = min(mna, a[i]);
		}
		for (int i = 0; i < n; i++) {
			scanf("%d", &b[i]);
			mnb = min(mnb, b[i]);
		}
		long long res = 0;
		for (int i = 0; i < n; i++)
			res += max(a[i] - mna, b[i] - mnb);
		printf("%I64d\n", res);
	}
    return 0;
}