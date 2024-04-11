#include <cstdio>
using namespace std;

const int Maxn = 1005;

int n, m;
bool frows[Maxn], fcols[Maxn];
int res;

int main()
{
	scanf("%d %d", &n, &m);
	while (m--) {
		int x, y; scanf("%d %d", &x, &y);
		frows[x] = true; fcols[y] = true;
	}
	int l = 2, r = n - 1;
	while (l < r) { 
		res += !frows[l] + !frows[r] + !fcols[l] + !fcols[r];
		l++; r--;
	}
	if (l == r) res += !frows[l] || !fcols[l];
	printf("%d\n", res);
	return 0;
}