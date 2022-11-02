#include <bits/stdc++.h>
using namespace std;
int n;
char s[15][15], to[15][15];
void turn()
{
	static char c[15][15];
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			c[i][j] = s[n - j + 1][i];
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			s[i][j] = c[i][j];
}
void flip()
{
	static char c[15][15];
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			c[i][j] = s[n - i + 1][j];
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			s[i][j] = c[i][j];
}
bool chk()
{
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			if (s[i][j] != to[i][j])
				return false;
	return true;
}
int main()
{
#ifdef _noname
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%s", s[i] + 1);
	for (int i = 1; i <= n; i++) scanf("%s", to[i] + 1);
	if (chk()) {puts("Yes"); return 0;}
	turn();
	if (chk()) {puts("Yes"); return 0;}
	turn();
	if (chk()) {puts("Yes"); return 0;}
	turn();
	if (chk()) {puts("Yes"); return 0;}
	flip();
	if (chk()) {puts("Yes"); return 0;}
	turn();
	if (chk()) {puts("Yes"); return 0;}
	turn();
	if (chk()) {puts("Yes"); return 0;}
	turn();
	if (chk()) {puts("Yes"); return 0;}
	puts("No");
	return 0;
}