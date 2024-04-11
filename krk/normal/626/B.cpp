#include <cstdio>
#pragma comment(linker, "/STACK:16000000")
using namespace std;

const int Maxn = 205;

int n;
char str[Maxn];
int vis[Maxn][Maxn][Maxn];

void Visit(int r, int g, int b)
{
	if (vis[r][g][b]) return;
	vis[r][g][b] = true;
	if (r + g + b <= 1) return;
	if (r >= 1 && g >= 1) Visit(r - 1, g - 1, b + 1);
	if (r >= 1 && b >= 1) Visit(r - 1, g + 1, b - 1);
	if (g >= 1 && b >= 1) Visit(r + 1, g - 1, b - 1);
	if (r >= 2) Visit(r - 1, g, b);
	if (g >= 2) Visit(r, g - 1, b);
	if (b >= 2) Visit(r, g, b - 1);
}

int main()
{
	scanf("%d", &n); scanf("%s", str);
	int r = 0, g = 0, b = 0;
	for (int i = 0; i < n; i++)
		if (str[i] == 'R') r++;
		else if (str[i] == 'G') g++;
		else if (str[i] == 'B') b++;
	Visit(r, g, b);
	if (vis[0][0][1]) printf("B");
	if (vis[0][1][0]) printf("G");
	if (vis[1][0][0]) printf("R");
	printf("\n");
	return 0;
}