#include<bits/stdc++.h>
using namespace std;
inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}
pair<int, int> a[3010];
int b[3010], c[3010];
int f[3010][110];
int main()
{
	int n;
	scanf("%d",&n);
	int i, j, k;
	for(i=1; i<=n; i++) a[i] = make_pair(read(), i);
	sort(a+1, a+n+1);
	for(i=1; i<=n; i++) b[i] = a[i].first - a[i-1].first;
	for(i=1; i<=n; i++) f[i][0] = i;
	for(j=1; j<20; j++)
	{
		for(i=1; i<=n; i++)
		{
			if(i + (1 << j) - 1 > n) break;
			//cout << i + (1 << j) << endl;
			if(b[f[i][j-1]] > b[f[i + (1 << (j - 1))][j-1]]) f[i][j] = f[i][j-1];
			else f[i][j] = f[i + (1 << (j - 1))][j-1];
		}
	}

	int mx1 = -1;
	int mx2 = -1;
	int mx3 = -1;
	int ans1 = -1, ans2 = -1, ans3 = -1;
	for(i=n; i > 2; i --)
	{
		for(j=i-1; j > 1; j--)
		{
			//cout << i << j << endl;
			int cnt1 = n - i + 1;
			int cnt2 = i - j;
			if(cnt1 > 2 * cnt2 || cnt2 > 2 * cnt1) continue;
			int mx = min(2 * cnt1, 2 * cnt2);
			int mn = max((cnt1 + 1) / 2, (cnt2 + 1) / 2);
			if(j - mn < 1) continue;
			int l = max(j - mx, 1);
			int r = j - mn;
			k = log(r - l + 1) / log(2);
			int a3;
			if(b[f[l][k]] > b[f[r - (1 << k) + 1][k]]) a3 = f[l][k];
			else a3 = f[r - (1 << k) + 1][k];
			if(b[i] > mx1)
			{
				mx1 = b[i];
				mx2 = b[j];
				mx3 = b[a3];
				ans1 = i;
				ans2 = j;
				ans3 = a3;
			}
			else if(b[i] == mx1 && b[j] > mx2)
			{
				mx1 = b[i];
				mx2 = b[j];
				mx3 = b[a3];
				ans1 = i;
				ans2 = j;
				ans3 = a3;
			}
			else if(b[i] == mx1 && b[j] == mx2)
			{
				if(b[a3] > mx3)
				{
					ans1 = i;
					ans2 = j;
					ans3 = a3;
					ans1 = i;
					ans2 = j;
					mx3 = b[a3];
				}
			}
		}
	}
	//cout << ans1 << " " << ans2 << " " << ans3 << endl;
	for(int i = n; i >= ans1; i--) c[a[i].second] = 1;
	for(int i = ans1 - 1; i >= ans2; i--) c[a[i].second] = 2;
	for(int i = ans2 - 1; i >= ans3; i--) c[a[i].second] = 3;
	for(int i = ans3 - 1; i >= 1; i--) c[a[i].second] = -1;
	for(int i = 1; i <= n; i++) printf("%d ", c[i]);
	return 0;
}