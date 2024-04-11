#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <iomanip>
#include <cmath>
#include <string>
#include <cstring>
#include <sstream>
#include <algorithm>
using namespace std;

typedef long double ld;

const int Maxn = 100005;
const ld Inf = 1e13l;

int n, p;
int a[Maxn], b[Maxn];

bool Ok(ld t)
{
	ld sum = 0;
	for (int i = 0; i < n && sum <= t; i++)
		if (t * ld(a[i]) >= ld(b[i]))
			sum += ld(t * ld(a[i]) - ld(b[i])) / p;
	return sum <= t;
}

int main()
{
	scanf("%d %d", &n, &p);
	for (int i = 0; i < n; i++)
		scanf("%d %d", &a[i], &b[i]);
	ld lef = 0, rig = Inf;
	for (int i = 0; i < 100; i++) {
		ld mid = (lef + rig) / 2.0l;
		if (Ok(mid)) lef = mid;
		else rig = mid;
	}
	if (lef >= Inf / 2) cout << "-1\n";
	else cout << fixed << setprecision(15) << lef << endl;
	return 0;
}