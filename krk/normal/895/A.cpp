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

const int Maxn = 365;

int n;
int a[Maxn];
int res = 360;

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	for (int i = 0; i < n; i++) {
		int cand = 0;
		for (int j = 0; j < n; j++) {
			cand += a[(i + j) % n];
			res = min(res, abs(cand - (360 - cand)));
		}
	}
	printf("%d\n", res);
	return 0;
}