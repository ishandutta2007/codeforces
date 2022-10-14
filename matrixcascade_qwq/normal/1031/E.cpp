//This code is made by Yiran Empty.
//GrandMaster When??

//#pragma GCC optimize("Ofast", "unroll-loops")
//#pragma GCC target("sse", "sse2", "sse3", "ssse3", "sse4", "avx")
#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
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
#define R return;
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
int q[101000];
int g[101010];
struct node
{
	int a,b,c;
};
node mk(int a,int b,int c)
{
	return (node){a,b,c};
}
vector<node>v;
void f(int a,int b,int c)
{
	q[a]^=1;q[b]^=1;q[c]^=1;v.emplace_back(mk(a,b,c));R
}
int flag=0;
void dfs(int l,int r)
{
	/*
	
	*/
	if(r-l<8)
	{
		
		while(r-l<7&&r<n)r++;while(r-l<7&&l>1)l--;
        
//		cout<<l<<" "<<r<<endl;
//		up(i,l,r)cout<<q[i]<<" ";puts("");
		vector<node>w;
		up(i,l,r-2)
		{
			for(int j=i+2;j<=r;j+=2)
			{
				w.emplace_back(mk(i,(i+j)/2,j));
			}
		}
		int siz=w.size();
		m=(1<<siz)-1;
		up(i,0,m)
		{
			up(j,l,r)g[j]=q[j];
			up(j,0,siz-1)
			{
				if((i>>j)&1)
				{
					g[w[j].a]^=1;g[w[j].b]^=1;g[w[j].c]^=1;
				}
			}
			int sum=0;
			up(j,l,r)sum+=g[j];
			if(sum!=0)continue;
			up(j,0,siz-1)
			{
				if((i>>j)&1)
				{
					v.emplace_back(w[j]);
				}
			}
			puts("YES");
			cout<<v.size()<<'\n';
			for(auto nw:v)
			{
				printf("%d %d %d\n",nw.a,nw.b,nw.c);
			}
			exit(0);
		}
		return;
	}
	if(q[l]==0)
	{
		dfs(l+1,r);R
	}
	if(q[r]==0)
	{
		dfs(l,r-1);R
	}
	if(q[l]==1&&q[l+1]==1&&q[l+2]==1)
	{
		f(l,l+1,l+2);dfs(l+3,r);R
	}
	if(q[l]==1&&q[l+1]==0&&q[l+2]==1)
	{
		f(l,l+2,l+4);dfs(l+3,r);R
	}
	if(q[l]==1&&q[l+1]==0&&q[l+2]==0)
	{
		f(l,l+3,l+6);dfs(l+3,r);R
	}
	if(q[r]==1&&q[r-1]==1&&q[r-2]==1)
	{
		f(r-2,r-1,r);dfs(l,r-3);R
	}if(q[r-2]==1&&q[r-1]==0&&q[r]==1)
	{
		f(r-4,r-2,r);dfs(l,r-3);R
	}
	if(q[r-2]==0&&q[r-1]==0&&q[r]==1)
	{
		f(r-6,r-3,r);dfs(l,r-3);R
	}
	
	
	//worse case
	/*
	1 3:2
	1 5:3
	1 4
	*/
	if((r-l)%2==0)
	{
		f(l,(l+r)/2,r);f(l+1,(l+r)/2,r-1);dfs(l+3,r-3);R
	}
	f(l,(l+r-1)/2,r-1);f(l+1,(l+1+r)/2,r);dfs(l+3,r-3);R
	
}
signed main()
{
	int T=1;
	while(T--)
	{
		n=read();
		up(i,1,n)q[i]=read();
		dfs(1,n);
		puts("NO");
	}
}
/*
	   - clear the arrays if a problem has many tasks.
	   - pay attention to some special cases(n=0,1).
	   - Don't code before think completely.
	   - ...
*/