//Author:MatrixCascade

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
int a[202020],sum[202020];
signed main()
{
	int T;
	T=read();
	while(T--)
	{
		n=read();
		up(i,1,n+2)a[i]=read();
		sort(a+1,a+n+3);
		sum[0]=0;
		up(i,1,n+2)sum[i]=sum[i-1]+a[i];
		int pos1=-1,pos2=-1;
		up(i,1,n+1)
		{
			if(sum[n+2]-a[i]-a[n+2]==a[n+2])
			{
				pos1=i;
				pos2=n+2;
				break;
			}
		}
		if(sum[n+1]-a[n+1]==a[n+1])
		{
			pos1=n+1;
			pos2=n+2;
		}
		if(pos1==-1)
		{
			puts("-1");
		}
		else
		{
			up(i,1,n+2)
			{
				if(i==pos1||i==pos2)continue;
				cout<<a[i]<<" ";
			}
			cout<<endl;
		}
	}
}