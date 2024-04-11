#include <bits/stdc++.h>
using namespace std;

int T;
int n;

int main()
{
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		int md[3] = {};
		for (int i = 0; i < n; i++) {
			int a; scanf("%d", &a);
			md[a % 3]++;
		}
		int res = 0;
		while (true)
			if (md[0] > n / 3) {
				int tk = md[0] - n / 3;
				md[0] -= tk; md[1] += tk;
				res += tk;
			} else if (md[1] > n / 3) {
				int tk = md[1] - n / 3;
				md[1] -= tk; md[2] += tk;
				res += tk;
			} else if (md[2] > n / 3) {
				int tk = md[2] - n / 3;
				md[2] -= tk; md[0] += tk;
				res += tk;
			} else break;
		printf("%d\n", res);
	}
    return 0;
}