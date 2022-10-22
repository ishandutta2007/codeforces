#include <bits/stdc++.h>
using namespace std;

const int Maxn = 300005;

int T;
int n;
int a[Maxn];

int Get(int ind)
{
	if (ind <= 0 || ind >= n - 1) return 0;
	return a[ind] < a[ind - 1] && a[ind] < a[ind + 1] ||
		   a[ind] > a[ind - 1] && a[ind] > a[ind + 1];
}

int main()
{
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
			scanf("%d", &a[i]);
		int cur = 0;
		for (int i = 1; i + 1 < n; i++)
			cur += Get(i);
		int res = cur;
		for (int i = 0; i < n; i++) {
			int old = a[i];
			if (i > 0) {
				cur -= (Get(i - 1) + Get(i) + Get(i + 1));
				a[i] = a[i - 1];
				cur += (Get(i - 1) + Get(i) + Get(i + 1));
				res = min(res, cur);
				cur -= (Get(i - 1) + Get(i) + Get(i + 1));
				a[i] = old;
				cur += (Get(i - 1) + Get(i) + Get(i + 1));
			}
			if (i + 1 < n) {
				cur -= (Get(i - 1) + Get(i) + Get(i + 1));
				a[i] = a[i + 1];
				cur += (Get(i - 1) + Get(i) + Get(i + 1));
				res = min(res, cur);
				cur -= (Get(i - 1) + Get(i) + Get(i + 1));
				a[i] = old;
				cur += (Get(i - 1) + Get(i) + Get(i + 1));
			}
		}
		printf("%d\n", res);
	}
    return 0;
}