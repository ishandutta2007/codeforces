#include<bits/stdc++.h>
#define re register
int x1[10][10],x2[10][10],fl[10][10][2],d[10],dd[10][10],qw[10],cur[10],n,x[10],y[10],k=1,ex[10],nm[10];
char ss[10];
int a1[10],b1[10];
int q[100100],ta;
bool bfs()
{
	re bool bo=0;ta=0;
	for(re int i=1;i<=k;cur[i]=1,i++)if(nm[i])d[i]=1,q[++ta]=i;else d[i]=0;
	memset(dd,0,sizeof(dd));
	for(re int i=1;i<=ta;i++)
	{
		re int x=q[i];
		if(x<=k)
		{
			for(re int j=1;j<=x;j++)if(!dd[j][x])dd[j][x]=d[x]+1,q[++ta]=j*k+x;
			for(re int j=x+1;j<=k;j++)if(!dd[x][j])dd[x][j]=d[x]+1,q[++ta]=x*k+j;
		}else
		{
			re int y=(x-1)%k+1;x=(x-y)/k;
			if(x2[x][y])bo=1;
			if(!d[x]&&fl[x][y][0])d[x]=dd[x][y]+1,q[++ta]=x;
			if(!d[y]&&fl[x][y][1])d[y]=dd[x][y]+1,q[++ta]=y;
		}
	}
	return bo;
}
int dfs1(re int,re int);
int dfs2(re int i,re int j,re int ff)
{
	re int fa=std::max(ff-x2[i][j],0);
	x2[i][j]=std::max(x2[i][j]-ff,0);
	if(!fa)return ff;
	if(d[i]==dd[i][j]+1&&fl[i][j][0]){
		re int t=dfs1(i,std::min(fa,fl[i][j][0]));
		fa-=t;fl[i][j][0]-=t;
		if(!fa)return ff;
	}
	if(d[j]==dd[i][j]+1&&fl[i][j][1]){
		re int t=dfs1(j,std::min(fa,fl[i][j][1]));
		fa-=t;fl[i][j][1]-=t;
		if(!fa)return ff;
	}
	return ff-fa;
}
int dfs1(re int i,re int ff)
{
	re int fa=ff;
	for(re int&j=cur[i];j<=i;j++)
	if(dd[j][i]==d[i]+1){
		re int t=dfs2(j,i,fa);
		fa-=t;fl[j][i][1]+=t;
		if(!fa)return ff;
	}
	if(cur[i]==i)cur[i]++;
	for(re int&j=cur[i];j<=k;j++)
	if(dd[i][j]==d[i]+1){
		re int t=dfs2(i,j,fa);
		fa-=t;fl[i][j][0]+=t;
		if(!fa)return ff;
	}
	return ff-fa;
}
void clac()
{
	memcpy(x2,x1,sizeof(x1));
	memset(b1,0,sizeof(b1));
	memset(fl,0,sizeof(fl));
	re int xx,yy;
	for(re int i=1;i<=k-2;i++)
	{
		yy=a1[i];
		for(re int j=i;j<=k-2;j++)b1[a1[j]]++;
		for(xx=1;xx<=k;xx++)if(!b1[xx])break;
		b1[xx]++;
		for(re int j=i;j<=k-2;j++)b1[a1[j]]--;
		if(xx>yy)std::swap(xx,yy);
		x[i]=xx;y[i]=yy;if(!x2[xx][yy])return;x2[xx][yy]--;
	}
	if(k>1)
	{
		for(xx=1;xx<=k;xx++)if(!b1[xx])break;b1[xx]++;
		for(yy=1;yy<=k;yy++)if(!b1[yy])break;
		x[k-1]=xx;y[k-1]=yy;if(!x2[xx][yy])return;x2[xx][yy]--;
	}
	for(re int i=1;i<=k;i++)nm[i]=std::min(n+1,ex[i+1])-ex[i]-1;
	while(bfs())
	{
		for(re int i=1;i<=k;i++)if(nm[i])nm[i]-=dfs1(i,nm[i]);
	}
	for(re int i=1;i<=k;i++)if(nm[i])return;
	for(re int i=1;i<=k;i++)nm[i]=ex[i]+1;
	for(re int i=1;i<=k-1;i++)printf("%d %d\n",ex[x[i]],ex[y[i]]);
	for(re int i=1;i<=k;i++)
	{
		for(re int j=i;j<=k;j++)
		{
			for(re int ii=1;ii<=fl[i][j][0];ii++)printf("%d %d\n",nm[i]++,ex[j]);
			for(re int ii=1;ii<=fl[i][j][1];ii++)printf("%d %d\n",nm[j]++,ex[i]);
		}
	}
	exit(0);
}
void dfs(re int i)
{
	if(i>k-2){clac();return;}
	for(a1[i]=1;a1[i]<=k;a1[i]++)dfs(i+1);
}
int main()
{
	re int x,y;
	scanf("%d",&n);
	for(re int i=1;i<n;i++)
	{
		scanf("%s",ss+1);x=strlen(ss+1);
		scanf("%s",ss+1);y=strlen(ss+1);
		if(x>y)x1[y][x]++;else x1[x][y]++;
	}
	for(ex[1]=1;n>=ex[k];k++,ex[k]=ex[k-1]*10);k--;
	dfs(1);
	puts("-1");
}