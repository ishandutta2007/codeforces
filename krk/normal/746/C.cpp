#include <cstdio>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

typedef long long ll;

int s, x1, x2;
int t1, t2;
int p, d;
ll res;

int main()
{
	scanf("%d %d %d", &s, &x1, &x2);
	scanf("%d %d", &t1, &t2);
	res = ll(t2) * abs(x1 - x2);
	scanf("%d %d", &p, &d);
	int ndir = x1 < x2? 1: -1;
	ll tim = 0;
	while (p != x1 || d != ndir)
		if (p == s && d == 1) d = -1;
		else if (p == 0 && d == -1) d = 1;
		else { p += d; tim += t1; }
	res = min(res, tim + ll(t1) * abs(x1 - x2));
	cout << res << endl;
	return 0;
}