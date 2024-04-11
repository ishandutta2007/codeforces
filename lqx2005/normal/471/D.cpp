/* **********************************************
Created Time: 2020/4/2 16:03:32
File Name: SegmentTree
*********************************************** */
#include<bits/stdc++.h>
using namespace std;
#define Deg fprintf(stderr,"Passing [%s] line %d\n",__FUNCTION__,__LINE__)
typedef long long LL;
const int maxn=210000;
const LL mod=999999937;
const LL B=131;
int n,m;
LL a[maxn],b[maxn];
LL h[maxn],p[maxn],s[maxn];
LL calc(int l,int r)
{
   if(l>r) return 0;
   LL res=((h[r]-h[l-1]*p[r-l+1]%mod)+mod)%mod;
   res-=a[l]%mod*s[r-l]%mod;
   res=(res%mod+mod)%mod;
   return res;
}
int main()
{
	scanf("%d%d",&n,&m);
   p[0]=1;
   for(int i=1;i<=max(n,m);i++) p[i]=p[i-1]*B%mod;
   s[0]=1;
   for(int i=1;i<=max(n,m);i++) s[i]=(s[i-1]+p[i])%mod;
   for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
   for(int i=1;i<=m;i++) scanf("%lld",&b[i]);
   for(int i=1;i<=n;i++) h[i]=(h[i-1]*B%mod+a[i])%mod;
   LL aim=0;
   for(int i=1;i<=m;i++) aim=(aim*B%mod+((b[i]-b[1])%mod+mod)%mod)%mod;
   int cnt=0;
   for(int i=m;i<=n;i++) if(calc(i-m+1,i)==aim) cnt++;
   printf("%d\n",cnt);
	return 0;
}