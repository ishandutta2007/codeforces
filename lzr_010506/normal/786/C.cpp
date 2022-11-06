#include <bits/stdc++.h>
#define N 100010
using namespace std;
int ans[N], vis[N], n, c[N];

inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}

int get_cnt(int k)
{
    int res = 0, cnt = 0;
    memset(vis, -1, sizeof vis);
    for(int i = 1; i <= n; i ++)
    {
        if(vis[c[i]] == res) continue;
        vis[c[i]] = res;
        cnt ++;
        if(cnt > k)
        {
            res ++;
            cnt = 1;
            vis[c[i]] = res;
        }
    }
    return res + 1;
}

void Solve(int l, int r)
{
	if(l > r) return;
	int cl = get_cnt(l);
	int cr = get_cnt(r);
	if(cl == cr)
	{
		for(int i = l; i <= r; i ++)
			ans[i] = cl;
		return;
	}
	ans[l] = cl;
	ans[r] = cr;
	int mid = (l + r) >> 1;
	Solve(l + 1, mid);
	Solve(mid + 1, r - 1);
}
int main()
{
	n = read();
	for(int i = 1; i <= n; i ++)
		c[i] = read();
	Solve(1, n);
    for(int i = 1; i <= n; i ++)
        cout << ans[i] << " ";
	return 0;
}