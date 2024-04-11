#include <bits/stdc++.h>
#define ll long long
using namespace std;
int n, k, a[1000010], l, r = 10000001, ans;
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
   	k = read();
    for(int i = 1; i <= n; i ++) a[i] = read();

    while (l <= r)
    {
        int mid = (l + r) >> 1;
        ll c = 0;
        if (!mid) break;
        for(int i = 1; i <= n; i ++)
        {
            int p = 1, j = mid;
            while(j <= a[i]) j *= 2, p *= 2;
            c += max(p / 2, p - j + a[i]);
        }
        if (c >= k) l = mid + 1, ans = mid;
        else r = mid - 1;
    }
    if (!ans) cout << -1;
    else cout << ans;
    return 0;
}