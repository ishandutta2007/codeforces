#include<bits/stdc++.h>
#define re register
int fa[51][500100],fv[51][500100],ans[500100],K;
std::vector<int>vc[2001000];
bool vy;
int find(re int a){return fa[K][a]<0?a:(vy^=fv[K][a],find(fa[K][a]));}
int sta[501000],stf[500100],stk[500100],ta;
void meg(re int a,re int b)
{
	vy=1;
	a=find(a);b=find(b);
	if(a!=b)
	{
		if(fa[K][a]>fa[K][b])std::swap(a,b);
		sta[++ta]=b;stf[ta]=fa[K][b];stk[ta]=K;
		fa[K][a]+=fa[K][b],fa[K][b]=a;fv[K][b]=vy;
	}
}
int x[500100],y[500100],nw[500100],la[500100],e[500100],c[500100],rr[500100],n,m,k,q;
int l1,r1,v1;
void add(re int i,re int l,re int r)
{
	if(l>=l1&&r<=r1){vc[i].push_back(v1);return;}
	re int mid=(l+r)/2;
	if(l1<=mid)add(i*2,l,mid);
	if(r1>mid)add(i*2+1,mid+1,r);
}
void dfs(re int i,re int l,re int r)
{
	re int mid=(l+r)/2,tta=ta;
	for(re int j=0;j<vc[i].size();j++)
	{
		re int x1=vc[i][j];//printf("***%d\n",x1);
		K=c[x1];x1=e[x1];
		meg(x[x1],y[x1]);
	}
	if(l==r)
	{
		vy=0;K=c[l];
		//printf("***%d %d %d\n",x[e[l]],y[e[l]],vy);
		re int x1=find(x[e[l]]),y1=find(y[e[l]]);
		if(x1!=y1||vy==1)nw[e[l]]=l,ans[l]=1;
		l1=l+1;r1=rr[l];v1=nw[e[l]];
		if(v1)add(1,1,q);
	}else
	{
		dfs(i*2,l,mid);
		dfs(i*2+1,mid+1,r);
	}
	for(;ta>tta;ta--)
	{
		K=stk[ta];
		fa[K][fa[K][sta[ta]]]-=stf[ta];
		fa[K][sta[ta]]=stf[ta];
	}
}
int main()
{
	scanf("%d%d%d%d",&n,&m,&k,&q);
	for(re int i=1;i<=m;i++)scanf("%d%d",&x[i],&y[i]);
	for(re int i=1;i<=k;i++)for(re int j=1;j<=n;j++)fa[i][j]=-1;
	for(re int i=1;i<=q;i++)
	{
		scanf("%d%d",&e[i],&c[i]);
		if(la[e[i]])rr[la[e[i]]]=i-1;
		la[e[i]]=i;
	}
	for(re int i=1;i<=q;i++)if(!rr[i])rr[i]=q;
	dfs(1,1,q);
	for(re int i=1;i<=q;i++)if(ans[i])puts("YES");else puts("NO");
}