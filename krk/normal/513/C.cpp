#include <cstdio>
#include <iostream>
#include <iomanip>
using namespace std;

typedef long double ld;

const int Maxn = 5;
const int lim = 10000;

int n;
int L[Maxn], R[Maxn];
ld res;

ld isIn(int L, int R, int l, int r)
{
	l = max(l, L); r = min(r, R);
	if (l > r) return 0.0l;
	return ld(r - l + 1) / ld(R - L + 1);
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d %d", &L[i], &R[i]);
	for (int i = 1; i <= lim; i++)
		for (int j = 0; j < n; j++) if (L[j] <= i && i <= R[j]) {
			ld prob = i / ld(R[j] - L[j] + 1);
			for (int l = j + 1; l < n; l++) {
				ld cprob = prob * isIn(L[l], R[l], i, i);
				for (int k = 0; k < n; k++) if (k != j && k != l)
					cprob *= isIn(L[k], R[k], L[k], (l < k? i: i - 1));
				res += cprob;
			}
			for (int l = 0; l < n; l++) if (l != j) {
				ld cprob = prob * isIn(L[l], R[l], i + 1, R[l]);
				for (int k = 0; k < n; k++) if (k != j && k != l)
					cprob *= isIn(L[k], R[k], L[k], (j < k? i: i - 1));
				res += cprob;
			}
		}
	cout << fixed << setprecision(10) << res << endl;
	return 0;
}