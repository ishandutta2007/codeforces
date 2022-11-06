#include <cstdio>
#include <iostream>
#define MN 4010000

int Max[MN], lazy[MN], a[MN]; 
int st[MN], top = 0; 

void add(int x, int k) {Max[x] += k; lazy[x] += k;}
 
void pd(int x)
{
    if(lazy[x])
    {
        add(x << 1, lazy[x]);
        add(x << 1 | 1, lazy[x]);
        lazy[x] = 0;
    }
}
 
void modify(int x, int l, int r, int L, int R)
{
    if(L == l && R == r) {add(x, 1); return;}
    pd(x); int mid = l + r >> 1;
    if(R <= mid) modify(x << 1, l, mid, L, R);
    else if(L > mid) modify(x << 1 | 1, mid + 1, r, L, R);
    else modify(x << 1, l, mid, L, mid), modify(x << 1 | 1, mid + 1, r, mid + 1, R);
    Max[x] = std::max(Max[x << 1], Max[x << 1 | 1]);
}
 
int query(int x, int l, int r, int L, int R)
{
    if(L == l && R == r) {return Max[x];}
    pd(x); int mid = l + r >> 1;
    if(R <= mid) return query(x << 1, l, mid, L, R);
    else if(L > mid) return query(x << 1 | 1, mid + 1, r, L, R);
    else return std::max(query(x << 1, l, mid, L, mid), query(x << 1 | 1, mid + 1, r, mid + 1, R));
}

int main()
{
	int n, k; scanf("%d%d", &n, &k);
	for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
	for(int i = 1; i <= n; i++)
	{
		int l = 1, r = top + 1;
		while(l < r)
		{
			int mid = l + r >> 1;
			if(a[st[mid]] >= a[i]) l = mid + 1;
			else r = mid;
		}
		modify(1, 1, n, st[l - 1] + 1, i);
		while(top && a[st[top]] <= a[i]) top--;
		st[++top] = i;
		if(i >= k) printf("%d ", query(1, 1, n, i - k + 1, i));
	}
	return 0;
}

/*c
  [>=c+1, ]
  p1greedy subsequence1 
  xjb */