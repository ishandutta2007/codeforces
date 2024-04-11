#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=300005;
int x,y,f[maxn][50],M[maxn][50],s[maxn][50],n,k,x1,x2,z;
void ans(int x,int y)
{ 	
	x1=0,x2=0x3f3f3f3f;
	for(int i=40;i>=0;i--)
	{
		z=(long long)1<<i;
		if(z<=y)x1+=s[x][i],x2=min(M[x][i],x2),x=f[x][i],y=y-z;
	}
		
}
signed main()
{
	cin>>n>>k;for(int i=1;i<=n;i++)scanf("%lld",&f[i][0]),f[i][0]++;
	for(int i=1;i<=n;i++)scanf("%lld",&y),s[i][0]=y,M[i][0]=y;
	for(int i=1;i<=40;i++)
		for(int j=1;j<=n;j++)
		{
			f[j][i]=f[f[j][i-1]][i-1];
			M[j][i]=min(M[j][i-1],M[f[j][i-1]][i-1]);
			s[j][i]=s[j][i-1]+s[f[j][i-1]][i-1];
		}
	for(int i=1;i<=n;i++)ans(i,k),printf("%lld %lld\n",x1,x2);
	return 0;
}