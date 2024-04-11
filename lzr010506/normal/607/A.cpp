#include<bits/stdc++.h>
#define maxn 1000010
using namespace std;
typedef pair<int,int> pii;
#define fi first
#define se second
#define mp make_pair
int n;
pii a[maxn];
int b[maxn], dp[maxn];

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

int main()
{
    n = ReadInt();
    for (int i = 0; i < n; i ++)
    {
        a[i].fi = ReadInt();
		a[i].se = ReadInt();
    }
    sort(a, a + n);
    for (int i = 0; i < n; i ++)
        b[i] = a[i].fi;
    int ans = 1;
    dp[0] = 1;
    for (int i = 1; i < n; i ++)
	{
        int tmp = lower_bound(b, b + i + 1, a[i].fi - a[i].se) - b;
        if (tmp == 0) dp[i] = 1;
        dp[i] = dp[tmp - 1] + 1;
        ans = max(ans,dp[i]);   
    }
    printf("%d",n - ans);

    return 0;
}