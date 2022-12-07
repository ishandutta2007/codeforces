#include <bits/stdc++.h>
using namespace std;
const int maxn = 105;
inline int ReadInt()
{
	int x = 0, f = 1;
	char ch = getchar();
	while(ch < '0' || ch > '9')
	{
		if(ch == '-') f = -1;
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9')
	{
		x = x * 10 + ch - '0';
		ch = getchar();
	}
	return x * f;
}
int n,T;
int a[maxn * maxn], dp[maxn * maxn], s[maxn * maxn], p, v, cnt[305];
int main()
{
	n = ReadInt();
	T = ReadInt();
	for(int i = 1; i <= n; i ++)
    {
        scanf("%d",&a[i]);
        cnt[a[i]] ++;
    }
    for(int i = n + 1; i <= min(T, n) * n; i ++) a[i] = a[i - n];
    int top = 0;
    int ans = 0, anspos;
    for(int i = 1; i <= min(T, n) * n; i ++)
    {
        int L = 1, R = top + 1;
        while(L < R)
        {
            int mid = L + (R - L) / 2;
            if(a[i] >= s[mid]) L = mid + 1;
            else R = mid;
        }
        dp[i] = L;
        ans = max(ans,dp[i]);
        if(L > top) s[++ top] = a[i];
        else s[L] = min(s[L],a[i]);
    }
    int Max = 0;
    for(int i = 1; i <= 300; i ++)Max = max(Max,cnt[i]);
    ans += Max * max(T - n, 0);
    printf("%d", ans);
	return 0;
}