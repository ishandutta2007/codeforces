#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define int long long
#define YES puts("YES")
#define NO puts("NO")
#define Yes puts("Yes")
#define No puts("No")
#define edl puts("")
#define mc cerr<<"qwq\n"
#define rd(x) x=read()
#define op(x) printf("%lld",x)
#define ops(x) printf("%lld ",x)
#define ver(x) for(int i=head[x];i;i=nxt[i])
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
char c[202020];
int f[202020][6];
int ch[4];
signed main()
{
	n=read(),m=read();
	cin>>(c+1);
	ch[1]='a',ch[2]='b',ch[3]='c';
	up(i,1,n)
	{
		f[i][0]=f[i-1][0];
	if(c[i]!=ch[(i-1)%3+1])
		{
			f[i][0]++;
		}
	}
	ch[1]='a',ch[2]='c',ch[3]='b';
	up(i,1,n)
	{
		f[i][1]=f[i-1][1];
	if(c[i]!=ch[(i-1)%3+1])
		{
			f[i][1]++;
		}
	}
	ch[1]='b',ch[2]='a',ch[3]='c';
	up(i,1,n)
	{
		f[i][2]=f[i-1][2];
	if(c[i]!=ch[(i-1)%3+1])
		{
			f[i][2]++;
		}
	}
	ch[1]='b',ch[2]='c',ch[3]='a';
	up(i,1,n)
	{
		f[i][3]=f[i-1][3];
	if(c[i]!=ch[(i-1)%3+1])
		{
			f[i][3]++;
		}
	}
	ch[1]='c',ch[2]='a',ch[3]='b';
	up(i,1,n)
	{
		f[i][4]=f[i-1][4];
	if(c[i]!=ch[(i-1)%3+1])
		{
			f[i][4]++;
		}
	}
	ch[1]='c',ch[2]='b',ch[3]='a';
	up(i,1,n)
	{
		f[i][5]=f[i-1][5];
		if(c[i]!=ch[(i-1)%3+1])
		{
			f[i][5]++;
		}
	}
	while(m--)
	{
		int l,r;
		l=read(),r=read();
		int ans=101010100;
		up(i,0,5)ans=min(ans,f[r][i]-f[l-1][i]);
		cout<<ans<<endl;
	}
}