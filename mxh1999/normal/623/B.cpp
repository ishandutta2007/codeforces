#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define maxn 1000010
const ll INF=1LL<<60;
typedef long long ll;
int a[maxn];
int n,e1,e2;
int b[1010],cnt;
ll f[maxn][3];
int q[maxn];
ll ans;
void doit(int t)
{
	for (int i=2;i*i<=t;i++)
	if (t%i==0)
	{
		b[++cnt]=i;
		while (t%i==0)	t/=i;
	}
	if (t!=1)	b[++cnt]=t;
}
inline ll min(ll a,ll b)
{
	if (a>b)	return b;
	return a;
}
int main()
{
	scanf("%d%d%d",&n,&e1,&e2);
	for (int i=1;i<=n;i++)	scanf("%d",&a[i]);
	ans=INF;
	doit(a[1]),doit(a[1]+1),doit(a[1]-1);
	doit(a[n]),doit(a[n]+1),doit(a[n]-1);
	sort(b+1,b+cnt+1);
	cnt=unique(b+1,b+cnt+1)-(b+1);
	for (int i=1;i<=cnt;i++)
	{
		ll sum=0;
		for (int j=1;j<=n;j++)
		{
			if (a[j]%b[i]==0)	q[j]=0;else
			if ((a[j]+1)%b[i]==0 || (a[j]-1)%b[i]==0)	q[j]=1;else
			q[j]=2;
		}
		
		for (int j=1;j<=n;j++)	f[j][0]=f[j][1]=f[j][2]=INF;
		f[0][0]=f[0][1]=f[0][2]=0;
		for (int j=1;j<=n;j++)
		{
			if (q[j]==0)
			{
				f[j][0]=f[j-1][0];
				f[j][1]=f[j-1][1]+e1;
				f[j][2]=f[j-1][2];
				f[j][2]=min(f[j][2],f[j][1]);
			}	else
			if (q[j]==1)
			{
				f[j][0]=f[j-1][0]+e2;
				f[j][1]=min(f[j-1][1],f[j-1][0])+e1;
				f[j][2]=min(f[j-1][2]+e2,f[j-1][1]+e1);
				f[j][2]=min(f[j][2],f[j][1]);
			}	else
			if (q[j]==2)
			{
				f[j][1]=min(f[j-1][1],f[j-1][0])+e1;
				f[j][2]=min(f[j][2],f[j][1]);
			}
		}
		sum=min(f[n][0],min(f[n][1],f[n][2]));
		ans=min(ans,sum);
	}
	cout<<ans<<endl;
}