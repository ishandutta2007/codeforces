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

int f[40][40],v[40][40];
int q(int x,int y)
{
	return v[x][y]?-f[x][y]:f[x][y];
}
int qry1(int x,int y,int w)
{
	v[x][y]=w;
	v[x+m][y]=v[m][y]^w;
	v[x][y+m]=v[x][m]^w;
	v[x+m][y+m]=v[m][y+m]^v[x][y+m];
	return q(x,y)+q(x+m,y)+q(x,y+m)+q(x+m,y+m);
}
int qry2(int y,int w)
{
	int s=0;
	v[m][y]=w;
	v[m][y+m]=v[m][m]^w;
	s+=q(m,y)+q(m,y+m);
	up(i,1,m-1)s+=max(qry1(i,y,0),qry1(i,y,1));
	return s;
}
int solve()
{
	int s=0;
	up(i,1,n)s+=q(i,m);
	up(i,1,m-1)s+=max(qry2(i,0),qry2(i,1));
	return s;
}
signed main()
{
	n=read(),m=(n+1)/2;
	up(i,1,n)
	{
		up(j,1,n)
		{
			f[i][j]=read();
		}
	}
	int ans=-1;
	for(int msk=0;msk<(1<<m);++msk)
	{
		up(i,1,m)
		{
			v[i][m]=msk>>(i-1)&1;
		}
		up(i,1,m-1)
		{
			v[i+m][m]=v[m][m]^v[i][m];
		}
		ans=max(ans,solve());
		
	}
	cout<<ans;
}