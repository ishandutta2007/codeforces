#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
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
int a[101010],b[101010];
int f[101010],tot;
signed main()
{
	int T=read();
	while(T--)
	{
		k=read(),n=read(),m=read();
		tot=0;
		up(i,1,n)a[i]=read();up(i,1,m)b[i]=read();
		int q1=1,q2=1,fl=1;
		up(i,1,n+m)
		{
			if(q1==n+1)
			{
				if(b[q2]==0)
				{
					++k;
				}
				else
				{
					if(b[q2]>k)
					{
						fl=0;
						break;
					}
				}
				f[++tot]=b[q2];
				++q2;
			}
			else if(q2==m+1)
			{
				if(a[q1]==0)
				{
					++k;
				}
				else
				{
					if(a[q1]>k)
					{
						fl=0;
						break;
					}
				}
				f[++tot]=a[q1];
				++q1;
			}
			else
			{
				if(a[q1]<b[q2])
				{
					if(a[q1]==0)
					{
						++k;
					}
					else
					{
						if(a[q1]>k)
						{
							fl=0;
							break;
						}
					}
					f[++tot]=a[q1];
					++q1;
				}
				else
				{
					f[++tot]=b[q2];
					if(b[q2]==0)++k;
					else
					{
						if(b[q2]>k)
						{
							fl=0;
							break;
						}
					}
					++q2;
				}
			}
		}
		if(!fl)puts("-1");
		else
		{
			up(i,1,tot)
			{
				printf("%lld ",f[i]);
				
			}puts("");
		}
	}
}