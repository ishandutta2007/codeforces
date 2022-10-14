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
int T;
const int maxn=2e5+10;
int a[maxn];
struct node
{
	int v,id;	
}s[maxn];
bool cmp(node a,node b)
{
	return a.v<b.v;
}
signed main()
{
	T=read();
	while(T--)
	{
		n=read();
		int sum=0;
		up(i,1,n)s[i].v=read(),s[i].id=i,sum+=s[i].v,a[i]=0;
		sort(s+1,s+n+1,cmp);
		a[s[n].id]=1;
		sum-=s[n].v;
		int nw=1;
		down(i,n-1,1)
		{
			if(sum>=s[i+1].v)
			{
				a[s[i].id]=1;
				sum-=s[i].v;
				++nw;
			}
			else break;
		}
		cout<<nw<<endl;
		up(i,1,n)
		{
			if(a[i])cout<<i<<" ";
		}
		cout<<endl;
	}
}