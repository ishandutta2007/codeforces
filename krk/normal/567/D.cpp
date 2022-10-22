#include <cstdio>
#include <set>
using namespace std;

int n, k, a;
int m;
set <int> S;
int l;

void Shoot(int x)
{
	set <int>::iterator it1, it2;
	it1 = S.lower_bound(x);
	if (*it1 == x) return;
	it2 = it1; it1--;
	int w = *it2 - *it1 - 1;
	l -= (w + 1) / (a + 1);
	l += (x - *it1) / (a + 1);
	l += (*it2 - x) / (a + 1);
	S.insert(x);
}

int main()
{
	scanf("%d %d %d", &n, &k, &a);
	S.insert(0); S.insert(n + 1);
	l = (n + 1) / (a + 1);
	scanf("%d", &m);
	for (int i = 1; i <= m; i++) {
		int x; scanf("%d", &x);
		Shoot(x);
		if (l < k) { printf("%d\n", i); return 0; }
	}
	printf("-1\n");
	return 0;
}