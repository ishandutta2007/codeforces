#include <bits/stdc++.h>
#define int long long
#define down(i,x,y) for(int i=x,i##end=y;i>=i##end;--i)
#define up(i,x,y) for(int i=x,i##end=y;i<=i##end;++i)
using namespace std;
int n,m,k;
const int maxn=(1<<20)+10;
int f[maxn],g[maxn],h[maxn];
void fwt(int f[],int fl,int n)
{
	for(int len=1;len<(1<<n);len<<=1)
	{
		for(int p=0;p<(1<<n);p+=(len<<1))
		{
			up(i,0,len-1)
			{
				int x=f[i|p],y=f[i|p|len];
				f[i|p]=(x+y)/fl;
				f[i|p|len]=(x-y)/fl;
			}
		}
	}
}
char c[maxn];
short p[maxn];
int cnt[maxn];
signed main()
{
	cin>>n>>m;
	k=(1<<n);
	up(i,0,n-1)
	{
		scanf("%s",c);
		up(j,0,m-1)
		{
			if(c[j]=='1')h[j]|=(1<<i);
		}
	}
	up(i,0,m-1)f[h[i]]++;
	up(i,1,k-1)cnt[i]=cnt[i>>1]+(i&1);
	up(i,0,k-1)g[i]=min(cnt[i],n-cnt[i]);
	fwt(f,1,n);fwt(g,1,n);
	up(i,0,k-1)f[i]*=g[i];
	fwt(f,2,n);
	int ans=13401001301ll;
	up(i,0,k-1)ans=min(ans,f[i]);
	cout<<ans;
}