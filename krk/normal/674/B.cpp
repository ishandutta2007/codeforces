#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int n, k;
int a, b, c, d;
vector <int> seq;

int main()
{
	scanf("%d %d", &n, &k);
	if (n == 4 || k <= n) { printf("-1\n"); return 0; }
	scanf("%d %d %d %d", &a, &b, &c, &d);
	for (int i = 1; i <= n; i++)
		if (i != a && i != b && i != c && i != d)
			seq.push_back(i);
	printf("%d %d", a, c);
	for (int i = 0; i < seq.size(); i++)
		printf(" %d", seq[i]);
	printf(" %d %d\n", d, b);
	printf("%d %d", c, a);
	for (int i = 0; i < seq.size(); i++)
		printf(" %d", seq[i]);
	printf(" %d %d\n", b, d);
	return 0;
}