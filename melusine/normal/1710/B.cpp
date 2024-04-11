#include<iostream>
#include<cstdio>
#include<algorithm>
#define inf 1121131433448687LL
using namespace std;
inline int read()
{
	int n=0,f=1,ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		n=n*10+ch-'0';
		ch=getchar();
	}
	return n*f;
}
int qz[1000005],pos[1000005];
int dy[1000005];
long long yl[1000005],qd[1000005];
struct tree
{
	int l,r;
	long long maxn1,maxn2,maxn3;
}a[3000004];
void build(int l,int r,int k)
{
	a[k].l=l;
	a[k].r=r;
	if(l==r)
	{
		a[k].maxn1=yl[pos[l]]-qz[pos[l]];
		a[k].maxn2=yl[pos[l]];
		a[k].maxn3=yl[pos[l]]+qz[pos[l]];
		return;
	}
	build(l,(l+r)>>1,k<<1);
	build(((l+r)>>1)+1,r,k<<1|1);
	a[k].maxn1=max(a[k<<1].maxn1,a[k<<1|1].maxn1);
	a[k].maxn2=max(a[k<<1].maxn2,a[k<<1|1].maxn2);
	a[k].maxn3=max(a[k<<1].maxn3,a[k<<1|1].maxn3);
}
long long query1(int l,int r,int k)
{
	if(a[k].r<l||a[k].l>r)return -inf;
	if(a[k].l>=l&&a[k].r<=r)return a[k].maxn1;
	return max(query1(l,r,k<<1),query1(l,r,k<<1|1));
}
long long query2(int l,int r,int k)
{
	if(a[k].r<l||a[k].l>r)return -inf;
	if(a[k].l>=l&&a[k].r<=r)return a[k].maxn2;
	return max(query2(l,r,k<<1),query2(l,r,k<<1|1));
}
long long query3(int l,int r,int k)
{
	if(a[k].r<l||a[k].l>r)return -inf;
	if(a[k].l>=l&&a[k].r<=r)return a[k].maxn3;
	return max(query3(l,r,k<<1),query3(l,r,k<<1|1));
}
bool bi(int x,int y)
{
	return qz[x]<qz[y];
}
signed main()
{
	int t,n,m;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		m=read();
		for(int i=1;i<=n;i++)
		{
			qz[3*i-1]=read();
			pos[3*i]=3*i;
			pos[3*i-1]=3*i-1;
			pos[3*i-2]=3*i-2;
			qd[i]=read();
			qz[3*i]=qz[3*i-1]+qd[i];
			qz[3*i-2]=qz[3*i-1]-qd[i];
		}
		sort(pos+1,pos+3*n+1,bi);
		//for(int i=1;i<=3*n;i++)printf("%lld %lld\n",pos[i],qz[pos[i]]);
		for(int i=1;i<=3*n;i++)dy[pos[i]]=i;
		long long nans=0;
		int cf=0;
		for(int i=1;i<=n;i++)
		{
			if(qz[pos[1]]>=qz[3*i-2]&&qz[pos[1]]<=qz[3*i-1])nans+=qd[i]-qz[3*i-1]+qz[pos[1]];
			else if(qz[pos[1]]>=qz[3*i-1]&&qz[pos[1]]<=qz[3*i])nans+=qd[i]-qz[pos[1]]+qz[3*i-1];
		}
		cf=1;
		for(int i=1;i<=3*n;i++)
		{
			if(i!=1)nans+=1LL*cf*(qz[pos[i]]-qz[pos[i-1]]);
			//printf("%lld %lld\n",qz[pos[i]],nans);
			yl[pos[i]]=nans;
			//if(i!=1&&pos[i]==pos[i-1])yl[pos[i-1]]=-inf;
			if(i!=1)
			{
				if(pos[i]%3==0)cf++;
				else if(pos[i]%3==1)cf++;
				else if(pos[i]%3==2)cf-=2;
			}
		}
		build(1,3*n,1);
		for(int i=1;i<=n;i++)
		{
			long long nmax=max(query2(1,dy[3*i-2],1),query2(dy[3*i],3*n,1));
			//printf("%lld %lld\n",i,nmax);
			nmax=max(nmax,max(query1(dy[3*i-2],dy[3*i-1],1)-qd[i]+qz[3*i-1],query3(dy[3*i-1],dy[3*i],1)-qz[3*i-1]-qd[i]));
			//printf("%lld %lld\n",i,nmax);
			if(nmax<=m)printf("1");
			else printf("0");
		}
		printf("\n");
	}
	return 0;
}