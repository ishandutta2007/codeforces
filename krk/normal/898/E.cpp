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

typedef long long ll;

const int Maxn = 200005;

int n;
int a[Maxn], got[Maxn];
int sq;
int tk;
vector <int> V;
ll res;

int Get(int x)
{
	int lef = 0, rig = 1000000;
	while (lef <= rig) {
		int mid = lef + rig >> 1;
		if (ll(mid) * mid <= x) lef = mid + 1;
		else rig = mid - 1;
	}
	return lef - 1;
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		got[i] = Get(a[i]);
		if (got[i] * got[i] == a[i]) sq++;
	}
	if (sq > n / 2) {
		tk = sq - n / 2;
		for (int i = 0; i < n; i++)
			if (got[i] * got[i] == a[i])
				if (a[i] == 0) V.push_back(2);
				else V.push_back(1);
	} else {
		tk = n / 2 - sq;
		for (int i = 0; i < n; i++)
			if (got[i] * got[i] != a[i])
				V.push_back(min(a[i] - got[i] * got[i], (got[i] + 1) * (got[i] + 1) - a[i]));
	}
	sort(V.begin(), V.end());
	for (int i = 0; i < tk; i++)
		res += V[i];
	cout << res << endl;
	return 0;
}