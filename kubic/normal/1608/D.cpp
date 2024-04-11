#include <bits/stdc++.h>
using namespace std;
#define N 200005
#define MOD 998244353
const int lim=2e5;
int T,n,w,ans,cnt[9],fc[N],invF[N];char a[N][5];
void W(int &x,int y) {x+=y;if(x>=MOD) x-=MOD;}
int qPow(int x,int y)
{
	int res=1;
	for(;y;y/=2,x=1ll*x*x%MOD) if(y&1) res=1ll*res*x%MOD;
	return res;
}
int C(int x,int y) {return x<y?0:1ll*fc[x]*invF[y]%MOD*invF[x-y]%MOD;}
int main()
{
	scanf("%d",&n);fc[0]=invF[0]=1;
	for(int i=1;i<=n;++i) scanf("%s",a[i]);
	for(int i=1;i<=lim;++i) fc[i]=1ll*fc[i-1]*i%MOD;
	invF[lim]=qPow(fc[lim],MOD-2);
	for(int i=lim-1;i;--i) invF[i]=1ll*invF[i+1]*(i+1)%MOD;
	for(int i=1,t;i<=n;++i)
	{
		t=0;if(a[i][0]=='B') t+=3;if(a[i][0]=='?') t+=6;
		if(a[i][1]=='B') t+=1;if(a[i][1]=='?') t+=2;++cnt[t];
	}
	if(!cnt[0] && !cnt[4])
	{
		W(ans,MOD-qPow(2,cnt[8]));
		if(!cnt[1] && !cnt[2] && !cnt[7]) ++ans;
		if(!cnt[3] && !cnt[6] && !cnt[5]) ++ans;
	}w=cnt[4]+cnt[5]+cnt[7]+cnt[8]-cnt[0];
	if(w<0) {printf("%d\n",ans);return 0;}
	W(ans,C(cnt[2]+cnt[5]+cnt[6]+cnt[7]+cnt[8]*2,w));
	printf("%d\n",ans);return 0;
}