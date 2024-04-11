#include <cstdio>
#include <algorithm>
using namespace std;

const int Maxn = 200005;
const int Inf = 2000000000;

int n, w;
int a[Maxn];
bool tk[Maxn];
int res;
bool half;

int Mult(int a, int b) { return a <= Inf / b? a * b: Inf; }

int main()
{
	scanf("%d %d", &n, &w);
	for (int i = 0; i < 2 * n; i++)
		scanf("%d", &a[i]);
	sort(a, a + 2 * n);
	if (a[0] * 2 <= a[n]) printf("%d\n", min(w, Mult(3 * n, a[0])));
	else if (2 * w <= Mult(3 * n, a[n])) printf("%d\n", w);
		 else {
		 	int had = Mult(3 * n, a[n]);
		 	printf("%d", had / 2);
		 	if (had % 2) printf(".5");
		 	printf("\n");
		 }
	return 0;
}