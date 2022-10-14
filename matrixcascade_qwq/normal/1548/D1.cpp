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
#define rd(x) x=read()
#define op(x) printf("%lld",x)
#define ops(x) printf("%lld ",x)
#define ver(x) for(int i=head[x];i;i=nxt[i])
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
int x[6666],y[6666],z[6666];
int f(int x1,int y1,int x2,int y2)
{
	int g=__gcd(abs(x1-x2),abs(y1-y2));
	return g;
}
int b[1010];
signed main()
{
	n=read();
	up(i,1,n)
	{
		x[i]=read()/2,y[i]=read()/2;
		z[i]=x[i]%2+y[i]%2;
		z[i]+=x[i]%2;++b[z[i]];
	}
	int ans=0;
	ans+=b[0]*(b[0]-1)*(b[0]-2)/6;
	ans+=b[1]*(b[1]-1)*(b[1]-2)/6;
	ans+=b[2]*(b[2]-1)*(b[2]-2)/6;
	ans+=b[3]*(b[3]-1)*(b[3]-2)/6;
	
	ans+=b[0]*(b[0]-1)*(b[1])/2;
	ans+=b[0]*(b[0]-1)*(b[2])/2;
	ans+=b[0]*(b[0]-1)*(b[3])/2;
	
	ans+=b[1]*(b[1]-1)*(b[0])/2;
	ans+=b[2]*(b[2]-1)*(b[0])/2;
	ans+=b[3]*(b[3]-1)*(b[0])/2;
	
	ans+=b[1]*(b[1]-1)*(b[3])/2;
	ans+=b[1]*(b[1]-1)*(b[2])/2;
	
	ans+=b[2]*(b[2]-1)*(b[1])/2;
	ans+=b[3]*(b[3]-1)*(b[1])/2;
	
	ans+=b[2]*(b[2]-1)*(b[3])/2;
	ans+=b[3]*(b[3]-1)*(b[2])/2;
	
	cout<<ans<<endl;
	
	
}