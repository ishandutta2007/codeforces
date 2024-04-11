//MatrixCascade AFO.

//#pragma GCC optimize("Ofast", "unroll-loops")
//#pragma GCC target("sse", "sse2", "sse3", "ssse3", "sse4", "avx")
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
#define error goto gg
#define def gg:
#define rd(x) x=read()
#define opl(x) printf("%lld",x)
#define opls(x) printf("%lld ",x)
#define opd(x) printf("%d",x)
#define opds(x) printf("%d ",x)
#define ver(x) for(int i=head[x];i;i=nxt[i])
#define up(i,x,y) for(int i=x,i##end=y;i<=i##end;++i) 
#define pu(i,x,y) for(int i=x,i##end=y;i>=i##end;--i)
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
int a[101001];
const int maxn=(1<<12)+10;
int s1[maxn],t1,s2[maxn],t2,vis[maxn],w[maxn],vs[maxn];
signed main()
{
	srand(892133);
	int T=1;
	while(T--)
	{
		k=read();n=(1<<k);
		int f=0;
		up(i,0,n-1)a[i]=read(),f^=a[i];
		if(f)
		{
			puts("Fou");return 0;
		}
		puts("Shi");
		memset(w,-1,sizeof(w));
		while("SyadouHayami")
		{
			memset(vis,-1,sizeof(vis));memset(vs,-1,sizeof(vs));
			t1=0;t2=0;
			up(i,0,n-1)
			{
				if(w[i]!=-1)vis[w[i]]=1,vs[w[i]^a[i]]=i;
			}
			up(i,0,n-1)
			{
				if(vis[i]==-1)s1[t1++]=i;
				if(w[i]==-1)s2[t2++]=i;
			}
	//		cout<<t1<<endl;
			if(!t1)
			{
				error;
			}
			int pos=s2[rand()%t2];
			up(i,0,t1-1)
			{
				int nw=a[pos]^s1[i];
				if(vs[nw]==-1)
				{
					w[pos]=s1[i];
					break;
				}
			}
			if(w[pos]==-1)
			{
				int p2=s1[rand()%t1];
				w[pos]=p2;
				int ww=a[pos]^p2;
				w[vs[ww]]=-1;vs[ww]=pos;
			}
		}
		def;
		up(i,0,n-1)cout<<w[i]<<" ";puts("");
		up(i,0,n-1)cout<<(w[i]^a[i])<<" ";
	}
}
/*
  When you are coding,remember to:
	   - clear the arrays if a problem has many tasks.
	   - pay attention to some special cases(n=0,1).
	   - Don't code before think completely.
	   - ...
*/