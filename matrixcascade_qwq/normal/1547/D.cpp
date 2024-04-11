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
int a[300303];
int ans[303030];
signed main()
{
	int T=read();
	while(T--)
	{
		n=read();
		up(i,1,n)a[i]=read();
		int nw=0;
		up(i,1,n)
		{
			ans[i]=0;
			up(j,0,31)
			{
				if(!(a[i]&(1ll<<j))&&(nw&(1ll<<j)))ans[i]|=(1ll<<j);
			}
			nw=a[i]^ans[i];
		}
		up(i,1,n)
		{
			cout<<ans[i]<<" ";
		}
		puts("");
	}
}