#include <cstdio>
#include <algorithm>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 105;

int n;
ii A[Maxn], B[Maxn];
int alen, blen;
int res;

int main()
{
	scanf("%d", &n);
	while (n--) {
		int x, a; scanf("%d %d", &x, &a);
		if (x < 0) A[alen++] = ii(-x, a);
		else B[blen++] = ii(x, a);
	}
	sort(A, A + alen); sort(B, B + blen);
	int mn = min(alen, blen);
	for (int i = 0; i < mn; i++)
		res += A[i].second + B[i].second;
	if (mn < alen) res += A[mn].second;
	else if (mn < blen) res += B[mn].second;
	printf("%d\n", res);
	return 0;
}