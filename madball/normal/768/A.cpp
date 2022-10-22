#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <cmath>
#include <random>
#include <stack>
#include <queue>
#include <deque>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll inf = 1e+9 + 7;
const ld eps = 1e-7;

#ifdef LOCAL
//#define STRESS
#endif

vector<int> ar;

void solve()
{
	int n;
	scanf("%d", &n);
	if (n <= 2)
	{
		printf("0");
		return;
	}
	ar.resize(n);
	for (int i = 0; i < n; ++i)
		scanf("%d", &ar[i]);
	sort(ar.begin(), ar.end());
	int low = ar[0];
	int hi = ar[ar.size() - 1];
	int cnt = 0;
	for (int i = 0; i < ar.size(); ++i)
		if (ar[i] != low && ar[i] != hi)
			++cnt;
	printf("%d", cnt);
}

int main()
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	solve();
	return 0;
}