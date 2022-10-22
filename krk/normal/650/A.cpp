#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef pair <int, int> ii;

map <int, int> X, Y;
map <ii, int> T;
int n;
ll res;

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int x, y; scanf("%d %d", &x, &y);
		X[x]++; Y[y]++;
		T[ii(x, y)]++;
	}
	for (map <int, int>::iterator it = X.begin(); it != X.end(); it++)
		res += ll(it->second) * (it->second - 1) / 2;
	for (map <int, int>::iterator it = Y.begin(); it != Y.end(); it++)
		res += ll(it->second) * (it->second - 1) / 2;
	for (map <ii, int>::iterator it = T.begin(); it != T.end(); it++)
		res -= ll(it->second) * (it->second - 1) / 2;
	printf("%I64d\n", res);
	return 0;
}