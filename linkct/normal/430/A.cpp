#include <stdio.h>
#include <algorithm>
using std :: sort;
struct point
{
	int pos, n, col;
	bool operator < (const point& x) const{return pos < x.pos;}
}data[105];
bool cmp(const point& a, const point& b)
{return a.n < b.n;}
int main()
{
	int n, i, m;
	scanf("%d%d", &n, &m);
	for(i = 1; i <= n; i ++)
	{
		scanf("%d", &data[i].pos);
		data[i].n = i;
	}
	sort(data + 1, data + 1 + n);
	for(i = 1; i <= n; i ++)
		data[i].col = i % 2;
	sort(data + 1, data + 1 + n, cmp);
	for(i = 1; i <= n; i ++)
		printf("%d ", data[i].col);
	return 0;
}