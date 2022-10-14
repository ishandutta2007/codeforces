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
const int maxn=2e5+10;
int T;
int a[maxn],q[maxn],ans[maxn];
const int inf=1e15+10;
struct node
{
	int x,y,id;
}s[maxn];
int sum;
bool cmp(node a,node b)
{
	return a.x<b.x;
}
signed main()
{
	T=read();
	while(T--)
	{
		n=read();m=read();
		int mx=-1010101010;
		up(i,1,n)a[i]=read(),a[i]+=a[i-1],mx=max(mx,a[i]);
		up(i,1,m)q[i]=read();
		int w=a[n];
		if(w>0)
		{
			up(i,1,m)
			{
				if(q[i]<mx)
				{
					s[i]=(node){q[i],0,i};
				}
				else
				{
					s[i]=(node){q[i]-((q[i]-mx)/w+((q[i]-mx) %w!=0))*w,((q[i]-mx)/w+((q[i]-mx)%w!=0))*n,i};
				}
			}
		}
		else
		{
			up(i,1,m)
			{
				if(q[i]>mx)
				{
					s[i]=(node){inf,0,i};
				}
				else s[i]=(node){q[i],0,i};
			}
		}
		sort(s+1,s+m+1,cmp);
		int nw=1;
		up(i,1,n)
		{
			while(s[nw].x<=a[i]&&nw<=m)
			{
				s[nw++].y+=i;
			}
		}
		up(i,1,m)ans[s[i].id]=s[i].y-1;
		up(i,1,m)cout<<ans[i]<<" ";
		cout<<endl;
	}
}