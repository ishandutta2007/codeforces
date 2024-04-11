#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

const int Maxn = 100005;

int n, k;
char str[Maxn];

int Solve(char a, char b)
{
	int r = 0, lft = k;
	int res = 0;
	for (int l = 0; l < n; l++) {
		if (r < l) { r = l; lft = k; }
		while (r < n && (str[r] == a || lft > 0 && str[r] == b)) {
			lft -= str[r] == b;
			r++;
		}
		res = max(res, r - l);
		lft += str[l] == b;
	}
	return res;
}

int main()
{
	scanf("%d %d", &n, &k);
	scanf("%s", str);
	printf("%d\n", max(Solve('a', 'b'), Solve('b', 'a')));
	return 0;
}