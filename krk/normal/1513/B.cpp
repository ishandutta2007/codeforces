#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 200005;
const int mod = 1000000007;
const int Maxb = 30;

int T;
int n;
int cnt[Maxb];
int a[Maxn];

int main()
{
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		fill(cnt, cnt + Maxb, 0);
		for (int i = 0; i < n; i++) {
			scanf("%d", &a[i]);
			for (int j = 0; j < Maxb; j++)
				if (a[i] & 1 << j)
					cnt[j]++;
		}
		int spec = 0;
		for (int i = 0; i < n; i++) {
			bool mespec = true;
			for (int j = 0; j < Maxb; j++)
				if (cnt[j] < n && bool(a[i] & 1 << j))
					mespec = false;
			spec += mespec;
		}
		if (spec < 2) printf("0\n");
		else {
			int res = ll(spec) * (spec - 1) % mod;
			for (int i = 1; i <= n - 2; i++)
				res = ll(res) * i % mod;
			printf("%d\n", res);
		}
	}
    return 0;
}