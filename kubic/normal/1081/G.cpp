#include <bits/stdc++.h>
using namespace std;
#define N 1000005
const int lim=1e6;
int n,m,c,d,r,ans,MOD,inv[N];
int add(int x,int y) {x+=y;return x<MOD?x:x-MOD;}
int f(int x) {return min(x-1,d)-max(x-d,1)+1;} 
int main()
{
	scanf("%d %d %d",&n,&m,&MOD);c=1;
	for(int i=1;i<=lim;++i)
		inv[i]=i==1?1:1ll*inv[MOD%i]*(MOD-MOD/i)%MOD;
	for(int i=1;i<m;++i) c=min(c*2,n);d=n/c;r=n%c;
	ans=(1ll*d*(d-1)*(c-r)+1ll*(d+1)*d*r)%MOD*inv[4]%MOD;
	ans=add(ans,1ll*r*(r-1)*d%MOD*inv[d*4+4]%MOD);
	for(int i=2;i<=d*2;++i)
		ans=add(ans,1ll*c*(c-1)*f(i)%MOD*(i-2)%MOD*inv[i*4]%MOD);
	for(int i=d+2;i<=d*2+1;++i)
		ans=add(ans,1ll*(c-1)*r*(i-2)%MOD*inv[i*2]%MOD);
	printf("%d\n",ans);return 0;
}