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
bitset<4100>f[101001];
int a[13][101010],b[101010][13];
int tot=0;
bool cmp(int x,int y)
{
	return a[x][tot]==a[y][tot]?x>y:a[x][tot]>a[y][tot];
}
signed main()
{
	int q;
	n=read(),k=read(),q=read();
	up(i,1,k)
	{
		up(j,1,n)
		{
			a[i][j]=read();
			b[j][i]=i;
		}
	}
	for(int i=1;i<=n;i++)tot=i,sort(b[i]+1,b[i]+k+1,cmp);
	up(i,1,k)
	{
		up(j,0,(1<<k))
		{
			if(j&(1<<(i-1)))f[i][j]=1;
		}
	}
	tot=k;
	up(cas,1,q)
	{
		int opt,x,y;
		opt=read(),x=read(),y=read();
		if(opt==1)f[++tot]=f[x]|f[y];
		else if(opt==2)f[++tot]=f[x]&f[y];
		else
		{
			int cur=0;
			up(i,1,k)
			{
				cur|=(1<<(b[y][i]-1));
				if(f[x][cur])
				{
					cout<<a[b[y][i]][y]<<endl;
					break;
				}
			}
		}
	}
}