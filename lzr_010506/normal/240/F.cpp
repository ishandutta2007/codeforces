#include <bits/stdc++.h>
#define N 200010
#define lx rt << 1
#define rx rt << 1 | 1
#define lson l, mid, lx
#define rson mid + 1, r, rx
using namespace std;
struct Tree
{
	int l, r, sum[30], Lazy;
}a[N * 4];
char ch[N];
int n, m, cs[30];

void push_up(int rt)
{
	for(int i = 0; i < 26; i ++)
		a[rt].sum[i] = a[lx].sum[i] + a[rx].sum[i];
}

void Clear(int rt)
{
    a[rt].Lazy = -1;
    for(int i = 0; i < 26; i ++)
		a[rt].sum[i] = 0;
}

void push_down(int rt)
{
	if(a[rt].Lazy != -1)
	{
		int mid = (a[rt].l + a[rt].r) >> 1;
        int id = a[rt].Lazy;
        Clear(lx);
		Clear(rx);
        a[lx].Lazy = a[rx].Lazy = a[rt].Lazy;
        a[lx].sum[id] = mid - a[rt].l + 1;
		a[rx].sum[id] = a[rt].r - mid;
        a[rt].Lazy = -1;
	}
}

void Build(int l, int r, int rt)
{
	a[rt].Lazy = -1;
	a[rt].l = l;
	a[rt].r = r;
	if(l == r)
	{
		a[rt].sum[ch[l] - 'a'] ++;
		a[rt].Lazy = ch[l] - 'a';
		return;
	}
	int mid = (l + r) >> 1;
	Build(lson);
	Build(rson);
	push_up(rt);
}

void Update(int l, int r, int rt, int id, int x, int y)
{
    if(x <= l && r <= y)
    {
        Clear(rt);
        a[rt].Lazy = id;
        a[rt].sum[id] = r - l + 1;
        return ;
	}
    push_down(rt);
    int mid = (l + r) >> 1;
    if(x <= mid) Update(lson, id, x, y);
    if(y > mid) Update(rson, id, x, y);
    push_up(rt);
}


void Query(int l, int r, int rt, int x, int y)
{
	if(x <= l && r <= y)
    {
		for(int i = 0; i < 26; i ++)
			cs[i] += a[rt].sum[i];
        return;
    }
    push_down(rt);
    int mid = (l + r) >> 1;
    if(x <= mid) Query(lson, x, y);
    if(y > mid) Query(rson, x, y);
    push_up(rt);
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	scanf("%d %d", &n, &m);
	scanf("%s", ch + 1);
	Build(1, n, 1);

	while(m --)
	{
		int l, r;
		scanf("%d %d", &l, &r);
		memset(cs, 0, sizeof(cs));
		Query(1, n, 1, l, r);
		int flag = 0, pp = 1;
		for(int i = 0; i < 26; i ++)
        {
            if(cs[i] % 2) flag ++;
			if(flag > 1) pp = 0;
        }
        if(!pp) continue;
		int ll = l, rr = r;
		int mid = (l + r) >> 1;
		for(int i = 0; i < 26; i ++)
			if(cs[i])
			{
				if(cs[i] / 2)
				{
					Update(1, n, 1, i, ll, ll + cs[i] / 2 - 1);
					Update(1, n, 1, i, rr - cs[i] / 2 + 1, rr);
					ll += cs[i] / 2;
					rr -= cs[i] / 2;
				}
				if(cs[i] % 2) Update(1, n, 1, i, mid, mid);
			}
	}

	for(int i = 1; i <= n; i ++)
	{
		memset(cs, 0, sizeof(cs));
		Query(1, n, 1, i, i);
		for(int j = 0; j < 26; j ++)
			if(cs[j]) printf("%c", j + 'a');
	}

	return 0;
}