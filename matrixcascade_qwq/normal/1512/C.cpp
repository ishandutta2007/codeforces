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
char c[505050];
signed main()
{
	T=read();
	while(T--)
	{
		int n;
		int a=read(),b=read();
		n=a+b;
		cin>>(c+1);
		int flag=1;
		int f1=a,f2=b;
		up(i,1,n/2)
		{
			if(c[i]=='1'&&c[n-i+1]=='0'||c[i]=='0'&&c[n-i+1]=='1')
			{
				flag=0;
				break;
			}
			if(c[i]==c[n-i+1])continue;
			if(c[i]=='?')c[i]=c[n-i+1];
			else c[n-i+1]=c[i];
		}
		up(i,1,n/2)
		{
			if(c[i]=='0')f1-=2;
			else if(c[i]=='1')f2-=2;
		}
		up(i,1,n/2)
		{
			if(c[i]=='?')
			{
				if(f1>f2)
				{
					f1-=2;
					c[i]=c[n-i+1]='0';
				}
				else 
				{
					f2-=2;
					c[i]=c[n-i+1]='1';
				}
			}
		}
		if(n%2==1)
		{
			if(c[n/2+1]=='0')f1--;
			else if(c[n/2+1]=='1')f2--;
			else
			{
				if(f1>f2)
				{
					f1-=1;
					c[n/2+1]='0';
				}
				else 
				{
					f2-=1;
					c[n/2+1]='1';
				}
			}
		}
		if(!flag||f1!=0||f2!=0)
		{
			puts("-1");
			continue;
		}
		cout<<(c+1)<<endl;
	}
}