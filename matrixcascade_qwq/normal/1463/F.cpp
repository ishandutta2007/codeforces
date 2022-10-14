//MatrixCascade

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
int x,y;
int f[2][1<<22];
int p[101];
signed main()
{
	n=read(),x=read(),y=read(),m=x+y,k=1<<(max(x,y));
	int cur=0;
	int lst=cur^1;
	up(i,0,m-1)f[cur][i]=-1,p[i]=n/m+(i<n%m?1:0);
	f[0][0]=0;
	up(kk,0,m-1)
	{
		lst=cur;
		cur^=1;
		memset(f[cur],-1,sizeof(f[cur]));
		up(i,0,k-1)
		{
			if(~f[lst][i])
			{
				f[cur][(i<<1)&(k-1)]=max(f[cur][(i<<1)&(k-1)],f[lst][i]);
				if(~(i>>(x-1)|i>>(y-1))&1)
				{
					f[cur][(i<<1)&(k-1)|1]=max(f[cur][(i<<1)&(k-1)|1],f[lst][i]+p[kk]);
				}
			}
		}
	}
	int ans=-1;
	up(i,0,k-1)ans=max(ans,f[cur][i]);
	cout<<ans;
}