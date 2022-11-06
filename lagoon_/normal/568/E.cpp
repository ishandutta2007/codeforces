#include<bits/stdc++.h>
#define re register
int p[100100],la[100100],len[100100],nx[100100],nm[100100],p1[100100],pp[200100],pa[100100],x1,pk[200100],m,bg[100100];
std::vector<int>pq[200100];
bool bo[100100];
void dfs(re int i,re int x,re int lim)
{
	lim=p1[std::lower_bound(p1+1,p1+m+1,lim)-p1-1];
	if(!i)return;
	if(i==1){if(p[x]==-1)p[x]=1;return;}
	if(p[x]!=-1)dfs(i-1,la[x],p[x]);
//printf("*p1*%d %d %d\n",i,x,p[x]);
	else
	{
		if(pq[i-1].size()==0||*pq[i-1].begin()>x)
		{
			dfs(i-1,bg[x],lim);p[x]=nx[p[bg[x]]];
//printf("*pp1*%d %d %d\n",x,p[x],p[bg[x]]);
		}else
		{
			re int xx=*(std::upper_bound(pq[i-1].begin(),pq[i-1].end(),x)-1);
//printf("**%d %d %d %d %d\n",i,x,xx,*std::lower_bound(pq[i-1].begin(),pq[i-1].end(),x),*pq[i-1].begin());
			if(lim<=p[xx])dfs(i-1,bg[x],lim),p[x]=nx[p[bg[x]]];
			else dfs(i-1,xx,lim),p[x]=pa[xx];
//printf("*pp2*%d %d %d %d\n",x,p[x],p[xx],pa[xx]);
		}
//printf("*p2*%d %d %d\n",i,x,p1[p[x]]);
	}
}
int main()
{
	re int n,x1=0,ta=0,i1,x,xx;
	scanf("%d",&n);
	for(re int i=1;i<=n;i++)scanf("%d",&p[i]);
	scanf("%d",&m);
	for(re int i=1;i<=m;i++){scanf("%d",&p1[i]);}
	std::sort(p1+1,p1+m+1);
	nx[m]=m+1;
	for(re int i=m;i>1;i--)if(p1[i]==p1[i-1])nx[i-1]=nx[i];else nx[i-1]=i;
	for(re int i=1;i<=n;i++)if(p[i]!=-1)pa[i]=std::upper_bound(p1+1,p1+m+1,p[i])-p1;
	for(re int i=1;i<=n;i++)
	{
		if(p[i]==-1)
		{
			pk[++x1]=i;bg[i]=pk[x1-1];
			re int qw=ta;
			for(re int j=m;j;j--)
			{
				while(qw&&pp[qw]>=p1[j])qw--;qw++;
				pp[qw]=p1[j];ta=std::max(qw,ta);nm[qw]=i;
				while(j>1&&p1[j]==p1[j-1])j--;
			}
		}else
		{
			if(pp[ta]<p[i])pp[++ta]=p[i],nm[ta]=i,len[i]=ta,la[i]=nm[ta-1];
			else
			{
				re int pc=(std::lower_bound(pp+1,pp+ta+1,p[i]))-pp;
				pp[pc]=p[i];nm[pc]=i;len[i]=pc;la[i]=nm[pc-1];
			}
			if(pq[len[i]].size()==0||p[i]<p[*(pq[len[i]].end()-1)]){pq[len[i]].push_back(i);}
		}
	}
	dfs(ta,nm[ta],1e9+1);
	for(re int i=1;i<=x1;i++)if(p[pk[i]]!=-1)bo[p[pk[i]]]=1,p[pk[i]]=p1[p[pk[i]]];
	re int tt=1;
	for(re int i=1;i<=x1;i++)if(p[pk[i]]==-1){while(bo[tt])tt++;p[pk[i]]=p1[tt];bo[tt]=1;}
	for(re int i=1;i<=n;i++)printf("%d ",p[i]);
	puts("");
}