#include<bits/stdc++.h>
#define re register
int ans[300100],stx[300100],sty[300100],stz[300100],z,fa[300100],ta,n,m,m1,as;
struct eg{int x,y,w,t;}e[300100];
inline bool cmp(const eg&A,const eg&B){return A.w>B.w;}
std::vector<int>vc[1500100];
int find(re int a){for(;fa[a]>0;a=fa[a]);return a;}
void meg(re int a,re int b)
{
	a=find(a);b=find(b);//printf("**%d %d %d %d %d\n",a,b,-fa[a],-fa[b],z);
	if(a!=b)
	{
		if(((-fa[a])&1)&&((-fa[b])&1))z-=2,stz[++ta]=2;else stz[++ta]=0;
		if(fa[a]<fa[b])stx[ta]=b,sty[ta]=fa[b],fa[a]+=fa[b],fa[b]=a;
		else stx[ta]=a,sty[ta]=fa[a],fa[b]+=fa[a],fa[a]=b;
	}
}
int l1,r1,x1;
void add(re int i,re int l,re int r)
{
	if(l>=l1&&r<=r1){vc[i].push_back(x1);return;}
	re int mid=(l+r)/2;
	if(l1<=mid)add(i*2,l,mid);
	if(r1>mid)add(i*2+1,mid+1,r);
}
void dfs(re int i,re int l,re int r)
{
	re int tta=ta;
	for(re int i1=0;i1<vc[i].size();i1++)meg(e[vc[i][i1]].x,e[vc[i][i1]].y);
	if(l==r)
	{
		for(;m1&&z;m1--)
		{//printf("***%d %d\n",m1,e[m1].t);
			as=e[m1].w;
			if(e[m1].t<=l)
			{
				meg(e[m1].x,e[m1].y);
				if(e[m1].t<l)l1=e[m1].t,r1=l-1,x1=m1,add(1,1,m);
			}
		}
		if(!m1&&z)ans[l]=1<<30;
		else ans[l]=as;
	}else
	{
		re int mid=(l+r)/2;
		dfs(i*2+1,mid+1,r);
		dfs(i*2,l,mid);
	}
	for(;ta>tta;ta--)
	{
		z+=stz[ta];
		re int x=stx[ta],y=sty[ta];
		fa[fa[x]]-=y;
		fa[x]=y;
	}
}
int main()
{
	scanf("%d%d",&n,&m);m1=m;z=n;
	for(re int i=1;i<=n;i++)fa[i]=-1;
	for(re int i=1;i<=m;i++)scanf("%d%d%d",&e[i].x,&e[i].y,&e[i].w),e[i].t=i;
	std::sort(e+1,e+m+1,cmp);
	dfs(1,1,m);
	for(re int i=1;i<=m;i++)if(ans[i]<(1<<30))printf("%d\n",ans[i]);else puts("-1");
}