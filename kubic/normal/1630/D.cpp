#include <bits/stdc++.h>
using namespace std;
#define N 1000005
#define LIM 1000005
#define ll long long
#define gc() (P1==P2 && (P2=(P1=buf)+fread(buf,1,LIM,stdin),P1==P2)?EOF:*P1++)
char *P1,*P2,buf[LIM];
int T,n,m,c,a[N];ll ans[2];
int rd()
{
	int res=0;bool fl=0;char c=0;while(!isdigit(c)) fl|=c=='-',c=gc();
	while(isdigit(c)) res=res*10+c-48,c=gc();return fl?-res:res;
}
int gcd(int x,int y) {return y?gcd(y,x%y):x;}
void slv()
{
	n=rd();m=rd();c=ans[0]=ans[1]=0;for(int i=1;i<=n;++i) a[i]=rd();
	for(int i=1,x;i<=m;++i) x=rd(),c=gcd(c,x);
	for(int i=1;i<=c;++i)
	{
		int t,mn=1e9;ll s=0;bool fl=0;
		for(int j=i;j<=n;j+=c) fl^=a[j]<0,t=abs(a[j]),s+=t,mn=min(mn,t);
		ans[0]+=s;ans[1]+=s;ans[!fl]-=mn*2;
	}printf("%lld\n",max(ans[0],ans[1]));
}
int main() {T=rd();while(T--) slv();return 0;}