#include <bits/stdc++.h>
#define ll long long
#define ls x << 1
#define rs x << 1 | 1
#define lson ls, l, mid
#define rson rs, mid + 1, r
#define INF 1000000007
using namespace std;
int n, a[200010], L[800010], R[800010], tag[800010] ;
ll sum[800010], minv[800010][2];

void build(int x, int l, int r)
{
	L[x] = l;
	R[x] = r;
	if(l == r)
	{
		sum[x] = a[l];
		minv[x][0]  = a[l]; 
		minv[x][1] = INF;
		return;
	} 
	int mid = (l + r) >> 1;
	build(lson);
	build(rson);
	int k = ((mid - l + 1) & 1);
	sum[x] = sum[ls] + (k ? -sum[rs] : sum[rs]);
	minv[x][0] = min(minv[ls][0], k ? minv[rs][1] + sum[ls] : minv[rs][0] + sum[ls]);
	minv[x][1] = min(minv[ls][1], k ? minv[rs][0] - sum[ls] : minv[rs][1] - sum[ls]);
}

void pushdown(int x) 
{
	if (tag[x]) 
	{
		int tg = tag[x];
		tag[x] = 0;
		tag[ls] += tg, tag[rs] += tg; 
		minv[ls][0] += tg, minv[rs][0] += tg;
		sum[ls] += tg * ((R[ls] - L[ls] + 1) & 1);
		sum[rs] += tg * ((R[rs] - L[rs] + 1) & 1); 
	}
}


void Modify(int x,int l,int r,int v) 
{
	if (L[x] == l && R[x] == r) 
	{
		tag[x] += v;
		minv[x][0] += v;
		sum[x] += v * ((r - l + 1) & 1);
		return; 
	}
	pushdown(x);
	int mid = (L[x] + R[x]) >> 1;
	if (r <= mid) Modify(x << 1, l, r, v);
	else if (l > mid) Modify((x << 1) | 1, l, r, v);
	else Modify(lson, v), Modify(rson, v) ; 
	int k = ((mid - L[x] + 1) & 1);  
	sum[x] = sum[ls] + (k ? -sum[rs]  : sum[rs]) ; 
	minv[x][0] = min(minv[ls][0] , k ? minv[rs][1] + sum[ls]: minv[rs][0] + sum[ls]);  
	minv[x][1] = min(minv[ls][1], k ? minv[rs][0] - sum[ls] : minv[rs][1] - sum[ls]);
}

pair<ll, pair<ll,ll> > Query(int x,int l,int r) 
{
	if (L[x] == l &&  R[x] == r) 
		return make_pair(sum[x], make_pair(minv[x][0], minv[x][1])); 
	pushdown(x) ;
	int mid = (L[x] + R[x]) >> 1; 
	if (r <= mid) return Query(x << 1, l, r) ;
	if (l > mid) return Query((x << 1) | 1, l, r) ;
	pair<ll,pair<ll, ll> > p1 = Query(lson), p2 = Query(rson), p; 
	int k = (mid - l + 1) & 1;  
	p.first = p1.first + (k ? -p2.first : p2.first); 
	p.second.first = min(p1.second.first, k ? p2.second.second + p1.first : p2.second.first + p1.first);
	p.second.second = min(p1.second.second, k ? p2.second.first - p1.first : p2.second.second - p1.first);
	return p ; 
}

bool Solve(int l,int r) 
{
	pair<ll, pair<ll, ll> > p = Query(1, l, r);
	if (p.first) return 0; 
	if (min(p.second.first, p.second.second) < 0) return 0;
	return 1 ;
}

int main() 
{
	scanf("%d", &n);
	for (int i = 1;i <= n;i ++) scanf("%d", &a[i]), a[i] -- ;
	build(1, 1, n) ;
	int T;
	scanf("%d" ,&T) ;
	while (T --) 
	{
	int op; 
	scanf("%d", &op);
	if (op == 1) 
	{
		int l, r, k ;
		scanf("%d%d%d", &l, &r, &k);
		l ++;
		r ++;
		Modify(1, l, r, k);
	}
	else 
	{
		int l, r ;
		scanf("%d%d" ,&l, &r); 
		puts(Solve( ++ l, ++ r) ? "1" : "0"); 
	}
	}
	return 0;
}