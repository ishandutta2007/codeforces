//Author:MatrixCascade

#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define clr(f, n) memset(f, 0, sizeof(int) * (n))
#define cpy(f, g, n) memcpy(f, g, sizeof(int) * (n))
#define rev(f, n) reverse(f, f + n)
#define pir pair<int, int>
#define mkp make_pair
#define fst it->first
#define sec it->second
#define int long long
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
inline void print(int *f, int len)
{
    for (int i = 0; i < len; i++)
        printf("%lld ", f[i]);
    puts("");
}
int a[202020],vis[202020];
int b[202020],f[202020];
signed main()
{
	int T;
	T=read();
	while(T--)
	{
		n=read();
		int l,r,s;
		l=read(),r=read(),s=read();
		int len=r-l+1;
		int sum=0;
		up(i,1,len)b[i]=i,sum+=b[i];
		if(sum>s)
		{
			puts("-1");
			continue;
		}
		int mx=n-len;
		down(i,len,1)
		{
			if(sum+mx<s)
			{
				sum+=mx;
				b[i]+=mx;
			}
			else
			{	b[i]+=s-sum;
				sum+=s-sum;
			
				break;
			}
		}
		if(sum<s)
		{
			puts("-1");
			continue;
		}
		up(i,1,n)vis[i]=0;
		up(i,1,len)vis[b[i]]=1;int tot=0;
		up(i,1,n)if(!vis[i])f[++tot]=i;
		int q1=0,q2=0;
		up(i,1,n)
		{
			if(i>=l&&i<=r)cout<<b[++q1];
			else cout<<f[++q2];
			cout<<" ";
		}
		puts("");
	}
}