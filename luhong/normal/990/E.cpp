#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<cmath> 
using namespace std;
int Abs(int x){return x>0?x:-x;}
int gcd(int a,int b){return b==0?a:gcd(b,a%b);}
bool used[1010000];
int c[1001000],nxt[1010000];long long INF=1e18;
int main()
{
	int n,m,k;scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++){int a;scanf("%d",&a);used[a]=1;}
	nxt[n]=n;for(int i=n-1;i>=0;i--)if(used[i])nxt[i]=nxt[i+1];else nxt[i]=i;
	for(int i=1;i<=k;i++)scanf("%d",&c[i]);
	long long ans=INF;
	for(int i=1;i<=k;i++)
	{
		int now=n,tot=0;bool ok=0;
		while(now)
		{
			int u=nxt[max(0,now-i)];if(u==now){ok=1;break;}
			now=u;tot++;
		}
		if(!ok)ans=min(ans,1ll*tot*c[i]);
	}
	if(ans==INF)return 0*puts("-1");
	printf("%lld",ans);return 0;
}