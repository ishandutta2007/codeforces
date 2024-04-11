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
int p[303003];
int b[303030],tot;
int vs[303030];
int f[303030];
map<int,int>mp;
signed main()
{
	int T;
	rd(T);
	while(T--)
	{
		tot=0;
		rd(n);rd(m);
		mp.clear();
		up(i,1,n)
		{
			p[i]=read();
			++mp[(n+i-p[i])%n];
		}
		for(auto x:mp)
		{
			int v=x.second;
			if(v>=m)
			{
				int w=x.first;
			//	cout<<w<<endl;
				up(i,1,n)
				{
					int nw=(i-w+n)%n;
					if(nw==0)nw=n;
			//		cout<<nw<<" ";
					f[p[i]]=nw;
					vs[i]=0;
				}
			//	puts("");	
				int ans=n;
				up(i,1,n)
				{
					if(!vs[i])
					{
						int nw=i;
						while(!vs[nw])
						{
						//	cout<<nw<<"qwq"<<" "<<i<<endl;
							vs[nw]=1;
							nw=f[nw];
						}
						--ans;
					}
				}
			//	cout<<ans<<endl;
				if(ans<=m)b[++tot]=(w+n)%n;
			}
		}
		cout<<tot<<" ";
		sort(b+1,b+tot+1);
		up(i,1,tot)cout<<b[i]<<" ";
		puts("");
	}
}