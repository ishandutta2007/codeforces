#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define clr(f, n) memset(f, 0, sizeof(int) * (n))
#define cpy(f, g, n) memcpy(f, g, sizeof(int) * (n))
#define rev(f, n) reverse(f, f + n)
#define pir pair<int, int>
#define mkp make_pair
#define fst it->first
#define sec it->second
#define int long long
#define up(i,x,y) for(int i=x,i##end=y;i<=i##end;++i)
#define down(i,x,y) for(int i=x,i##end=y;i>=i##end;--i)
using namespace std;
int n, m, k;
int read()
{
    int s = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9')
    {
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        s = s * 10 + ch - '0';
        ch = getchar();
    }
    return s * f;
}
inline void print(int *f, int len)
{
    for (int i = 0; i < len; i++)
        printf("%lld ", f[i]);
    puts("");
}
int a[202020],b[101];
int pos[404040];
int p,y;
int ans=0;
void f(int x)
{
	int nw=200000;
	memset(pos,-1,sizeof(pos));
	pos[nw]=0;
	up(i,1,n)
	{
		if(a[i]==p)++nw;
		else if(a[i]==x)--nw;
		if(pos[nw]==-1)
		{
			pos[nw]=i;
		}
		else ans=max(ans,i-pos[nw]);
	}
}
signed main()
{
	n=read();
	up(i,1,n)a[i]=read(),b[a[i]]++;
	up(i,1,100)if(b[i]>b[p])p=i;
	up(i,1,100)
	{
		if(i!=p)f(i);
	}
	cout<<ans;
}