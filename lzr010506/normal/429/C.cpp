#include <bits/stdc++.h>
using namespace std;
int n, h, a[26];
bool vis[26], ans;
 
inline int read()
{
    int x = 0, f = 1; char ch = getchar();
    while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
    while (ch >= '0' && ch <= '9') { x = x * 10 + ch-'0'; ch = getchar(); }
    return x * f;
}
 
void dfs(int l)
{
    if(a[l] == 1)
    {
        int c = 0;
        for(int j = l + 1; j < n; j ++)
            c += a[j] - 1;
        if(c == h) ans = 1;
        return;
    }
    for (int i = l + 1; i < n; i ++) 
        if (a[i] >= a[l] + 1) 
        {
            if (a[i] == a[l] + 1 && !vis[i]) continue;
            a[i] -= a[l];
            bool ow = vis[i];
            vis[i] = 1;
            dfs(l - 1);
            if (ans) return;
            vis[i] = ow;
            a[i] += a[l];
        }
}
 
int main()
{
    n = read();
    for(int i = 0; i < n; i ++)
        a[i] = read();
    if(n == 1 && a[0] == 1) printf("YES");
    else
    {
        sort(a, a + n);
        for(h = 0; h < n; h ++)
            if(a[h] != 1) break;
        if(h == n || h * 2 - 1 < 1 || a[h] == 2) printf("NO");
        else
        {
            dfs(n - 2);
            if(ans) printf("YES");
            else printf("NO");
        }
    }
    return 0;
}