#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

const int Maxn = 20;

int n;
int a[1 << Maxn];
vector <int> V;
ll I1[Maxn + 1], I2[Maxn + 1];
int m;
ll res;

void Traverse(int lvl, int l, int r, vector <int> &tofill)
{
	if (lvl == 0) tofill.push_back(a[l]);
	else {
		vector <int> A, B;
		int m = l + r >> 1;
		Traverse(lvl - 1, l, m, A); Traverse(lvl - 1, m + 1, r, B);
		int i = 0, j = 0;
		while (i < A.size() || j < B.size()) {
			int mx = i < A.size() && (j == B.size() || A[i] >= B[j])? A[i]: B[j];
			int i2 = i, j2 = j;
			while (i2 < A.size() && A[i2] == mx) { tofill.push_back(mx); i2++; }
			while (j2 < B.size() && B[j2] == mx) { tofill.push_back(mx); j2++; }
			I1[lvl] += ll(i2 - i) * (B.size() - j2); I2[lvl] += ll(j2 - j) * (A.size() - i2);
			i = i2; j = j2;
		}
	}
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < 1 << n; i++)
		scanf("%d", &a[i]);
	Traverse(n, 0, (1 << n) - 1, V);
	scanf("%d", &m);
	while (m--) {
		int b; scanf("%d", &b);
		res = 0ll;
		for (int i = 0; i <= n; i++) {
			if (i <= b) swap(I1[i], I2[i]);
			res += I1[i];
		}
		printf("%I64d\n", res);
	}
	return 0;
}