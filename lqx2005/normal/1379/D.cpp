#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=510000;
int n,h,m,k;
int tr[N],l[N],r[N];
int san[N],tot=0,sum[N];
void Init()
{
	for(int i=1;i<=n;i++) san[++tot]=l[i],san[++tot]=r[i];
	sort(san+1,san+tot+1);
	tot=unique(san+1,san+tot+1)-(san+1);
	for(int i=1;i<=n;i++)
	{
		l[i]=lower_bound(san+1,san+tot+1,l[i])-san;
		r[i]=lower_bound(san+1,san+tot+1,r[i])-san;
	}
	return;
}
signed main()
{
	scanf("%lld%lld%lld%lld",&n,&h,&m,&k);
	int x,y;
	for(int i=1;i<=n;i++) 
	{
		scanf("%lld%lld",&x,&y);
		tr[i]=m*x+y;
		l[i]=tr[i]%(m/2);
		r[i]=(tr[i]+k)%(m/2);
		swap(l[i],r[i]);
	}
	Init();
	for(int i=1;i<=n;i++)
	{
		if(l[i]<=r[i]) sum[l[i]]++,sum[r[i]+1]--;
		else sum[0]++,sum[r[i]+1]--,sum[l[i]]++;
	}
	for(int i=1;i<=tot;i++) sum[i]+=sum[i-1];
	int ans=0,pos=-1;
	for(int i=1;i<=tot;i++) if(ans<sum[i])  ans=sum[i],pos=i;
	printf("%lld %lld\n",n-ans,san[pos]);
	for(int i=1;i<=n;i++)
	{
		if(l[i]<=r[i])
		{
			if(l[i]<=pos&&pos<=r[i]) continue;
			else printf("%lld ",i); 
		}
		else
		{
			if(r[i]+1<=pos&&pos<=l[i]-1) printf("%lld ",i);
		}
	}
	printf("\n");
	return 0;
}