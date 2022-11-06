#include <cstdio>
#include <map>
#include <iostream>
#define MN 801000

typedef long long ll;
ll Min[MN], lazy[MN];
int a[MN], q1[MN], top1, q2[MN], top2;
int lst[MN];

std::map<int, int> mp;

void add(int x, ll v) {Min[x] += v; lazy[x] += v;}
void pd(int x) {if(lazy[x]) add(x << 1, lazy[x]), add(x << 1 | 1, lazy[x]), lazy[x] = 0;}

void modify(int x, int l, int r, int L, int R, ll v)
{
	if(l == L && r == R) {add(x, v); return;}
	pd(x); int mid = l + r >> 1;
	if(R <= mid) modify(x << 1, l, mid, L, R, v);
	else if(L > mid) modify(x << 1 | 1, mid + 1, r, L, R, v);
	else modify(x << 1, l, mid, L, mid, v), modify(x << 1 | 1, mid + 1, r, mid + 1, R, v);
	Min[x] = std::min(Min[x << 1], Min[x << 1 | 1]);
}

int query(int x, int l, int r, ll k)
{
	if(l == r) return l;
	pd(x); int mid = l + r >> 1;
	if(Min[x << 1] <= k) return query(x << 1, l, mid, k);
	else return query(x << 1 | 1, mid + 1, r, k);
}

int main()
{
	int n, k, d; scanf("%d%d%d", &n, &k, &d);
	for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
	
	int Max = 1;
	int L = 0, R = -1;
	
	if(d == 0)
	{
		for(int i = 1; i <= n; i++)
		{
			if(a[i] == a[i - 1]) lst[i] = lst[i - 1];
			else lst[i] = i;
			if(i - lst[i] > R - L) L = lst[i], R = i;
		}
		printf("%d %d\n", L, R);
		return 0;
	}
	
	for(int i = 1; i <= n; i++)
	{
		if((a[i] % d + d) % d == (a[i - 1] % d + d) % d)
			lst[i] = std::max(lst[i - 1], mp[a[i]] + 1);
		else lst[i] = i;
		mp[a[i]] = i;
	}
	for(int i = 1; i <= n; i++)
	{
		modify(1, 1, n, i, i, 1ll * i * d);
		while(top1 && a[q1[top1]] >= a[i])
		{
			modify(1, 1, n, q1[top1 - 1] + 1, q1[top1], a[q1[top1]] - a[i]);
			top1--;
		}
		q1[++top1] = i;
		
		while(top2 && a[q2[top2]] <= a[i])
		{
			modify(1, 1, n, q2[top2 - 1] + 1, q2[top2], a[i] - a[q2[top2]]);
			top2--;
		}
		q2[++top2] = i;
		
		if(lst[i] > Max) modify(1, 1, n, Max, lst[i] - 1, (ll)1e18), Max = lst[i];
		int j = query(1, 1, n, 1ll * k * d + 1ll * i * d);
		if(i - j > R - L) L = j, R = i;
	}
	printf("%d %d\n", L, R);
	return 0;
}