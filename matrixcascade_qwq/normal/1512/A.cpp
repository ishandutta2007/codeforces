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
signed main()
{
	T=read();
	while(T--)
	{
		int n;
		n=read();
		up(i,1,n)a[i]=read();
		int qwq=a[1];
		int pos=0,flag=1;;
		for(int i=2;i<=n;++i)
		{
			if(a[i]!=qwq)
			{
				if(pos)
				{
					flag=0;
					break;
				}
				pos=i;
			}
		} 
		if(!flag)puts("1");
		else cout<<pos<<endl;
	}
}