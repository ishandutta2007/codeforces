#include <stdio.h>
#include <algorithm>
using namespace std;

int n; long long p[33][33], a[33][33];
pair<long long, long long> v[33][33];

int main()
{
	scanf ("%d", &n);
	for (int i = n; i >= 1; i--){
		for (int j = n; j >= 1; j--){
			if (i == n && j == n) p[i][j] = 1;
			else p[i][j] = p[i + 1][j] + p[i][j + 1];
			v[i][j].first = v[i + 1][j - 1].second;
			v[i][j].second = v[i][j].first + p[i][j];

			if (i == n && j == n);
			else if (i < n) a[i][j] = v[i][j].first - v[i + 1][j].first;
			else if (j < n) a[i][j] = v[i][j].first - v[i][j + 1].first;
		}
	}

	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= n; j++){
			printf ("%lld ", a[i][j]);
		}
		puts("");
	}
	fflush(stdout);

	int q; scanf ("%d", &q); while (q--){
		long long k; scanf ("%lld", &k);
		int i = 1, j = 1;
		printf ("1 1\n");
		while (i < n || j < n){
			if (p[i + 1][j] > k - v[i][j].first) k -= a[i++][j];
			else k -= a[i][j++];
			printf ("%d %d\n", i, j);
		}
		fflush(stdout);
	}

	return 0;
}