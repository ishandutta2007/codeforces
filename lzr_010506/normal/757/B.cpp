#include <bits/stdc++.h>
using namespace std;
int n;
int a[100010], s[100010], tot, cnt[100010];
inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}

int pd(int x)
{
    for(int i = 2; i <= sqrt(x); i ++)
        if(x % i == 0) return 0;
    return 1;
}

void fen(int x)
{
   for(int i = 1; i <= tot; i ++)
    {
        if(s[i] > sqrt(x)) break;
        if(x % s[i] == 0) cnt[s[i]] ++;
        while(x)
        {
            if(x % s[i] == 0) x /= s[i];
            else break;
        }
    }
    cnt[x] ++;
}

int main()
{
   // freopen("input.txt", "r", stdin);
    //freopen("a.in", "r", stdin);
    //freopen("a.ans", "w", stdout);
	int Mx = 0;
	n = read();
	for(int i = 2; i <= 100000; i ++)
		if(pd(i)) s[++ tot] = i;
	for(int i = 1; i <= n; i ++)
    {
        int x = read();
        fen(x);
    }

	int ans = 1;
	for(int i = 2; i <= 100000; i ++)
		ans = max(ans, cnt[i]);
	cout << ans;
	return 0;
}