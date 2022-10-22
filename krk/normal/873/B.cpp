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

const int Maxn = 200015;
const int nil = 100005;

int lst[Maxn];
int n;
int res;

int main()
{
	fill(lst, lst + Maxn, -1);
	int cur = nil;
	lst[cur] = 0;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		char ch; scanf(" %c", &ch);
		if (ch == '1') cur++;
		else cur--;
		if (lst[cur] == -1) lst[cur] = i;
		else res = max(res, i - lst[cur]);
	}
	printf("%d\n", res);
	return 0;
}