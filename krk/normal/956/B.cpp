#include <bits/stdc++.h>
using namespace std;

typedef long double ld;

const int Maxn = 100005;

int n, U;
int A[Maxn];
ld res = -1.0;

int main()
{
	scanf("%d %d", &n, &U);
	for (int i = 0; i < n; i++)
		scanf("%d", &A[i]);
	for (int i = 0; i < n; i++) {
		int ind = upper_bound(A, A + n, A[i] + U) - A - 1;
		if (ind - i + 1 >= 3)
			res = max(res, ld(A[ind] - A[i + 1]) / ld(A[ind] - A[i]));
	}
	if (res < -0.5) cout << "-1\n";
	else cout << fixed << setprecision(13) << res << endl;
	return 0;
}