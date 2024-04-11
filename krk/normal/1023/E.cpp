#include <bits/stdc++.h>
using namespace std;

const int Maxn = 505;

int n;
bool ok[Maxn][Maxn];

bool Inside(int r, int c) { return 1 <= r && r <= n && 1 <= c && c <= n; }

bool Ask(int r1, int c1, int r2, int c2)
{
	if (!Inside(r1, c1) || !Inside(r2, c2)) return false;
	printf("? %d %d %d %d\n", r1, c1, r2, c2); fflush(stdout);
	string s; cin >> s;
	return s == "YES";
}

int main()
{
	scanf("%d", &n);
	int r = 1, c = 1;
	ok[r][c] = true;
	while (abs(r - 1) + abs(c - 1) < n - 1)
		if (Ask(r, c + 1, n, n)) { c++; ok[r][c] = true; }
		else { r++; ok[r][c] = true; }
	r = n, c = n;
	ok[r][c] = true;
	while (abs(r - n) + abs(c - n) < n - 1)
		if (Ask(1, 1, r - 1, c)) { r--; ok[r][c] = true; }
		else { c--; ok[r][c] = true; }
	r = 1, c = 1;
	string s;
	while (r != n || c != n)
		if (Inside(r, c + 1) && ok[r][c + 1]) { s += "R"; c++; }
		else { s += "D"; r++; }
	printf("! %s\n", s.c_str()); fflush(stdout);
	return 0;
}