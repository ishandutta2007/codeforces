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

const int Maxn = 200005;

int n;
bool used[Maxn];
int res = 1;

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		int a; scanf("%d", &a);
		if (!used[a]) used[a]++;
		else res++;
	}
	printf("%d\n", res);
	return 0;
}