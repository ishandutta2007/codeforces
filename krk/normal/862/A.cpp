#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <string>
#include <cstring>
#include <sstream>
#include <algorithm>
using namespace std;

int n, x;
set <int> S;
int res;

int main()
{
	scanf("%d %d", &n, &x);
	for (int i = 0; i < n; i++) {
		int a; scanf("%d", &a);
		S.insert(a);
	}
	for (int i = 0; i < x; i++)
		res += S.find(i) == S.end();
	res += S.find(x) != S.end();
	printf("%d\n", res);
	return 0;
}