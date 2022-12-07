#include <bits/stdc++.h>
#define N 200005
#define lowbit(x) (x&(-x))
#define FOR(i, x, y) for(int (i) = (x); (i) <= (y); (i) ++)
using namespace std;
int m,Q,cnt,top;
int a[N],b[N],c[N];
int v[N],sa[2][N],rk[2][N],h[N],p,q;
int mn[N][19],lg[N];
struct node
{
	int l,r,id;
	bool operator <(const node &a)const
	{
		return l + r < a.l + a.r;
	}
}qq[N];
void mul(int k,int *sa,int *rk,int *SA,int *RK)
{
	FOR(i, 1, cnt) v[rk[sa[i]]] = i;
	for(int i = cnt; i; i --)
		if(sa[i] > k)
			SA[v[rk[sa[i] - k]] --] = sa[i] - k;
	FOR(i, cnt - k + 1, cnt) SA[v[rk[i]] --] = i;
	FOR(i, 1, cnt) RK[SA[i]] = RK[SA[i - 1]] + (rk[SA[i]] != rk[SA[i - 1]] || rk[SA[i - 1] + k] != rk[SA[i] + k]);
}
void get_sa(int lim)
{
	p = 1;
	FOR(i, 1, cnt) v[b[i]] ++;
	FOR(i, 1, lim) v[i] += v[i - 1];
	FOR(i, 1, cnt) sa[p][v[b[i]] --] = i;
	FOR(i, 1, cnt)
		rk[p][sa[p][i]] = rk[p][sa[p][i - 1]] + (b[sa[p][i]] != b[sa[p][i - 1]]);
	for(int k = 1; k <= cnt; k <<= 1)
	{
		mul(k,sa[p], rk[p], sa[q], rk[q]);
		swap(p, q);
	}
	for(int j, k = 0, i = 1; i <= cnt; i ++)
	{
		j = sa[p][rk[p][i] - 1];
		while(b[i + k] == b[j + k]) k ++;
		h[rk[p][i]] = k;
		if(k) k --;
	}
}
void add(int x,int y)
{
	for(; x <= cnt; x += lowbit(x)) c[x] += y;
}
int query(int x)
{
	int ret = 0;
	for(; x; x -= lowbit(x)) ret += c[x];
	return ret;
}
int get_mn(int l,int r)
{
	int t = lg[r - l + 1];
	return min(mn[l][t], mn[r - (1 << t) + 1][t]);
}
int get_ans(int pos,int k)
{
	int tl = pos + 1, tr = pos - 1;
	int l = pos + 1, r = cnt, mid;
	while(l <= r)
	{
		mid = (l + r) >> 1;
		if(get_mn(pos + 1, mid) >= k) l = mid + 1, tr = mid;
		else r = mid - 1;
	}
	r = pos, l = 2;
	while(l <= r)
	{
		mid = (l + r) >> 1;
		if(get_mn(mid, pos) >= k) tl = mid, r = mid - 1;
		else l = mid + 1;
	}
	return query(tr) - query(tl - 2);
}
int ans[N];
bool cmp1(const node &a,const node &b)
{
	return a.l - a.r < b.l - b.r;
}
int main()
{
	cin >> m;
	FOR(i, 1, m)
	{
		scanf("%d", &a[i]);
		if(i > 1) b[++ cnt] = a[i] - a[i - 1];
	}
	b[++ cnt] = 0x3f3f3f3f;
	FOR(i, 2, m) b[++ cnt] = a[i - 1] - a[i];
	FOR(i, 1, cnt) c[i] = b[i];
	sort(c + 1, c + cnt + 1);
	top = unique(c + 1, c + cnt + 1) - c - 1;
	FOR(i, 1, cnt) b[i] = lower_bound(c + 1, c + top + 1, b[i]) - c;
	get_sa(top);
	FOR(i, 1, cnt) mn[i][0] = h[i];
	for(int j = 1; (1 << j) <= cnt; j ++)
		for(int i = 1; i + (1 << j) - 1 <= cnt; i ++)
			mn[i][j] = min(mn[i][j - 1], mn[i + (1 << j - 1)][j - 1]);
	for(int i = 2; i <= cnt; i ++) lg[i] = lg[i >> 1] + 1;
	cin >> Q;
	for(int i = 1; i <= Q; i ++)
	{
		scanf("%d%d", &qq[i].l, &qq[i].r);
		qq[i].r -= qq[i].l;
		qq[i].id = i;
	}
	sort(qq + 1, qq + Q + 1);
	memset(c,0,sizeof(c));
	for(int j = m - 1, i = Q; i; i --)
	{
		while(j > 1 && j > qq[i].l + qq[i].r) add(rk[p][j + m], 1), j --;
		ans[qq[i].id] = get_ans(rk[p][qq[i].l],qq[i].r);
	}
	sort(qq + 1, qq + Q + 1, cmp1);
	memset(c, 0, sizeof(c));
	for(int j = 1, i = 1; i <= Q; i ++)
	{
		while(j < m && j + qq[i].r < qq[i].l) add(rk[p][j + m], 1), j ++;
		ans[qq[i].id] += get_ans(rk[p][qq[i].l], qq[i].r);
		if(qq[i].r == 0) ans[qq[i].id] = m - 1;
	}
	for(int i = 1; i <= Q; i ++) printf("%d\n", ans[i]);
	return 0;
}