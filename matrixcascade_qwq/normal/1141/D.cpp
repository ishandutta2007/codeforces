//MatrixCascade AFO.
//GrandMaster When??

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
vector<int>b[30],c[30];
#define pii pair<int,int>
#define mkp make_pair
signed main()
{
	int T=1;
	while(T--)
	{
		n=read();
		string s,t;cin>>s>>t;
		up(i,0,n-1)
		{
			if(s[i]=='?')b[0].emplace_back(i+1);
			else b[s[i]-'a'+1].emplace_back(i+1);
		}
		up(i,0,n-1)
		{
			if(t[i]=='?')c[0].emplace_back(i+1);
			else c[t[i]-'a'+1].emplace_back(i+1);
		}
		vector<pii>v;
		up(i,1,26)
		{
			while(b[i].size()&&c[i].size())
			{
				v.emplace_back(mkp(b[i].back(),c[i].back()));
				b[i].pop_back();c[i].pop_back();
			}
		}
		up(i,1,26)
		{
			while(b[0].size()&&c[i].size())
			{
				v.emplace_back(mkp(b[0].back(),c[i].back()));
				b[0].pop_back();c[i].pop_back();
			}
		}
		up(i,1,26)
		{
			while(b[i].size()&&c[0].size())
			{
				v.emplace_back(mkp(b[i].back(),c[0].back()));
				b[i].pop_back();c[0].pop_back();
			}
		}
		up(i,1,26)
		{
			while(b[0].size()&&c[0].size())
			{
				v.emplace_back(mkp(b[0].back(),c[0].back()));
				b[0].pop_back();c[0].pop_back();
			}
		}
		cout<<v.size()<<endl;
		for(auto to:v)
		{
			cout<<to.first<<" "<<to.second<<'\n';
		}
	}
}
/*
  When you are coding,remember to:
	   - clear the arrays if a problem has many tasks.
	   - pay attention to some special cases(n=0,1).
	   - Don't code before think completely.
	   - ...
*/