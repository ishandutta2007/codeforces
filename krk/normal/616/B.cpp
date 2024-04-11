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

const int Inf = 1000000007;
const int Maxn = 105;

int n, m;
int mx;
int R[Maxn];

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		R[i] = Inf;
		for (int j = 0; j < m; j++) {
			int a; scanf("%d", &a);
			R[i] = min(R[i], a);
		}
		mx = max(mx, R[i]);
	}
	printf("%d\n", mx);
	return 0;
}