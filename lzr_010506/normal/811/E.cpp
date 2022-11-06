#include <bits/stdc++.h>
using namespace std;
inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}
int n, m, q;
int a[12][100005];
int tmp[24];
int fa[45];
inline int find(int k)
{
	return fa[k] == k ? k : fa[k] = find(fa[k]);
}
struct tree
{
	int l[12],r[12],L[12],R[12];
	int ans;
	void pushup(tree ls,tree rs)
	{
		ans = ls.ans + rs.ans;
		for(int i = 1; i <= n; i ++)
			fa[i] = ls.L[i], fa[i + n] = ls.R[i], fa[i + 2 * n] = rs.L[i] + 2 * n, fa[i + 3 * n] = rs.R[i] + 2 * n;
		for(int i = 1; i <= n; i ++)
			if(ls.r[i] == rs.l[i])
			{
				int u = find(n + i), v = find(2 * n + i);
				if(u != v) fa[u] = v, ans --;
			}
		for(int i = 1; i <= n; i ++) L[i] = R[i] = 0;
		for(int i = 1; i <= n; i ++) 
			if(L[i] == 0)
			{
				L[i] = i;
				for(int j = i + 1; j <= n; j ++)
					if(find(i) == find(j)) L[j] = i;
				for(int j = 1; j <= n; j ++)
					if(find(3 * n + j) == find(i)) R[j] = i;
			}
		for(int i = 1; i <= n; i ++)
			if(!R[i])
			{
				R[i] = i + n;
				for(int j = i + 1; j <= n; j ++)
					if(find(3 * n + i) == find(3 * n + j))R[j] = i + n;
			}
		for(int i = 1; i <= n; i ++)
			l[i] = ls.l[i], r[i] = rs.r[i];
	}
}t[400005];
#define mid ((l + r) >> 1)
#define lson rt << 1
#define rson rt << 1 | 1
void build(int l,int r,int rt)
{
	if(l == r)
	{
		t[rt].ans = n;
		t[rt].L[1] = t[rt].R[1] = 1;
		for(int i = 2; i <= n; i ++)
			if(a[i][l] == a[i - 1][l])
				t[rt].ans --, t[rt].L[i] = t[rt].R[i] = i - 1;
		else t[rt].L[i] = t[rt].R[i] = i;
		for(int i = 1; i <= n; i ++)
			t[rt].l[i] = t[rt].r[i]=a[i][l];
		return;
	}
	build(l, mid, lson);
	build(mid + 1, r, rson);
	t[rt].pushup(t[lson], t[rson]);
}
inline tree query(int l,int r,int L,int R,int rt)
{
	if((L <= l) && (R >= r))return t[rt];
	if(L > mid)return query(mid + 1, r, L, R, rson);
	if(R <= mid)return query(l, mid,L, R, lson);
	tree tmp1 = query(l, mid, L, R, lson), tmp2 = query(mid + 1, r, L, R, rson);
	tree ans;
	ans.pushup(tmp1,tmp2);
	return ans;
}
int main()
{
	n = read();
	m = read();
	q = read();
	for(int i = 1; i <= n; i ++)
		for(int j = 1; j <= m; j ++)
			a[i][j] = read();
	build(1, m, 1);
	while(q --)
	{
		int l = read(), r = read();
		printf("%d\n",query(1,m,l,r,1).ans);
	}
}