#include<bits/stdc++.h>
#define re register
#define minp(a,b) (dep[a]<dep[b]?(a):(b))
struct eg{int to;eg*nx;}e[2000100],*la[3][300100],*cnt=e;
void addE(re int ff,re int a,re int b)
{
	*++cnt=(eg){b,la[ff][a]};la[ff][a]=cnt;
	*++cnt=(eg){a,la[ff][b]};la[ff][b]=cnt;
}
int dfn[300100],bg[300100],dep[300100],lg[600100],el[21][600100],low[300100];
int tot,tt=1,in[300100],x[300100],y[300100],sta[300100],ta;
void dfs(re int a,re int fa)
{//printf("*l*l*%d %d\n",a,(la[0][a]?la[0][a]->to:-1));
	dfn[a]=low[a]=++tot;
	sta[++ta]=a;
	re int xx=0;
	for(re eg*i=la[0][a];i;i=i->nx)if(!dfn[i->to])
	{
		dfs(i->to,a);
		low[a]=std::min(low[a],low[i->to]);
	}else if(i->to!=fa||xx)low[a]=std::min(low[a],dfn[i->to]);
	else xx=1;
	if(low[a]==dfn[a])
	{//printf("***%d %d\n",a,low[a]);
		tt++;
		do
		{
			in[sta[ta]]=tt;
		}while(sta[ta--]!=a);
	}
}
int dfn1[300100],low1[300100],tta,in1[300100];
void dfsT(re int a,re int fa)
{//printf("***%d %d\n",a,fa);
	dfn1[a]=low1[a]=++tot;
	sta[++ta]=a;
	re int xx=0;
	for(re eg*i=la[2][a];i;i=i->nx)if(i->to!=1)
	{
		if(!dfn1[i->to])
		{
			dfsT(i->to,a);
			low1[a]=std::min(low1[a],low1[i->to]);
		}else if(i->to!=fa||xx)low1[a]=std::min(low1[a],dfn1[i->to]);
		else xx=1;
	}
	if(low1[a]==dfn1[a])
	{
		tta++;
		do
		{
			in1[sta[ta]]=tta;
		}while(sta[ta--]!=a);
	}
}
void dfs1(re int a,re int fa)
{//printf("***%d\n",a);
	el[0][++tot]=a;dfn[a]=tot;
	for(re eg*i=la[1][a];i;i=i->nx)if(!dfn[i->to])
	{
		dep[i->to]=dep[a]+1;
		dfs1(i->to,a);
		el[0][++tot]=a;
	}bg[a]=tot;
}
int LCA(re int a,re int b)
{
	a=dfn[a];b=dfn[b];
	if(a>b)std::swap(a,b);
	re int c=lg[b-a+1];//printf("*LCA*%d %d %d %d\n",a,b,c,lg[4]);
	return minp(el[c][a],el[c][b-(1<<c)+1]);
}
int n,cl[900100],ck[300100];
long long R;
int rotate(re int a)
{
	a=(a+R)%n;
	if(a==0)a=n;//printf("***%d\n",a);
	return a;
}
inline bool cmp(re int a,re int b){return dfn[a]<dfn[b];}
int main()
{
	re int q,m,n1;
	scanf("%d%d%d",&n,&m,&q);
	for(re int i=1;i<=m;i++)scanf("%d%d",&x[i],&y[i]),addE(0,x[i],y[i]);
	for(re int i=1;i<=n;i++)if(!dfn[i])
	{
		assert(ta==0);
		dfs(i,0);addE(1,1,in[i]);
	}
	for(re int i=1;i<=m;i++)if(in[x[i]]!=in[y[i]])
	{
		addE(1,in[x[i]],in[y[i]]);
	}
	for(re int i=1;i<=n;i++)dfn[i]=0;
	tot=0;dep[1]=1;
	dfs1(1,0);
	for(re int i=2;i<=tot;i++)lg[i]=lg[i>>1]+1;//,printf("*log*%d %d\n",i,lg[i]);
	for(re int i=1;(1<<i)<=tot;i++)
	{
		for(re int j=1;j+(1<<i)-1<=tot;j++)el[i][j]=minp(el[i-1][j],el[i-1][j+(1<<i-1)]);
	}//for(re int i=1;i<=n;i++)printf("**%d %d\n",i,in[i]);
	for(re int ii=1;ii<=q;ii++)
	{
		re eg*ctt=cnt;
		scanf("%d%d",&n1,&m);
		re int n2=n1,n3;
		for(re int i=1;i<=n1;i++)scanf("%d",&cl[i]),cl[i]=in[rotate(cl[i])],ck[i]=cl[i];
		for(re int i=1;i<=m;i++)scanf("%d%d",&x[i],&y[i]),x[i]=in[rotate(x[i])],y[i]=in[rotate(y[i])],cl[++n2]=x[i],cl[++n2]=y[i];
		std::sort(cl+1,cl+n2+1,cmp);
		n2=std::unique(cl+1,cl+n2+1)-cl-1;
		sta[ta=1]=cl[1];
		n3=n2;
		for(re int i=2;i<=n2;i++)
		{
			if(bg[sta[ta]]>=dfn[cl[i]])sta[++ta]=cl[i];
			else
			{
				re int xx=LCA(cl[i],sta[ta]);//printf("qlq%d %d %d\n",cl[i],sta[ta],xx);
				while(ta>=2&&dfn[sta[ta-1]]>dfn[xx])addE(2,sta[ta-1],sta[ta]),ta--;
				addE(2,xx,sta[ta]);ta--;
				if(dfn[sta[ta]]<dfn[xx])sta[++ta]=xx,cl[++n3]=xx;
				sta[++ta]=cl[i];
			}
		}
		for(re int i=1;i<=m;i++)addE(2,x[i],y[i]);//,printf("*k*%d %d\n",x[i],y[i]);
		while(ta>1)addE(2,sta[ta-1],sta[ta]),ta--;
		tta=0;ta=0;
		for(re int i=1;i<=n3;i++)
		if(cl[i]!=1&&!dfn1[cl[i]]){
			assert(ta==0);
			dfsT(cl[i],0);
		}//puts("***************");
		//printf("**^-^**%d %d %d %d %d\n",n1,n2,n3,in1[5],in1[3]);
		re bool bl=1;
		for(re int i=2;i<=n1;i++)bl&=(in1[ck[i]]==in1[ck[1]]);
		R+=bl*ii;
		puts(bl?"YES":"NO");
		for(re int i=1;i<=n3;i++)in1[cl[i]]=dfn1[cl[i]]=low1[cl[i]]=0,la[2][cl[i]]=0;//,printf("*l*l*%d\n",cl[i]);
		cnt=ctt;
	}
}