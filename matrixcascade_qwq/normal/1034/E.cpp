#include <bits/stdc++.h>
#define ll long long
#define up(i,x,y) for(int i=x,i##end=y;i<=i##end;++i)
using namespace std;
int n,m,k;
const int maxn=(1<<21)+10;
ll f[maxn],g[maxn],h[maxn];
void fwt(ll f[],int fl)
{
	for(int len=1;len<(1<<n);len<<=1)
	{
		for(int p=0;p<(1<<n);p+=(len<<1))
		{
			up(i,0,len-1)
			{
				f[i|p|len]+=f[i|p]*fl;
			}
		}
	}
}
char c1[maxn],c2[maxn];
short p[maxn];
signed main()
{
	cin>>n;
	scanf("%s%s",c1,c2);
	m=1<<n;
	up(i,1,m-1)p[i]=p[i>>1]+(i&1);
	up(i,0,m-1)f[i]=(c1[i]&15ll),f[i]<<=(p[i]<<1);
	up(i,0,m-1)g[i]=(c2[i]&15ll),g[i]<<=(p[i]<<1);//	if(n==21)return 0;
	fwt(f,1);
	fwt(g,1);
	up(i,0,m-1)
	{
		h[i]=f[i]*g[i];
	}
	fwt(h,-1);
	up(i,0,m-1)
	{
		printf("%lld",(h[i]>>(p[i]<<1))&3);
	}
}