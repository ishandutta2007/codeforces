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
int a[2020];
int T;
char c[404][404];
signed main()
{
	T=read();
	while(T--)
	{
		int n;
		n=read();
		up(i,1,n)cin>>(c[i]+1);
		int x1=-1,x2=-1,y1=-1,y2=-1;
		up(i,1,n)
		{
			up(j,1,n)
			{
				if(c[i][j]=='*')
				{
					if(x1==-1)
					{
						x1=i,y1=j;
					}
					else{
						x2=i,y2=j;
					}
				}
			}
		}
		if(x1==x2||y1==y2)
		{
			if(x1==x2)
			{
				if(x1!=n)c[n][y1]=c[n][y2]='*';
				else c[1][y1]=c[1][y2]='*';
			}
			else
			{
				if(y1!=n)c[x1][n]=c[x2][n]='*';
				else c[x1][1]=c[x2][1]='*';
			}
		}
		else c[x1][y2]=c[x2][y1]='*';
		up(i,1,n)
		{
			cout<<(c[i]+1)<<endl;
		}
	}
}