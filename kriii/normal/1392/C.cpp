#include <stdio.h>
#include <algorithm>
using namespace std;

int n, a[200200], g[200200];

int main()
{
	int t; scanf ("%d", &t); while (t--){
		scanf ("%d", &n);
		for (int i = 0; i < n; i++) scanf ("%d", &a[i]);
		g[0] = a[0];
		long long r = 0;
		for (int i = 1; i < n; i++){
			if (g[i - 1] <= a[i]) g[i] = a[i];
			else{
				if (a[i - 1] >= a[i]) r += a[i - 1] - a[i];
				g[i] = g[i - 1];
			}
		}
		printf ("%lld\n", r);
	}

	return 0;
}