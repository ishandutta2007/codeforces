#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> hi[200200];
int n, f[200200]; bool p[200200];

int main()
{
	for (int i = 2; i < 200200; i++) if (!p[i]){
		for (int j = i; j < 200200; j += i) p[j] = 1, f[j] = i;
	}

	scanf ("%d", &n);
	for (int i = 0; i < n; i++){
		int x; scanf ("%d", &x);
		while (x > 1){
			int v = f[x], c = 0;
			while (x % v == 0){
				x /= v;
				c++;
			}
			hi[v].push_back(c);
		}
	}

	long long r = 1;
	for (int i = 2; i < 200200; i++) if (!hi[i].empty()){
		sort(hi[i].begin(), hi[i].end());
		int c = 0;
		if (hi[i].size() == n) c = hi[i][1];
		else if (hi[i].size() == n - 1) c = hi[i][0];
		while (c--) r *= i;
	}

	printf ("%lld\n", r);
	return 0;
}