#include <iostream>
#include <fstream>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <bitset>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cassert>
#include <queue>


typedef long long ll;
typedef long double ld;

using namespace std;

const int MAXN = 500000;

int n;

int a[MAXN];
int dd[MAXN];

int l[MAXN];
int r[MAXN];

int gcd(int a, int b)
{
	while (b)
	{
		int q = a % b;
		a = b;
		b = q;
	}
	return a;
}



int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%d", &a[i]);

	int mx = -1;
	for (int i = 0; i < n; ++i)
	{
		if (mx >= i)
		{
			dd[i] = 1;
			r[i] = l[i] = 1;
			continue;
		}
		int now = a[i];
		r[i] = 1;
		while (i + r[i] < n && gcd(now, a[i + r[i]]) == a[i])
			++r[i];
		mx = i + r[i] - 1;
	}

	mx = n;
	for (int i = n - 1; i >= 0; --i)
	{
		if (mx <= i || dd[i])
		{
			dd[i] = 1;
			r[i] = l[i] = 1;
			continue;
		}
		l[i] = 1;
		while (i - l[i] >= 0 && gcd(a[i], a[i - l[i]]) == a[i])
			++l[i];
		mx = i - l[i] + 1;
	}

	int ans = 0;
	for (int i = 0; i < n; ++i)
		if (!dd[i])
			ans = max(ans, l[i] + r[i] - 1);

	vector<int> v;

	for (int i = 0; i < n; ++i)
		if (!dd[i] && l[i] + r[i] - 1 == ans)
			v.push_back(i - l[i] + 1);

	//sort(v.begin(), v.end());

	//v.resize(unique(v.begin(), v.end()) - v.begin());


	printf("%d %d\n", (int)v.size(), ans - 1);

	for (int i = 0; i < (int)v.size(); ++i)
		printf("%d ", v[i] + 1);





	return 0;
}