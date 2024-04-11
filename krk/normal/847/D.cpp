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

int n, T;
int a[Maxn];
vector <int> un;
int BIT[Maxn];
int res;

void Update(int x)
{
	x++;
	for (int i = x; i <= un.size(); i += i & -i)
		BIT[i]++;
}

int Get(int x)
{
	x++;
	int res = 0;
	for (int i = x; i > 0; i -= i & -i)
		res += BIT[i];
	return res;
}

int main()
{
	scanf("%d %d", &n, &T);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]); a[i] = max(a[i], i);
		un.push_back(a[i] - i);
	}
	sort(un.begin(), un.end()); un.erase(unique(un.begin(), un.end()), un.end());
	for (int i = 1; i <= n; i++) if (i < T) {
		int ind = lower_bound(un.begin(), un.end(), a[i] - i) - un.begin();
		Update(ind);
		int lft = T - 1 - i;
		ind = upper_bound(un.begin(), un.end(), lft) - un.begin() - 1;
		res = max(res, Get(ind));
	}
	printf("%d\n", res);
	return 0;
}