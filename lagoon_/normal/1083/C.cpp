#include<bits/stdc++.h>
using namespace std;
#define re register
#define mind(a,b) (d[a]<d[b]?(a):(b))
int p[200100],q[200100],d[200100],eul[20][400100],bg[200100],lg[400100],eu;
struct eg{int to;eg*nx;}e[400100],*la[200100],*cnt=e;
inline int lca(re int a,re int b)
{
	a=bg[a];b=bg[b];if(a>b)swap(a,b);
	re int c=lg[b-a+1];return mind(eul[c][a],eul[c][b-(1<<c)+1]);
}
inline void addE(re int a,re int b)
{
	*++cnt=(eg){b,la[a]};la[a]=cnt;
	*++cnt=(eg){a,la[b]};la[b]=cnt;
}
void dfs(re int a,re int fa)
{
	eul[0][++eu]=a;bg[a]=eu;
	for(re eg*i=la[a];i;i=i->nx)
	if(!d[i->to]){d[i->to]=d[a]+1;dfs(i->to,a);eul[0][++eu]=a;}
}
int a1[800100][2],ca[2],cca[2],aca[4],l1,ta;
inline bool in(re int a,re int b,re int c)
{
	return (lca(a,c)==c||lca(b,c)==c)&&(lca(c,lca(a,b))==lca(a,b));
}
inline void mg(re int*aa,re int*a2,re int*a3)
{
	if((*a2)==-1||(*a3)==-1){aa[0]=aa[1]=-1;return;}
	if((*a2)==-2){aa[0]=a3[0];aa[1]=a3[1];return;}
	aca[0]=a2[0];aca[1]=a2[1];aca[2]=a3[0];aca[3]=a3[1];
	for(re int i=0;i<=3;i++)for(re int j=i+1;j<=3;j++)
	{
		re bool bo=1;for(re int k=0;k<=3;k++)if(k!=i&&k!=j&&!in(aca[i],aca[j],aca[k])){bo=0;break;}
		if(bo){aa[0]=aca[i];aa[1]=aca[j];return;}
	}aa[0]=aa[1]=-1;return;
}
inline void pu(re int a)
{
	mg(a1[a],a1[a*2],a1[a*2+1]);
}
void build(re int i,re int l,re int r)
{
	if(l==r){a1[i][0]=a1[i][1]=p[l];return;}
	re int mid=(l+r)/2;
	build(i*2,l,mid);build(i*2+1,mid+1,r);
	pu(i);
}
void add(re int i,re int l,re int r)
{
	if(l==r){a1[i][0]=a1[i][1]=p[l];return;}
	re int mid=(l+r)/2;
	if(l1<=mid)add(i*2,l,mid);
	else add(i*2+1,mid+1,r);//printf("*a*%d %d\n",l,r);
	pu(i);
}
int qus(re int i,re int l,re int r)
{
	if(l==r){mg(cca,ca,a1[i]);if(cca[0]!=-1)return l;else return l-1;}
	re int mid=(l+r)/2;
	mg(cca,ca,a1[i*2]);//printf("*****%d %d %d %d %d %d %d %d %d %d %d\n",i,l,r,cca[0],cca[1],ca[0],ca[1],lca(1,2),lca(5,2),eul[2][5];
	if(cca[0]!=-1){ca[0]=cca[0];ca[1]=cca[1];return qus(i*2+1,mid+1,r);}
	else return qus(i*2,l,mid);
}
int main()
{
	re int n,m,t,x,y;
	scanf("%d",&n);
	for(re int i=1;i<=n;i++)scanf("%d",&q[i]),q[i]++,p[q[i]]=i;
	for(re int i=2;i<=n;i++)
	{
		scanf("%d",&x);
		addE(x,i);
	}
	d[1]=1;dfs(1,0);for(re int i=2;i<=eu;i++)lg[i]=lg[i/2]+1;
	for(re int i=1;(1<<i)<=eu;i++)
		for(re int j=1;j+(1<<i)<=eu+1;j++)
			eul[i][j]=mind(eul[i-1][j],eul[i-1][j+(1<<(i-1))]);
	build(1,1,n);
	scanf("%d",&m);
	for(;m--;)
	{
		scanf("%d",&t);
		if(t==1)
		{
			scanf("%d%d",&x,&y);
			swap(p[q[x]],p[q[y]]);
			swap(q[x],q[y]);
			l1=q[x];add(1,1,n);
			l1=q[y];add(1,1,n);
		}
		else
		{
			ca[0]=ca[1]=-2;
			printf("%d\n",qus(1,1,n));
		}
	}
}