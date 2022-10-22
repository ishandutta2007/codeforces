#include <iostream>
#include <cstdio>
#include <string>
#include <set>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef pair <int, int> ii;

const int lim = 1000000;

int n, m;
int x, y;
string dr;
int dx, dy;
set <ii> was;
ll res;

void Calc(int &t1, int &t2)
{
	if (dx == 1) t1 = n - x;
	if (dx == -1) t1 = x - 1;
	if (dy == 1) t2 = m - y;
	if (dy == -1) t2 = y - 1;
}

int main()
{
	cin >> n >> m;
	cin >> x >> y >> dr;
	if (dr == "DR") { dx = 1; dy = 1; }
	else if (dr == "UL") { dx = -1; dy = -1; }
	else if (dr == "UR") { dx = -1; dy = 1; }
	else { dx = 1; dy = -1; }
	int cnt = lim;
	res++;
	while (cnt--) {
		was.insert(ii(x, y));
		if (was.size() == n + m - 2) { printf("%I64d\n", res); return 0; }
		int t1, t2;
		do {
			Calc(t1, t2);
			if (t1 == 0) dx = -dx;
			if (t2 == 0) dy = -dy;
			if (t1 && t2) break;
		} while (true);
		if (t1 <= t2) { res += t1; x += t1 * dx; y += t1 * dy; dx = -dx; }
		else { res += t2; x += t2 * dx; y += t2 * dy; dy = -dy; }
		if (t1 == t2) dy = -dy;
	}
	printf("-1\n");
	return 0;
}