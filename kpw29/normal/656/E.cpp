#include <bits/stdc++.h>
using namespace std;
int a, b, maks = 0, n;
int path[25][25], odl[25][25];

int loop2(int x, int y) {
	scanf("%d", &odl[x][y]);
	return (y == n)?0:loop2(x, y + 1);
}
int loop(int x) {
	loop2(x, 1);
	return (x == n)?0:loop(x + 1);
}
int WYN = 0;
int L2(int x, int y) {
	int TMP = (x == y)?0:odl[x][y];
	return (y == n)?TMP:max(TMP, L2(x, y + 1));
}

int L(int x) {
	int W = L2(x, 1);
	WYN = max(WYN, W);
	return (x == n)?0:L(x + 1);
}

int F3(int x, int y, int z) {
	odl[y][z] = min(odl[y][x] + odl[x][z], odl[y][z]);
	return (z == n)?0:F3(x, y, z + 1);
}
int F2(int x, int y) {
	int pos = F3(x, y, 1);
	return (y == n)?0:F2(x, y + 1);
}

int F1(int x) {
	int pos = F2(x, 1);
	return (x == n)?0:F1(x + 1);
}

int main()
{
	scanf("%d", &n);
	loop(1);
	F1(1);
	L(1);
	cout << WYN;
}