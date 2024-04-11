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
int a[202020];
int in[202020];
int in2[202020]; 
signed main()
{
	int T;
	T=1;
	while(T--)
	{
		n=read(),m=read();
		int ans=n;
		up(i,1,m)
		{
			int u=read(),v=read();
			if(u>v)swap(u,v);
			 ++in[u];
			 if(in[u]==1)--ans;
		}
		int q=read();
		while(q--)
		{
			int opt=read();
			int u,v;
			if(opt==1)
			{
				u=read(),v=read();
				if(u>v)swap(u,v);
			 ++in[u];
			 if(in[u]==1)--ans;
			}
			else if(opt==2)
			{
				u=read(),v=read();
				if(u>v)swap(u,v);
			 --in[u];
			 if(in[u]==0)++ans;
			}
			else
			{
				cout<<ans<<endl;
			}
		}
	}
}