#include <bits/stdc++.h>
using namespace std;
int n, a, b, c;
char s[15];
struct node
{
	int fz, fm;
}f[200005], g[200005];
bool cmp(node u, node v) {return u.fz * v.fm < u.fm * v.fz;}
void getabc()
{
	int x = 1;
	a = s[x] - '0', x++;
	if (s[x] != '+') a = a * 10 + s[x] - '0', x++;
	x++;
	b = s[x] - '0', x++;
	if (s[x] != ')') b = b * 10 + s[x] - '0', x++;
	x += 2;
	c = s[x] - '0', x++;
	if (s[x] != '\0') c = c * 10 + s[x] - '0', x++;

}
int main()
{
#ifdef _noname
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%s", s);
		getabc();
		f[i].fz = g[i].fz = a + b;
		f[i].fm = g[i].fm = c;
	//	fprintf(stderr, "%d/%d\n", g[i].fz, g[i].fm);
	}
	sort(g + 1, g + n + 1, cmp);
	for (int i = 1; i <= n; i++)
		printf("%d ", upper_bound(g + 1, g + n + 1, f[i], cmp) - lower_bound(g + 1, g + n + 1, f[i], cmp));
	puts("");
	return 0;
}