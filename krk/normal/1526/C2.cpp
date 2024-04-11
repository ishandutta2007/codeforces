#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005;

int n;
int a[Maxn];
multiset <int> S;
int res;

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	for (int i = n - 1; i >= 0; i--)
		if (a[i] < 0) S.insert(-a[i]);
		else {
			res++;
			while (!S.empty() && *S.begin() <= a[i]) {
				a[i] -= *S.begin();
				res++;
				S.erase(S.begin());
			}
			if (!S.empty()) {
				int lft = *S.begin() - a[i];
				S.erase(S.begin());
				S.insert(lft);
			}
		}
	printf("%d\n", res);
    return 0;
}