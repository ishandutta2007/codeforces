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
int f[101010],vis[101010];
signed main()
{
	int T=1;
	while(T--)
	{
		string s;
		cin>>s;n=s.size();
		s=' '+s;
		set<int>s1,s2;
		up(i,1,n)
		{
			if(s[i]=='R')f[i]=1,s1.insert(i);
			else s2.insert(i);
		}
		s1.insert(999999999);s2.insert(999999999);
		if(n%2==0)
		{
			if(*s1.begin()>*s2.begin())swap(s1,s2);
		}
		else
		{
			if(s1.size()<s2.size())swap(s1,s2);
		}
		int nw=2;
		int pos=*s1.begin();
		int ans=0;
		int w=0;
		vector<int>v;
		up(i,1,n)
		{
			if(nw==1)
			{
				if(pos>1010011)
				{
					pos=*s2.begin();
					++ans;
				}
				else if(*s1.begin()>*s2.begin()&&*s1.lower_bound(pos)>1010100)
				{
					ans+=(pos!=*s2.begin());
					pos=*s2.begin();
					
				}
				w=pos;
				
				s2.erase(w);v.emplace_back(w);
				pos=*s1.lower_bound(w);
			}
			else
			{
				if(pos>1010011)
				{
					++ans;
					pos=*s1.begin();
				}
				else if(*s1.begin()<*s2.begin()&&*s2.lower_bound(pos)>1010100)
				{ans+=(pos!=*s1.begin());
					pos=*s1.begin();
				
				}
				w=pos;
				s1.erase(w);v.emplace_back(w);
				pos=*s2.lower_bound(w);
			}
			nw^=1;nw^=2;
		}
		cout<<ans<<endl;
		for(auto to:v)printf("%d ",to);
	}
}
/*
	   - clear the arrays if a problem has many tasks.
	   - pay attention to some special cases(n=0,1).
	   - Don't code before think completely.
	   - ...
*/