#include <bits/stdc++.h>
using namespace std;
#define ll long long
int n, p[1000010];
ll ans1[1000010], ans2[1000010];
inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}
int main()
{
	n = read();
	for(int i = 1; i <= n; i ++)
		p[i] = read();
	for(int i = 1; i <= n; i ++)
    {
        ans1[1] += abs(i - p[i]);
        ans2[i + 1] --;
        ans2[i + 2] --;
		if(p[i] <= i)
		{
			ans2[2] --;
			ans2[i - p[i] + 2] += 2;
			ans1[i + 1] += n - p[i] - p[i] + 1;
		}
		else
		{
			ans2[2] ++;
			ans1[i + 1] += n - p[i] - p[i] + 1;
			ans2[n + i + 2 - p[i]] += 2;
		}
    }

	for(int i = 1; i <= n; i ++)
		ans2[i] += ans2[i - 1];
	for(int i = 1; i <= n; i ++)
		ans1[i] += ans1[i - 1] + ans2[i];
	int ans = 1;
	for(int i = 2; i <= n; i ++)
		if(ans1[i] < ans1[ans]) ans = i;
	cout << ans1[ans] << ' ' << (n - ans + 1) % n;
	return 0;
}