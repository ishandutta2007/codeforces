#include <cstdio>
#include <algorithm>
#define MN 301000

struct xxx{
	int x, id;
}d[MN];

struct Q{
	int k, p, id;
}q[MN]; 

bool cmp(xxx a, xxx b) {return a.x == b.x ? a.id < b.id : a.x > b.x;}
bool cmp2(Q a, Q b) {return a.k < b.k;}

int c[MN], ans[MN];
int n, a[MN];

void add(int x) {for(int i = x; i <= 262144; i += i & -i) c[i]++; }
int query(int k)
{
	int b = 131072, now = 0;
	while(b)
	{
		if(c[now + b] < k)
		{
			k -= c[now + b]; 
			now += b;
		}
		b >>= 1;
	}
	return now + 1;
}

int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) scanf("%d", &a[i]), d[i].x = a[i], d[i].id = i;
	std::sort(d + 1, d + n + 1, cmp);
	int m; scanf("%d", &m);
	for(int i = 1; i <= m; i++) scanf("%d%d", &q[i].k, &q[i].p), q[i].id = i;
	std::sort(q + 1, q + m + 1, cmp2);
	int j = 1;
	for(int i = 1; i <= n; i++)
	{
		add(d[i].id);
		while(j <= m && q[j].k == i) ans[q[j].id] = query(q[j].p), j++;
	}
	for(int i = 1; i <= m; i++) printf("%d\n", a[ans[i]]);
}