#include<bits/stdc++.h>
#define re register
int a[210][210],ss[40100],ll[210][210],cn[210][210],ax[]={1,-1,0,0},ay[]={0,0,1,-1},ta,S,T;
struct eg{int to,c,nx;}e[2000100];
int cct,la[200100],cur[200100],q[200100],d[200100],n;
inline void addE(re int a,re int b,re int c)
{
	e[++cct]=(eg){b,c,la[a]};la[a]=cct;
	e[++cct]=(eg){a,0,la[b]};la[b]=cct;
}
bool bfs()
{
	re int ta=1;
	for(re int i=1;i<=T;i++)d[i]=0,cur[i]=la[i];
	q[1]=T;d[T]=1;
	for(re int i=1;i<=ta;i++)
	{
		re int x=q[i];
		for(re int j=la[x];j;j=e[j].nx)if(e[j^1].c&&!d[e[j].to])
		{
			d[e[j].to]=d[x]+1;
			if(e[j].to==S)return 1;
			q[++ta]=e[j].to;
		}
	}
	return 0;
}
int dfs(re int a,re int fl)
{
	if(a==T){return fl;}
	re int ff=fl;
	for(re int&i=cur[a];i;i=e[i].nx)if(e[i].c&&d[e[i].to]==d[a]-1)
	{
		re int c=dfs(e[i].to,std::min(ff,e[i].c));
		ff-=c;e[i].c-=c;e[i^1].c+=c;
		if(!ff)return fl;
	}
	return fl-ff;
}
void dinic()
{
	while(bfs())dfs(S,1<<30);
}
void ddfs(re int a)
{
	d[a]=1;
	for(re int i=la[a];i;i=e[i].nx)if(e[i].c&&!d[e[i].to])
	{
		ddfs(e[i].to);
	}
}
void dc(re int l,re int r)
{
	if(l==r)return;
	re int mid=(l+r)/2;
	re int cnt=0;cct=1;
	for(re int i=1;i<=n;i++)
		for(re int j=1;j<=n;j++)
		if(ll[i][j]==l&&a[i][j]==0){
			cn[i][j]=++cnt;la[cnt]=0;
		}
		else cn[i][j]=0;
	S=cnt+1;T=cnt+2;la[S]=la[T]=0;
	for(re int i=1;i<=n;i++)
		for(re int j=1;j<=n;j++)
		{
			if(a[i][j]!=-1&&(ll[i][j]!=l||a[i][j]>0)){
				for(re int ii=0;ii<=3;ii++)
				if(cn[i+ax[ii]][j+ay[ii]]){
					if((a[i][j]!=0&&a[i][j]<=ss[mid])||(a[i][j]==0&&ll[i][j]<l))addE(S,cn[i+ax[ii]][j+ay[ii]],1);
					else addE(cn[i+ax[ii]][j+ay[ii]],T,1);
				}
			}
			else if(cn[i][j]){
				for(re int ii=0;ii<=3;ii++)
				if(cn[i+ax[ii]][j+ay[ii]]){
					addE(cn[i][j],cn[i+ax[ii]][j+ay[ii]],1);
				}
			}
		}
	dinic();
	for(re int i=1;i<=T;i++)d[i]=0;
	ddfs(S);
	for(re int i=1;i<=n;i++)
		for(re int j=1;j<=n;j++)
		if(cn[i][j]){
			if(d[cn[i][j]])ll[i][j]=l;
			else ll[i][j]=mid+1;
		}
	dc(l,mid);
	dc(mid+1,r);
}
int main()
{
	scanf("%d",&n);
	for(re int i=1;i<=n;i++)
	{
		for(re int j=1;j<=n;j++)
		{
			scanf("%d",&a[i][j]);
			if(a[i][j]>0)ss[++ta]=a[i][j];
			if(a[i][j]==0)ll[i][j]=1;
		}
	}
	std::sort(ss+1,ss+ta+1);
	ta=std::unique(ss+1,ss+ta+1)-ss-1;
	dc(1,ta);
	for(re int i=1;i<=n;i++)
		for(re int j=1;j<=n;j++)if(a[i][j]==0)a[i][j]=ss[ll[i][j]];
	for(re int i=0;i<=n+1;i++)a[0][i]=a[n+1][i]=a[i][0]=a[i][n+1]=-1;
	re long long ans=0;
	for(re int i=1;i<=n;i++)
		for(re int j=1;j<=n;j++)
			for(re int ii=0;ii<=3;ii+=2)
				if(a[i+ax[ii]][j+ay[ii]]!=-1&&a[i][j]!=-1)
				{
				//	printf("****%d %d %d %d %d\n",i,j,i+ax[ii],j+ay[ii],a[i+ax[ii]][j+ay[ii]]);
					ans+=abs(a[i+ax[ii]][j+ay[ii]]-a[i][j]);
				}
	printf("%lld\n",ans);
}