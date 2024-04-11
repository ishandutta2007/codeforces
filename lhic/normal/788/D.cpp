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
#include <random>
#include <ctime>

#define mp make_pair
#define pb push_back


typedef long long ll;
typedef long double ld;

using namespace std;

#ifndef LOCAL
#define cerr _cer
struct _cert
{
    template <typename T> _cert& operator << (T) { return *this; }
};
_cert _cer;
#endif

template <typename T> void dprint(T begin, T end) {
    for (auto i = begin; i != end; i++) {
		cerr << (*i) << " ";
    }
    cerr << "\n";
}

int cnt = 0;

int ask(int x, int y) {
	++cnt;
	if (cnt > 300000)
		assert(false);
	/*x = abs(x);
	y = abs(y);
	x %= 20000;
	y %= 20000;
	return min({x, y, 20000 - x, 20000 - y});*/
	printf("0 %d %d\n", x, y);
	fflush(stdout);
	int d;
	scanf("%d", &d);
	if (d == -1)
		exit(0);
	return d;
}

const int MX = 1e8;

mt19937 rnd(time(NULL));

int rn(int a, int b) {
	ll x = rnd() % (b - a + 1);
	return x + a; 
}

vector<int> vx;
vector<int> vy;
int bx, by;

void solvex(int l, int r) {
	if (r < l)
		return;
	int mid = (l + r) / 2;
	int d = ask(mid, by);
	if (d == 0) {
		vx.push_back(mid);
		solvex(l, mid - 1);
		solvex(mid + 1, r);
	}
	else if (mid - d >= l && ask(mid - d, by) == 0) {
		vx.push_back(mid - d);
		solvex(l, mid - d - 1);
		solvex(mid + d, r);
	}
	else if (mid + d <= r && ask(mid + d, by) == 0) {
		vx.push_back(mid + d);
		solvex(l, mid - d);
		solvex(mid + d + 1, r);
	}
	else {
		solvex(l, mid - d - 1);
		solvex(mid + d + 1, r);
	}
}

void solvey(int l, int r) {
	if (r < l)
		return;
	int mid = (l + r) / 2;
	int d = ask(bx, mid);
	if (d == 0) {
		vy.push_back(mid);
		solvey(l, mid - 1);
		solvey(mid + 1, r);
	}
	else if (mid - d >= l && ask(bx, mid - d) == 0) {
		vy.push_back(mid - d);
		solvey(l, mid - d - 1);
		solvey(mid + d, r);
	}
	else if (mid + d <= r && ask(bx, mid + d) == 0) {
		vy.push_back(mid + d);
		solvey(l, mid - d);
		solvey(mid + d + 1, r);
	}
	else {
		solvey(l, mid - d - 1);
		solvey(mid + d + 1, r);
	}
}

int main() {
	while (true) {
		bx = rn(-MX, MX);
		by = rn(-MX, MX);
		if (ask(bx, by) >= 8000)
			break;
	}
	solvex(-MX, MX);
	solvey(-MX, MX);
	/*int now = -MX;
	while (now <= MX) {
		int d = ask(now, by);
		//cerr << d << "\n";
		if (d == 0) {
			vx.push_back(now);
			now += 1;
		}
		else {
			now += d;
		}
	}
	cerr << cnt << "\n";
	now = -MX;
	while (now <= MX) {
		int d = ask(bx, now);
		if (d == 0) {
			vy.push_back(now);
			now += 1;
		}
		else {
			now += d;
		}
	}*/
	printf("1 %d %d\n", (int)vx.size(), (int)vy.size());
	for (int i: vx)
		printf("%d ", i);
	printf("\n");
	for (int i: vy)
		printf("%d ", i);
	printf("\n");
	fflush(stdout);
	return 0;
}