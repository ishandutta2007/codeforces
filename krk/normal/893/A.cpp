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

int n;
int a = 1, b = 2, c = 3;

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int cur; scanf("%d", &cur);
		if (cur == a) swap(b, c);
		else if (cur == b) swap(a, c);
		else { printf("NO\n"); return 0; }
	}
	printf("YES\n");
	return 0;
}