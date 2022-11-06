#include <bits/stdc++.h>
#define inf 10000000
using namespace std;

struct Node
{
	int a[6][6];
}dp[800010];
char ch[800010];
int n, q;

Node Add(Node a, Node b)
{
	Node c;
	for(int i = 0; i < 6; i ++)
		for(int j = 0; j < 6; j ++)
		{
			c.a[i][j] = inf;
			for(int k = 0; k < 6; k ++)
				c.a[i][j] = min(a.a[i][k] + b.a[k][j], c.a[i][j]);
		}
	return c;
}

void build(int rt, int l, int r)
{
	if(l < r)
	{
		int mid = (l + r) >> 1;
		build(rt << 1, l, mid);
		build(rt << 1 | 1, mid + 1, r);
		dp[rt] = Add(dp[rt << 1], dp[rt << 1 | 1]);
	}
	else
	{
	    for (int i = 0; i < 6; i ++)
			for (int j = 0; j < 6; j ++)
				dp[rt].a[i][j] = inf;
		for (int i = 0; i < 6; i ++)
				dp[rt].a[i][i] = 0;
		if(ch[l] == '2') dp[rt].a[0][0] = 1, dp[rt].a[0][1] = 0;
		if(ch[l] == '0') dp[rt].a[1][1] = 1, dp[rt].a[1][2] = 0;
		if(ch[l] == '1') dp[rt].a[2][2] = 1, dp[rt].a[2][3] = 0;
		if(ch[l] == '7') dp[rt].a[3][3] = 1, dp[rt].a[3][5] = 0;
		if(ch[l] == '6') dp[rt].a[3][3] = dp[rt].a[5][5] = 1, dp[rt].a[3][4] = dp[rt].a[5][4] = 0;
	}
}

Node query(int rt, int l, int r, int x, int y)
{
    if(l >= x && r <= y) return dp[rt];
    int mid = (l + r) >> 1;
    if(y <= mid) return query(rt << 1, l, mid, x, y);
    else if(x > mid) return query(rt << 1 | 1, mid + 1, r, x, y);
    else return Add(query(rt << 1, l, mid, x, y), query(rt << 1 | 1, mid + 1, r, x, y));
}

int main()
{
	scanf("%d %d", &n, &q);
	scanf("%s", ch + 1);
	build(1, 1, n);
	/*
	for(int i = 1; i <= 29; i ++)
    {
        cout << i << endl;
        for(int j = 0; j < 6; j ++, cout << endl)
            for(int k = 0; k < 6; k ++)
                cout << dp[i].a[j][k] << " ";
        cout << endl;
    }
    */
	for(int i = 1; i <= q; i ++)
	{
		int l, r;
		scanf("%d%d", &l, &r);
		int ans = query(1, 1, n, l, r).a[0][5];
		if(ans == inf) cout << -1 << endl;
		else cout << ans << endl;
	}
	return 0;
}