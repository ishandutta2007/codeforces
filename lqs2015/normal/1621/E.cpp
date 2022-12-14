#include <bits/stdc++.h>
using namespace std;
int test, n, m, a[111111], num[111111], x, y, suf[111111], tree[444444];
long long sum[111111], avg, navg;
vector<int> arr[111111];
void build(int l, int r, int node)
{
	if (l == r)
	{
		tree[node] = suf[l];
		return;
	}
	int mid = (l + r) >> 1;
	build(l, mid, node << 1);
	build(mid + 1, r, (node << 1) | 1);
	tree[node] = min(tree[node << 1], tree[(node << 1) | 1]);
}
int query(int beg, int en, int l, int r, int node)
{
	if (l > en || r < beg) return 1e9;
	if (l >= beg && r <= en) return tree[node];
	int mid = (l + r) >> 1;
	return min(query(beg, en, l, mid, node << 1), query(beg, en, mid + 1, r, (node << 1) | 1));
}
int main()
{
	scanf("%d", &test);
	while(test--)
	{
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &a[i]);
		}
		sort(a + 1, a + n + 1);
		for (int i = 1; i <= m; i++)
		{
			arr[i].clear(); sum[i] = 0;
			scanf("%d", &num[i]);
			for (int j = 1; j <= num[i]; j++)
			{
				scanf("%d", &x);
				arr[i].push_back(x);
				sum[i] += x;
			}
		}
		suf[n + 1] = 0; 
		for (int i = 1; i <= n; i++) suf[i] = 1;
		for (int i = 1; i <= m; i++) 
		{
			avg = (sum[i] + num[i] - 1) / num[i];
			x = lower_bound(a + 1, a + n + 1, avg) - a;
			suf[x] --;
		}
		for (int i = n; i >= 1; i--) suf[i] += suf[i + 1];
		build(1, n + 1, 1);
		for (int i = 1; i <= m; i++)
		{
			for (int j = 0; j < num[i]; j++)
			{
				avg = (sum[i] + num[i] - 1) / num[i];
				x = lower_bound(a + 1, a + n + 1, avg) - a;
				navg = (sum[i] - arr[i][j] + num[i] - 2) / (num[i] - 1);
				y = lower_bound(a + 1, a + n + 1, navg) - a;
				if (x <= y)
				{
					if (query(x + 1, y, 1, n + 1, 1) >= 1 && query(y + 1, n + 1, 1, n + 1, 1) >= 0 && query(1, x, 1, n + 1, 1) >= 0)
					{
						putchar('1');
					}
					else putchar('0');
				}
				else
				{
					swap(x, y);
					if (query(x + 1, y, 1, n + 1, 1) >= -1 && query(y + 1, n + 1, 1, n + 1, 1) >= 0 && query(1, x, 1, n + 1, 1) >= 0)
					{
						putchar('1');
					}
					else putchar('0');
				}
			}
		}
		putchar('\n');
	}
	return 0;
}