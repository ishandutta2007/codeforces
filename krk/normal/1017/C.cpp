#include <bits/stdc++.h>
using namespace std;

int n;
int best = 200000005, bi;
vector <int> res;

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		int b = (n - 1) / i + 1;
		if (i + b < best) { best = i + b; bi = i; }
	}
	int bj = (n - 1) / bi + 1;
	for (int i = 1; i <= n; i += bj) {
		int to = min(n, i + bj - 1);
		for (int j = to; j >= i; j--)
			res.push_back(j);
	}
	for (int i = 0; i < res.size(); i++)
		printf("%d%c", res[i], i + 1 < res.size()? ' ': '\n');
	return 0;
}