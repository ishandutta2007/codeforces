#include <bits/stdc++.h>
using namespace std;
#define N 110000
#define ll long long 
ll f[N][2];
int beg[N],c[N],len[N], n;
char s[N];
int cmp(int x,int y,int a,int b)
{
	for(int i=1;i<=len[x]&&i<=len[y];i++)
	{
		char c1, c2;
		if(a == 1) c1 = s[beg[x]+i-1];
		else c1 = s[beg[x]+len[x]-i];
		if(b == 1) c2 = s[beg[y]+i-1];
		else c2 = s[beg[y]+len[y]-i];
		if(c1 != c2)return c1 < c2;
	}
	return len[x]<=len[y];
}

inline ll min(ll a, ll b)
{
	if(a < b) return a;
	return b;
}

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
		c[i] = read();
	int now = 1;
	for(int i=1;i<=n;i++)
	{
		beg[i] = now;
		scanf("%s", s + now);
		len[i] = strlen(s + now);
		now+=len[i];
	}
	memset(f,0x3f,sizeof(f));
	f[1][0] = 0;
	f[1][1] = c[1];
	for(int i=2;i<=n;i++)
	{
		if(cmp(i-1,i,1,1))f[i][0]=min(f[i][0],f[i-1][0]);
		if(cmp(i-1,i,-1,1))f[i][0]=min(f[i][0],f[i-1][1]);
		if(cmp(i-1,i,1,-1))f[i][1]=min(f[i][1],f[i-1][0]+c[i]);
		if(cmp(i-1,i,-1,-1))f[i][1]=min(f[i][1],f[i-1][1]+c[i]);
	}
	ll ans=min(f[n][0],f[n][1]);
	printf("%I64d\n",ans==f[0][0] ? -1:ans);
	return 0; 
}