#include <bits/stdc++.h>
using namespace std;
struct Node
{
	int x, y;
}a[200010], b[200010];
int n, vis[200010], l[200010], num[2], cnt;
int L[200010], R[200010];
inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}

bool cmp(Node a, Node b)
{
	if(a.x == b.x) return a.y < b.y;
	return a.x < b.x;
}

bool cmp1(Node a, Node b)
{
    return a.y > b.y;
}

int Find(int l, int r, int x)
{
	int ans = l;
	while(l <= r)
	{
		int mid = (l + r) >> 1;
		if(a[mid].x <= x) ans = mid, l = mid + 1;
		else r = mid - 1;
	}
	return ans;
}

int main()
{
	n = read();
	for(int i = 1; i <= n; i ++)
    {
        a[i].x = read();
        a[i].y = read();
        b[i].x = i;
        b[ a[i].x ].y = max (b[a[i].x].y, a[i].y);
    }
	sort(a + 1, a + n + 1, cmp);
	sort(b + 1, b + n + 1, cmp1);
	for(int i = 1; i <= n; i ++)
	{
		if(a[i - 1].x != a[i].x) L[a[i].x] = i;
		if(a[i + 1].x != a[i].x) R[a[i].x] = i;
	}

	int Q = read();
	while(Q --)
	{
		int k = read();
		for(int i = 1; i <= k; i ++)
			l[i] = read(), vis[l[i]] = 1;
        cnt = 0;
		for(int i = 1; i <= n; i ++)
        {
            if(!b[i].y) break;
            if(vis[ b[i].x ] == 1) continue;
            num[cnt ++] = b[i].x;
            if(cnt == 2) break;
        }
		vis[ num[0] ] = 0;
		vis[ num[1] ] = 0;
		for(int i = 1; i <= k; i ++)
			vis[l[i]] = 0;
        if(cnt == 0) {printf("0 0\n"); continue;}
		if(cnt == 1) {printf("%d %d\n", num[0], a[ L[num[0] ] ].y ); continue;}
		int w = Find(1, n, num[1]);
		int ans = R[num[0]];
		int h = L[num[0]], t = R[num[0]];
		while(h <= t)
		{
			int mid = (h + t) >> 1;
			if(a[mid].y < a[w].y) h = mid + 1;
			else ans = mid, t = mid - 1;
		}
		printf("%d %d\n", num[0], a[ans].y);
	}

	return 0;
}