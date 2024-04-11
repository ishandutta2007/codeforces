//This code is made by Yiran Empty.
//GrandMaster When??

//#pragma GCC optimize("Ofast", "unroll-loops")
//#pragma GCC target("sse", "sse2", "sse3", "ssse3", "sse4", "avx")
#include <bits/stdc++.h>
#define int long long
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
int a[300030];
signed main()
{
	int T=1;
	while(T--)
	{
		vector<int>v1,v2;
		n=read();
		up(i,1,n)
		{
			int x=read();
			a[i]=x;
			if(x&1)v1.emplace_back(x);
			else v2.emplace_back(x);
		}
		sort(v1.begin(),v1.end());sort(v2.begin(),v2.end());
		if(v1.size()==0||v2.size()==0)
		{
			up(i,1,n)cout<<a[i]<<" ";
			return 0;
		}
		int p1=0,p2=0;
		up(i,1,n)
		{
			if(p1==v1.size())
			{
				cout<<v2[p2++];
			}
			else if(p2==v2.size())
			{
				cout<<v1[p1++];
			}
			else if(v1[p1]<v2[p2])cout<<v1[p1++];
			else cout<<v2[p2++];
			cout<<" ";
		}
	}
}
/*
	   - clear the arrays if a problem has many tasks.
	   - pay attention to some special cases(n=0,1).
	   - Don't code before think completely.
	   - ...
*/
//663311 650047