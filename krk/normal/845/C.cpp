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

int n;
map <int, int> M;

int main()
{
	scanf("%d", &n);
	while (n--) {
		int l, r; scanf("%d %d", &l, &r);
		M[l]++; M[r + 1]--;
	}
	int cur = 0;
	for (map <int, int>::iterator it = M.begin(); it != M.end(); it++) {
		cur += it->second;
		if (cur > 2) { printf("NO\n"); return 0; }
	}
	printf("YES\n");
	return 0;
}