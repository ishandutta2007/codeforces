#include<cstdio>
#include<cstring>
#include<algorithm>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define Rep(i,x) for(int i=head[x];i+1;i=nxt[i])
#define rep2(i,a,b) for(int i=(a);i<(b);i++)
#define ff first
#define ss second
using namespace std;
const int N=300005;
const int inf=1e9+7;
typedef long long ll;
//------------------------------------------head---------------------------------------------------//
int f[N],a[N],n,k;
int chk(int x)
{
	memset(f,0,sizeof(f));
	f[0]=1;int l=0,tot=0;
	rep(i,k,n)
	{
		tot+=f[i-k];
		while(a[i]-a[l+1]>x && l<=i-k){tot-=f[l];l++;}
		if(tot>0)f[i]=1;
	}
	return f[n];
}
int main()
{
	scanf("%d%d",&n,&k);
	rep(i,1,n)scanf("%d",&a[i]);sort(a+1,a+1+n);
	int left=0,right=inf,ans=0;
	while(left<=right)
	{
		int mid=(left+right)>>1;
		if(chk(mid)) right=mid-1,ans=mid;
		else left=mid+1;
	}
	printf("%d\n",ans);
	return 0;
}