#include <cstdio>
#include <algorithm>
using namespace std;

int n, m, a[100100];

int main()
{
	int t; scanf ("%d", &t); while (t--){
		scanf ("%d %d", &n, &m);
		for (int i = 1; i <= n; i++) scanf ("%d", &a[i]);

		int l = n;
		while (l > 0 && a[l] == l) l--;

		double fail = 1;
		for (int i = 0; i < m; i++){
			int x; double p;
			scanf ("%d %lf", &x, &p);
			if (l <= x) fail *= 1 - p;
		}
		if (l == 0) fail = 0;
		printf ("%lf\n", 1 - fail);
	}
	return 0;
}