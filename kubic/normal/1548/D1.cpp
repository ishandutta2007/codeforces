#include <bits/stdc++.h>
using namespace std;
#define N 6005
#define ll long long
int n,cnt[4],a[6],b[3];ll ans;
ll C2(ll x) {return x<2?0:x*(x-1);}
ll C3(ll x) {return x<3?0:x*(x-1)*(x-2);}
ll calc()
{
	b[0]=a[0]*2+a[1];b[1]=a[2]*2+a[3];b[2]=a[4]*2+a[5];sort(b,b+3);
	if(b[0]==b[1] && b[0]==b[2]) return C3(cnt[b[0]]);
	if(b[0]==b[1]) return C2(cnt[b[0]])*cnt[b[2]];
	if(b[1]==b[2]) return cnt[b[0]]*C2(cnt[b[1]]);
	return cnt[b[0]]*cnt[b[1]]*cnt[b[2]];
}
ll slv(int stt)
{
	for(int i=0;i<6;++i) a[i]=stt>>i&1;
	if(a[0]*a[3]+a[1]*a[2]+a[2]*a[5]+a[3]*a[4]+a[4]*a[1]+a[5]*a[0]&1) return 0;
	return calc();
}
int main()
{
	scanf("%d",&n);
	for(int i=1,x,y;i<=n;++i) scanf("%d %d",&x,&y),++cnt[(x/2&1)*2+(y/2&1)];
	for(int i=0;i<1<<6;++i) ans+=slv(i);printf("%lld\n",ans/6);return 0;
}