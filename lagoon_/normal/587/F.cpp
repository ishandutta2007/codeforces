#include<bits/stdc++.h>
#define re register
char ss[100200];
const int B=316;
int fa[100100],nx[100100][26],la[100100],nd[100100],po[100100],len[100100],ff[100100][400],cct,cnt=1,cn;
int q[100100],ta;
long long ff1[400];
struct eg{int to;eg*nx;}e[200100],*ll[100100],*cqt=e;
inline void addE(re int a,re int b){*++cqt=(eg){b,ll[a]};ll[a]=cqt;}
long long ans[100100];
int dfn[100100],ed[100100],pc[100100],pc1[100100],tot;
void dfs(re int a)
{
	dfn[a]=++tot;
	for(re eg*i=ll[a];i;i=i->nx)
	{
		dfs(i->to);
		for(re int j=1;j<=cn;j++)ff[a][j]+=ff[i->to][j];
	}
	ed[a]=tot;
}
struct par{int l,x,no,as;}pk[200100];
inline bool cmp(const par&A,const par&B){return A.l<B.l;}
void add(re int a,re int ad)
{//printf("***%d %d\n",a,ad);
	re int a1=(a-1)/B+1;
	for(re int i=a1;i*B<=tot;i++)pc1[i]+=ad;
	for(re int i=a;i<a1*B;i++)pc[i]+=ad;
}
int qry(re int a){return pc1[a/B]+pc[a];}
int main()
{
	re int n,q1,l,r,k;
	scanf("%d%d",&n,&q1);
	for(re int i=1;i<=n;i++)
	{
		scanf("%s",ss+1);
		len[i]=strlen(ss+1);
		re int j1=1;
		for(re int j=1;j<=len[i];j++)
		{
			if(!nx[j1][ss[j]-'a'])nx[j1][ss[j]-'a']=++cnt,fa[cnt]=j1;
			j1=nx[j1][ss[j]-'a'];
		}
		po[i]=j1;
		if(len[i]>=B){cn++;nd[i]=cn;for(re int j=po[i];j;j=fa[j])ff[j][cn]++;}
	}
	q[ta=1]=1;
	for(re int i=1;i<=ta;i++)
	{
		re int x=q[i];
		if(x!=1)addE(la[x],x);
		for(re int j=0;j<26;j++)if(nx[x][j])
		{
			re int y=nx[x][j];
			q[++ta]=y;
			if(x!=1)la[y]=nx[la[x]][j];
			else la[y]=1;
		}else if(x!=1)nx[x][j]=nx[la[x]][j];
		else nx[x][j]=1;
	}
	dfs(1);
	for(re int i=1;i<=q1;i++)
	{
		scanf("%d%d%d",&l,&r,&k);
		pk[++cct]=(par){l-1,k,i,-1};
		pk[++cct]=(par){r,k,i,1};
	}
	std::sort(pk+1,pk+cct+1,cmp);
	re int j1=1;
	for(re int i=1;i<=cct;i++)
	{
		while(j1<=n&&pk[i].l>=j1)
		{//printf("**********%d %d\n",po[j1],ff[po[j1]][4]);
			for(re int i1=1;i1<=cn;i1++)ff1[i1]+=ff[po[j1]][i1];
			add(dfn[po[j1]],1);add(ed[po[j1]]+1,-1);
			j1++;
		}
		if(nd[pk[i].x])
		{
			ans[pk[i].no]+=ff1[nd[pk[i].x]]*pk[i].as;
		}else
		{
			for(re int j=po[pk[i].x];j!=1;j=fa[j])ans[pk[i].no]+=qry(dfn[j])*pk[i].as;
			//printf("**%d %d %lld\n",pk[i].no,pk[i].as,ans[pk[i].no]);
		}
	}
	for(re int i=1;i<=q1;i++)printf("%lld\n",ans[i]);
}