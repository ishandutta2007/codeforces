#include <bits/stdc++.h>
using namespace std;
#define N 100005
#define MOD 1000000007 
int T,n,m,ans,w;
int qPow(int x,int y)
{
	int res=1;
	for(;y;y/=2,x=1ll*x*x%MOD) if(y&1)
		res=1ll*res*x%MOD;return res;
}
void slv()
{
	scanf("%d %d",&n,&m);ans=0;
	if(n&1) printf("%d\n",qPow(qPow(2,n-1)+1,m));
	else
	{
		w=qPow(2,n-1);ans=qPow(w-1,m);
		for(int i=1;i<=m;++i)
			ans=(ans+1ll*qPow(w-1,i-1)*qPow(w*2,m-i))%MOD;
		printf("%d\n",ans); 
	}
}
int main()
{
	scanf("%d",&T);
	while(T--) slv();return 0;
}