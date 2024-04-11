#include <bits/stdc++.h>
using namespace std;
int n, w;
int a[110], vis[110];
int ans[110];
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
	w = read();
	for(int i = 1; i <= n; i ++)
		a[i] = read();
	for(int i = 1; i <= n; i ++)
		w -= ceil(a[i] / 2.0), ans[i] = ceil(a[i] / 2.0);
	if(w < 0) {cout << -1; return 0;}
	for(int i = 1; i <= n; i ++)
	{
	    int Mx = 0, id;
	    for(int j = 1; j <= n; j ++)
            if(!vis[j] && a[j] > Mx) Mx = a[j], id = j;
        vis[id] = 1;
        int res = a[id] / 2;
		if(res < w) ans[id] += res, w -= res;
		else {ans[id] += w; break;}
	}
	for(int i = 1; i <= n; i ++)
		cout << ans[i] << " ";
	return 0;
}