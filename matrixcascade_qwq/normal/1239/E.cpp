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
int ans[1010][5];
int sum,mx;
int a[1010];
int dp[55][1200100],f[55][1200010],book[50505];
void solve(int x)
{
	int nw=n;
	up(i,1,n)
	{
		ans[i][2]=f[nw][x],--book[f[nw][x]],x=x-f[nw][x],--nw;
	}
	int tot=1;
	up(i,0,mx)
	{
		while(book[i]>0)
		{
			ans[++tot][1]=i;
			--book[i];	
		}
	}
	up(i,1,n+1)cout<<ans[i][1]<<" ";
	puts("");
	up(i,1,n+1)cout<<ans[i][2]<<" ";
}
signed main()
{
	n=read();
	up(i,1,n+n)
	{
		a[i]=read();
		sum+=a[i];
		mx=max(mx,a[i]);
	}
	sort(a+1,a+n+n+1);
	ans[1][1]=a[1];
	ans[n][2]=a[2];
	sum-=a[1];
	sum-=a[2];
	sum/=2;
	dp[0][0]=1;
	m=n+n;
	n--;
	up(i,3,m)book[a[i]]++;
	up(i,3,m)
	{
		down(j,min(i,n),1)
		{
			down(k,sum,a[i])
			{
				if(dp[j][k])continue; 
				if(dp[j-1][k-a[i]])f[j][k]=a[i],dp[j][k]=1;
			}
		}
	}
	//cout<<sum<<endl;
	down(i,sum,0)
	{
		if(dp[n][i])
		{
	//		cout<<i<<endl;
			solve(i);
			return 0;
		}
	}
}