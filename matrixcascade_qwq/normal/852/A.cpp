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
string s;
signed main()
{
	int T=1;
	while(T--)
	{
		string f[4],nw;
		cin>>n>>s;
		srand(12421);
		int f1=0,f2=0;
		while("SyadouHayami")
		{
			nw=s;;
			up(tim,1,3)
			{
				n=nw.size();
				f[tim]="";
				up(j,0,n-1)
				{
					f1*=10;
					f1+=nw[j]-'0';
					f[tim]+=nw[j];
					if(j==n-1||rand()%10!=0)
					{
						f2+=f1;f1=0;
						if(j!=n-1)f[tim]+='+';
					}
				}
				nw=to_string(f2);f2=0;
			}//cout<<s<<endl;
			if((int)nw.size()==1)
			{
				up(i,1,3)cout<<f[i]<<'\n';
				return 0;
			}
		}
		
	}
}
/*
	   - clear the arrays if a problem has many tasks.
	   - pay attention to some special cases(n=0,1).
	   - Don't code before think completely.
	   - ...
*/