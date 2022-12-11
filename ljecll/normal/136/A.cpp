#include <iostream>
#include <cstdio>
#include <fstream>
#include <algorithm>
#include <cstring>
#include <string>
#include <cctype>
#include <stack>
#include <queue>
#include <deque>
#include <list>
#include <vector>
#include <map>
#include <sstream>
#include <cmath>
#include <bitset>
#include <utility>
#include <set>
#include <numeric>
#include <functional>
#include <ctime>
#include <climits>
#include <cstdlib>
#include <cassert>
#include <complex>
#define MAXN 105

using namespace std;

int N;
int ans[MAXN];

int main()
{
//	freopen ("cf136a.in", "r", stdin);
//	freopen ("cf136a.out", "w", stdout);
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
	{
		int x;
		cin >> x;
		ans[x] = i;
	}
	printf("%d", ans[1]);
	for (int i = 2; i <= N; i++)
	{
		printf(" %d", ans[i]);
	}
	printf("\n");
	return 0;
}