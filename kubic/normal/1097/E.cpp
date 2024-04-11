#include <bits/stdc++.h>
using namespace std;
#define N 100005
#define pb push_back
int T,n,m,tp,tmp,a[N];bool vs[N];
int n1,n2,ps,dp[N],pr[N],vl[N];vector<int> vc[N];
void clear() {for(int i=1;i<=n;++i) vl[i]=0;}
void upd(int x,int w)
{for(;x<=n;x+=x&-x) if(dp[w]>dp[vl[x]]) vl[x]=w;}
int qry(int x)
{
	int res=0;
	for(;x;x-=x&-x) if(dp[vl[x]]>dp[res])
		res=vl[x];return res;
}
void slv()
{
	scanf("%d",&n);m=tp=0;while(m*(m+1)/2<=n) ++m;--m;
	for(int i=1;i<=n;++i)
		vs[i]=0,vc[i].clear(),scanf("%d",&a[i]);n1=n;
	while(n1)
	{
		++tp;n2=ps=0;clear();
		for(int i=1,t;i<=n1;++i)
		{
			t=qry(a[i]);dp[i]=dp[t]+1;
			pr[i]=t;upd(a[i],i);if(dp[i]>dp[ps]) ps=i;
		}
		if(dp[ps]>m)
		{
			for(int i=ps;i;i=pr[i])
				vs[a[i]]=1,vc[tp].pb(a[i]);	
			reverse(vc[tp].begin(),vc[tp].end());
			for(int i=1;i<=n1;++i) if(!vs[a[i]])
				a[++n2]=a[i];n1=n2;--m;continue;
		}tmp=--tp;
		for(int i=1,l,r,mid;i<=n1;++i)
		{
			l=tmp+1;r=tp;
			while(l<=r)
			{
				mid=(l+r)/2;
				if(*--vc[mid].end()>a[i]) r=mid-1;
				else l=mid+1;
			}vc[l].pb(a[i]);if(l>tp) ++tp;
		}break;
	}printf("%d\n",tp);
	for(int i=1;i<=tp;++i,putchar('\n'))
	{
		printf("%d ",vc[i].size());
		for(auto j:vc[i]) printf("%d ",j);
	}
}
int main() {scanf("%d",&T);while(T--) slv();return 0;}