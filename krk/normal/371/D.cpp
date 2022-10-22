#include <cstdio>
#include <set>
using namespace std;

const int Maxn = 200005;

int n;
int a[Maxn];
int has[Maxn];
int m;
int q1, q2, q3;
set <int> S;

void Fill(int k, int x)
{
	set <int>::iterator it = S.lower_bound(k);
	while (it != S.end() && x) {
		int spil = min(x, a[*it] - has[*it]); x -= spil; has[*it] += spil;
		if (a[*it] == has[*it]) S.erase(it++);
	}
}

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]); S.insert(i);
	}
	scanf("%d", &m);
	while (m--) {
		scanf("%d %d", &q1, &q2);
		if (q1 == 1) { scanf("%d", &q3); Fill(q2, q3); }
		else printf("%d\n", has[q2]);
	}
	return 0;
}