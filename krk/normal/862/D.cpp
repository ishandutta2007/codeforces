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

int n;
char a, b;
int tot;

int Ask(const string &s)
{
	cout << "? " << s << endl; fflush(stdout);
	int res; scanf("%d", &res);
	return res;
}

int Solve()
{
	int lef = 1, rig = n;
	int res = -1;
	while (lef <= rig) {
		int mid = lef + rig >> 1;
		int g = Ask(string(mid, a) + string(n - mid, b));
		if (g == mid + n - tot) lef = mid + 1;
		else { res = mid - 1; rig = mid - 1; }
	}
	return res;
}

void Print(int a, int b)
{
	cout << "! " << a + 1 << " " << b + 1 << endl; fflush(stdout);
}

int main()
{
	scanf("%d", &n);
	int g = Ask(string(n, '0'));
	int wh = Ask(string(1, '0') + string(n - 1, '1'));
	if (wh == 1 + n - g) {
		a = '0'; b = '1'; tot = g;
		Print(Solve(), 0);
	} else {
		a = '1'; b = '0'; tot = n - g;
		Print(0, Solve());
	}
	return 0;
}