#include<cstdio>
#include<algorithm>
using std::max;
using std::min;
namespace sgt
{
	const int N=1e5+5;
	int mx[N],tag[N];
	inline void push_down(int x)
	{
		if(!tag[x])
			return;
		mx[x<<1]+=tag[x];tag[x<<1]+=tag[x];
		mx[x<<1|1]+=tag[x];tag[x<<1|1]+=tag[x];
		tag[x]=0;
		return;
	}
	inline void push_up(int x)
	{
		mx[x]=max(mx[x<<1],mx[x<<1|1]);
		return;
	}
	void modi(int x,int lp,int rp,int l,int r,int k)
	{
		if(l>r)
			return;
		if(lp==l&&rp==r)
		{
			mx[x]+=k;tag[x]+=k;
			return;
		}
		push_down(x);
		int mid=(lp+rp)>>1;
		if(r<=mid)
			modi(x<<1,lp,mid,l,r,k);
		else if(l>=mid+1)
			modi(x<<1|1,mid+1,rp,l,r,k);
		else
			modi(x<<1,lp,mid,l,mid,k),modi(x<<1|1,mid+1,rp,mid+1,r,k);
		push_up(x);
		return;
	}
	int que()
	{
		return mx[1];
	}
}
const int N=2005;
int n,m,k,s[N],ans;
int l[N],r[N],mx[N];
int f[N][N];
inline int itr(int l1,int r1,int l2,int r2)
{
	return max(min(r1,r2)-max(l1,l2)+1,0);
}
inline void init(int t)
{
	register int i;
	for(i=mx[t]=1;i<=n-k+1;i++)
	{
		f[t][i]=itr(i,i+k-1,l[t],r[t]);
		mx[t]=((f[t][i]>f[t][mx[t]])?i:mx[t]);
		sgt::modi(1,1,n-k+1,i,i,f[t][i]);
	}
//	pre[t][1]=0;
//	for(i=2;i<=n-k+1;i++)
//		pre[t][i]=(f[t][i-1]==f[t][i])?pre[t][i-1]:(i-1);
//	suc[t][n-k+1]=n-k+2;
//	for(i=n-k;i>=1;i--)
//		suc[t][i]=(f[t][i+1]==f[t][i])?suc[t][i+1]:(i+1);
	return;
}
inline void add(int t,int x)
{
	int l,r,mid;
	l=0;r=mx[t];
	while(l<r)
	{
		mid=(l+r+1)>>1;
		if(f[t][mid]<=s[t])
			l=mid;
		else
			r=mid-1;
	}
	sgt::modi(1,1,n-k+1,1,l,x);
	l=mx[t]+1;r=n-k+2;
	while(l<r)
	{
		mid=(l+r)>>1;
		if(f[t][mid]<=s[t])
			r=mid;
		else
			l=mid+1;
	}
	sgt::modi(1,1,n-k+1,l,n-k+1,x);
	return;
}
signed main()
{
	register int i,j;
	scanf("%d%d%d",&n,&m,&k);
	for(i=1;i<=m;i++)
		scanf("%d%d",&l[i],&r[i]),init(i);
	for(i=1;i<=n-k+1;i++)
	{
		for(j=1;j<=m;j++)
		{
			while(s[j]<f[j][i])
				add(j,1),s[j]++;
			while(s[j]>f[j][i])
				s[j]--,add(j,-1);
		}
		ans=max(ans,sgt::que());
	}
	printf("%d\n",ans);
	return 0;
}