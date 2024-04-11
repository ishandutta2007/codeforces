#include <bits/stdc++.h>
#define Accepted 0
using namespace std;
const int maxn = 250000;
int test, n, a[255555], Log[555555], mx[22][255555], mn[22][255555];
int st1[255555], st2[255555], top1, top2, dp[255555][2], tree1[2222222], tree2[2222222];
int getmx(int l, int r)
{
	int x = Log[r - l + 1];
	return max(mx[x][l], mx[x][r - (1 << x) + 1]);
}
int getmn(int l, int r)
{
	int x = Log[r - l + 1];
	return min(mn[x][l], mn[x][r - (1 << x) + 1]);
}
void upd1(int x, int l, int r, int node, int y)
{
	if (l == r)
	{
		tree1[node] = y;
		return;
	}
	int mid = (l + r) >> 1;
	if (x > mid) upd1(x, mid + 1, r, (node << 1) | 1, y);
	else upd1(x, l, mid, node << 1, y);
	tree1[node] = min(tree1[node << 1], tree1[(node << 1) | 1]);
}
int query1(int beg, int en, int l, int r, int node)
{
	if (l > en || r < beg) return 1e9;
	if (l >= beg && r <= en) return tree1[node];
	int mid = (l + r) >> 1;
	return min(query1(beg, en, l, mid, node << 1), query1(beg, en, mid + 1, r, (node << 1) | 1));
}
void upd2(int x, int l, int r, int node, int y)
{
	if (l == r)
	{
		tree2[node] = y;
		return;
	}
	int mid = (l + r) >> 1;
	if (x > mid) upd2(x, mid + 1, r, (node << 1) | 1, y);
	else upd2(x, l, mid, node << 1, y);
	tree2[node] = min(tree2[node << 1], tree2[(node << 1) | 1]);
}
int query2(int beg, int en, int l, int r, int node)
{
	if (l > en || r < beg) return 1e9;
	if (l >= beg && r <= en) return tree2[node];
	int mid = (l + r) >> 1;
	return min(query2(beg, en, l, mid, node << 1), query2(beg, en, mid + 1, r, (node << 1) | 1));
}
int main()
{
    scanf("%d", &test);
    while(test--)
    {
        scanf("%d", &n);
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &a[i]);
		}
		for (int i = 1; i <= 4 * n; i++)
		{
			tree1[i] = tree2[i] = 1e9;
		}
		for (int i = 1; i <= n; i++) dp[i][0] = dp[i][1] = 1e9;
		dp[1][0] = dp[1][1] = 0;
		top1 = top2 = 1;
		st1[1] = st2[1] = 1;
		upd1(1, 1, n, 1, 0);upd2(1, 1, n, 1, 0);
		for (int i = 2; i <= n; i++)
		{
			int tt = top1;
			while(tt > 0 && a[i] > a[st1[tt]]) tt--;
			if (tt == 0) dp[i][0] = query2(1, i - 1, 1, n, 1) + 1;
			else dp[i][0] = query2(st1[tt] + 1, i - 1, 1, n, 1) + 1; 
			tt = top2; 
			while(tt > 0 && a[i] < a[st2[tt]]) tt--;
			if (tt == 0) dp[i][1] = query1(1, i - 1, 1, n, 1) + 1;
			else dp[i][1] = query1(st2[tt] + 1, i - 1, 1, n, 1) + 1; 
			while(top1 > 0 && a[i] > a[st1[top1]])
			{
				upd1(st1[top1], 1, n, 1, 1e9);
				top1--;
			}
			st1[++top1] = i;
			upd1(i, 1, n, 1, dp[i][0]);
			while(top2 > 0 && a[i] < a[st2[top2]])
			{
				upd2(st2[top2], 1, n, 1, 1e9);
				top2--;
			}
			st2[++top2] = i;
			upd2(i, 1, n, 1, dp[i][1]);
		}
		printf("%d\n", min(dp[n][0], dp[n][1]));
    }
	return Accepted;
}