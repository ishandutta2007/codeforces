#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ls rt<<1
#define rs rt<<1|1
inline int read()
{
	char ch=getchar();bool f=0;int x=0;
	for(;!isdigit(ch);ch=getchar())if(ch=='-')f=1;
	for(;isdigit(ch);ch=getchar())x=(x<<1)+(x<<3)+(ch^48);
	if(f==1)x=-x;return x;
}
const int maxn=200005;
int f[maxn],n,d,a[maxn],b[maxn],tot=0,las[maxn],x,y,Max[maxn*4],pos,id1[maxn*4],h,ll,xx,yy;
map<long long,int>id;
int getx(int k)
{
	int l=1,r=k,res=0;
	if(b[k]-b[1]<d)return 0;
	while(l<=r)
	{
		int mid=(l+r)>>1;
		if(b[k]-b[mid]>=d)l=mid+1,res=mid;
		else r=mid-1;
	}
	return res;
}
int gety(int k)
{
	int l=k,r=tot,res=0;
	if(b[tot]-b[k]<d)return 0;
	while(l<=r)
	{
		int mid=(l+r)>>1;
		if(b[mid]-b[k]>=d)r=mid-1,res=mid;
		else l=mid+1;
	}
	return res;
}
inline void push(int rt)
{
	if(Max[ls]>Max[rs])Max[rt]=Max[ls],id1[rt]=id1[ls];
	else Max[rt]=Max[rs],id1[rt]=id1[rs];
}
void change(int rt,int l,int r,int x,int num,int i)
{
	if(l==x&&r==x){Max[rt]=num;id1[rt]=i;return;}
	int mid=(l+r)>>1;
	if(x<=mid)change(ls,l,mid,x,num,i);
	else change(rs,mid+1,r,x,num,i);
	push(rt);//cout<<Max[rt]<<" "<<rt<<endl;
}
int query(int rt,int l,int r,int L,int R,int &pos)
{
	//if(l>R||r<L)return 0;
	if(l>=L&&r<=R){pos=id1[rt];return Max[rt];}
	int mid=(l+r)>>1,sum1,sum2,x1,x2;x1=x2=0;
	if(L<=mid)x1=query(ls,l,mid,L,R,sum1);
	if(mid<R)x2=query(rs,mid+1,r,L,R,sum2);
	if(x1>x2){pos=sum1;return x1;}
	else {pos=sum2;return x2;}
}
void dfs(int x)
{
	if(x==0)return;
	dfs(las[x]);
	printf("%lld ",x);
}
signed main()
{
	n=read(),d=read();
	for(int i=1;i<=n;i++)
	{
		a[i]=b[i]=read();
	}
	sort(b+1,b+n+1);
	for(int i=1;i<=n;i++)
	{
		b[++tot]=b[i];id[b[tot]]=tot;
		int j=i+1;
		while(b[j]==b[i]&&j<=n)j++;
		i=j-1;
	}
	for(int i=1;i<=n;i++)
	{
		f[i]=1;h=0;
		x=getx(id[a[i]]),y=gety(id[a[i]]);
		if(x)
		{
			int xx=query(1,1,tot,1,x,h)+1;
			if(xx>f[i])f[i]=xx,las[i]=h;
		}
		if(y)
		{
			int yy=query(1,1,tot,y,tot,h)+1;
			if(yy>f[i])f[i]=yy,las[i]=h;
		}
		//cout<<las[i]<<" "<<x<<" "<<y<<" "<<f[i]<<endl;
		change(1,1,tot,id[a[i]],f[i],i);
	}
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		if(ans<f[i])ans=f[i],ll=i;
	}
	printf("%lld\n",ans);dfs(ll);
	return 0;
}