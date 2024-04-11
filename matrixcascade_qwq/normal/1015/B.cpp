/*
FUCK YOU XJOI.
FUCK YOU XJOI.
FUCK YOU XJOI.
FUCK YOU XJOI.
And in that light,I find deliverance.
*/

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
int f[101010],a[101010];
signed main()
{
	int T=1;
	while(T--)
	{
		n=read();
		string s1,s2;
		cin>>s1>>s2;
		up(i,0,n-1)
		{
			f[s1[i]-'a']++;f[s2[i]-'a']--;
		}
		up(i,0,25)
		{
			if(f[i])
			{
				puts("-1");return 0;
			}
		}
		up(i,0,n-1)
		{
			up(j,0,n-1)
			{
				if(s2[i]==s1[j]&&!a[j])
				{
					a[j]=i;break;
				}
			}
		}
		vector<int>v;
		up(i,0,n-1)
		{
			up(j,0,n-2)
			{
				if(a[j]>a[j+1])
				{
					swap(a[j],a[j+1]);
					v.push_back(j+1);
				}
			}
		}
		cout<<v.size()<<'\n';
		for(auto to:v)cout<<to<<" ";
	}
}
/*
  When you are coding,remember to:
	   - clear the arrays if a problem has many tasks.
	   - pay attention to some special cases(n=0,1).
	   - Don't code before think completely.
	   - ...
*/