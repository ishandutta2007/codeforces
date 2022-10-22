/* **********************************************
Created Time: 2020/4/11 11:06:03
File Name: SegmentTree
*********************************************** */
#include<bits/stdc++.h>
using namespace std;
#define Deg fprintf(stderr,"Passing [%s] line %d\n",__FUNCTION__,__LINE__)
typedef long long ll;
const int N=155000;
int n,m,q;
ll a[N];
map<int,ll> P;
void mul(ll &a,int b,int mod)
{
  a*=b;
  if(a>=mod) a=a%mod+mod;
  return;
}
ll qpow(ll a,int b,int mod)
{
  ll res=1;
  for(;b>0;b/=2,mul(a,a,mod)) if(b%2) mul(res,a,mod);
  return res;
}
ll Phi(int x)
{
  if(P.find(x)!=P.end()) return P[x];
  ll res=x;
  int t=x;
  for(ll i=2;i*i<=x;i++)
  {
    if(x%i==0)
    {
      res=res/i*(i-1);
      while(x%i==0) x/=i;
    }
  }
  if(x!=1) res=res/x*(x-1);
  P[t]=res;
  return res;
}
ll Ca(int l,int r,int mod)
{
  if(l>r) return 1;
  if(mod==1) return 1;
  ll Ph=Phi(mod);
  ll cnt=Ca(l+1,r,Ph);
  return qpow(a[l],cnt,mod);
}
int main()
{
  scanf("%d%d",&n,&m);
  for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
  scanf("%d",&q);
  int l,r;
  for(int i=1;i<=q;i++)
  {
    scanf("%d%d",&l,&r);
    printf("%lld\n",Ca(l,r,m)%m);
  }
  return 0;
}