#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#define N 200010
#define lx rt << 1
#define rx rt << 1 | 1
#define lson l, mid, lx
#define rson mid + 1, r, rx
using namespace std;
struct Tree
{
	int l, r, sum[30], add;
}a[N * 4];
char str[N];
int n, m, cs[30];

void push_up(int rt)
{
	for(int i = 0; i < 26; i ++)
		a[rt].sum[i] = a[lx].sum[i] + a[rx].sum[i];
}

void mz(int rt)
{
    a[rt].add = -1;
    for(int i = 0; i < 26; i ++)
		a[rt].sum[i] = 0;
}

void push_down(int l, int r, int rt)
{
	if(a[rt].add != -1)
	{
		int mid = (l + r) >> 1;
        int id = a[rt].add;
        mz(lx);
		mz(rx); 
        a[lx].add = a[rx].add = a[rt].add;
        a[lx].sum[id] = mid - l + 1;
		a[rx].sum[id] = r - mid;
        a[rt].add = -1;
	}
}

void build(int l, int r, int rt)
{
	a[rt].add = -1;
	a[rt].l = l;
	a[rt].r = r;
	if(l == r)
	{
		a[rt].sum[str[l] - 'a'] ++;
		a[rt].add = str[l] - 'a';
		return;
	}
	int mid = (l + r) >> 1;
	build(lson);
	build(rson);
	push_up(rt);
}

void update(int l, int r, int rt, int id, int x, int y)
{
    if(x <= l && r <= y)
    {
        mz(rt);
        a[rt].add = id;
        a[rt].sum[id] = r - l + 1;
        return ;
	}
    push_down(l, r, rt); 
    int mid = (l + r) >> 1;
    if(x <= mid) update(lson, id, x, y);
    if(y > mid) update(rson, id, x, y);
    push_up(rt);
}

void query(int l, int r, int rt, int x,int y)
{
 
    if(x <= l && r <= y)
    {
		for(int i = 0; i < 26; i ++)
			cs[i] += a[rt].sum[i];
        return ;
    }
    push_down(l,r,rt);
    int mid = (l + r) >> 1;
    if(x <= mid) query(lson, x, y);
    if(y > mid) query(rson, x, y);
    push_up(rt);
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	scanf("%d %d", &n, &m);
	scanf("%s", str + 1);
	build(1, n, 1);
	
	for(int Z = 1; Z <= m; Z ++)
	{
		int l, r;
		scanf("%d %d", &l, &r);
		int s = -1, ss = 0, pp = 1;
		memset(cs,0,sizeof(cs));
		query(1, n, 1, l, r);
		for(int i = 0; i < 26; i ++)
		{
			if(cs[i] % 2) 
			{
				ss ++;
				s = i;
			}
			if(ss > 1) {pp = 0; break;}
		}
		if(pp == 0) continue;
		int ll = l, rr = r;
		int mid = (l + r) >> 1;
		for(int i = 0; i < 26; i ++)
			if(cs[i])
			{
				if(cs[i] / 2)
				{
					update(1, n, 1, i, ll, ll + cs[i] / 2 - 1);
					update(1, n, 1, i, rr - cs[i] / 2 + 1, rr);
					ll = ll + cs[i] / 2;
					rr = rr - cs[i] / 2;
				}
				if(cs[i] % 2 == 1)
                	update(1, n, 1, i, mid, mid);
			}
    	
	}
	
	for(int i = 1; i <= n; i ++)
    {
		memset(cs,0,sizeof(cs));
		query(1, n, 1, i, i);
        for(int j = 0; j < 26; j ++)
            if(cs[j])
            {
                printf("%c", 'a' + j);
				break;
            }
    }
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}