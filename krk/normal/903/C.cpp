#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <string>
#include <cstring>
#include <sstream>
#include <queue>
#include <iomanip>
#include <algorithm>
using namespace std;

map <int, int> M;

int main()
{
	int n; scanf("%d", &n);
	while (n--) {
		int a; scanf("%d", &a);
		M[a]++;
	}
	int res = 0;
	for (map <int, int>::iterator it = M.begin(); it != M.end(); it++)
		res = max(res, it->second);
	printf("%d\n", res);
	return 0;
}