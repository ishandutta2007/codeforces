#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 1000005;

int mx[Maxn];
int T;
int n;
int a[Maxn];

int main()
{
	for (int i = 2; i < Maxn; i++) if (mx[i] == 0)
		for (int j = i; j < Maxn; j += i)
			mx[j] = i;
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		map <int, int> M;
		for (int i = 0; i < n; i++) {
			int a; scanf("%d", &a);
			int got = 1;
			while (a > 1) {
				int cur = mx[a], cnt = 0;
				while (a % cur == 0) {
					a /= cur; cnt++;
				}
				if (cnt % 2) got *= cur;
			}
			M[got]++;
		}
		int mx1 = 0, mx2 = 0;
		for (auto it: M) {
			mx1 = max(mx1, it.second);
			if (it.first == 1 || it.second % 2 == 0)
				mx2 += it.second;
		}
		mx2 = max(mx2, mx1);
		int q; scanf("%d", &q);
		while (q--) {
			ll t; scanf("%I64d", &t);
			printf("%d\n", t > 0? mx2: mx1);
		}
	}
    return 0;
}