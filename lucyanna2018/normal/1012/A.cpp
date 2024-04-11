#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<cctype>
#include<iostream>
#include<string>
#include<sstream>
#include<set>
#include<map>
#include<vector>
#include<algorithm>
#include<queue>
#include<utility>
using namespace std;

#define i64 long long int
// #define i128 __int128_t

int n, m, a[222222];
int main() {
	scanf("%d", &n);
	m = 2 * n;
	for (int i = 0; i < m; i++)scanf("%d", &a[i]);
	sort(a, a + m);
	i64 res = 1LL * (a[n - 1] - a[0]) * (a[m - 1] - a[n]);
	i64 w = a[m - 1] - a[0];
	for (int i = 0; i + n <= m; i++) {
		res = min(res, w * (a[i + n - 1] - a[i]));
	}
	cout << res << endl;
	return 0;
}