#include <cstdio>
#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <cstring> 
#define MN 201000

struct xxx{
	int x, l, r, t, id;
	xxx(){}
	xxx(int _x, int _l, int _r, int _t, int _id) {x = _x; l = _l; r = _r; t = _t; id = _id;}
}q[MN * 10], cur[MN * 10]; 
int c[MN], n, a[MN], b[MN], wza[MN], wzb[MN], ans[MN];

void add(int x, int v) {for(int i = x; i <= n; i += i & -i) c[i] += v;}
int query(int x) {int ans = 0; for(int i = x; i; i -= i & -i) ans += c[i]; return ans;}

void CDQ(int l, int r)
{
	if(l >= r) return;
	int mid = l + r >> 1;
	CDQ(l, mid); CDQ(mid + 1, r);
	int v = l;
	int j = l, k = mid + 1;
	while(j <= mid && k <= r)
	{
		
		if(q[j].x <= q[k].x)
		{
			if(q[j].id == 0) add(q[j].l, q[j].t);
			cur[v++] = q[j++];
		}
		else
		{
			if(q[k].id != 0)
			{
				ans[q[k].id] += q[k].t * (query(q[k].r) - query(q[k].l - 1));
			}
			cur[v++] = q[k++];
		}
	}
	while(j <= mid)
	{
		if(q[j].id == 0) add(q[j].l, q[j].t);
		cur[v++] = q[j++];
	}
	while(k <= r)
	{
		if(q[k].id != 0)
		{
			ans[q[k].id] += q[k].t * (query(q[k].r) - query(q[k].l - 1));
		}
		cur[v++] = q[k++];
	}
	for(int i = l; i <= mid; i++)
	{
		if(q[i].id == 0) add(q[i].l, -q[i].t);
	}
	for(int i = l; i <= r; i++) q[i] = cur[i]; 
}

int main()
{
	int m; scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++) scanf("%d", &a[i]), wza[a[i]] = i;
	for(int i = 1; i <= n; i++)
	{
		scanf("%d", &b[i]);
		wzb[b[i]] = i;
	}
	int tot = 0;
	for(int i = 1; i <= n; i++)
	{
		q[++tot] = xxx(wzb[a[i]], i, 0, 1, 0);
		//(i, b[a[i]])
	}
	for(int i = 1; i <= m; i++)
	{
		int o, A, B, C, D; scanf("%d%d%d", &o, &A, &B);
		if(o == 1)
		{
			scanf("%d%d", &C, &D);
			q[++tot] = xxx(C - 1, A, B, -1, i);
			q[++tot] = xxx(D, A, B, 1, i);
		}
		else
		{
			ans[i] = -1;
			q[++tot] = xxx(A, wza[b[A]], 0, -1, 0);
			q[++tot] = xxx(B, wza[b[B]], 0, -1, 0);
			std::swap(b[A], b[B]);
			q[++tot] = xxx(A, wza[b[A]], 0, 1, 0);
			q[++tot] = xxx(B, wza[b[B]], 0, 1, 0);
		}
	}
	CDQ(1, tot);
	for(int i = 1; i <= m; i++) if(ans[i] != -1) printf("%d\n", ans[i]);
	return 0;
}