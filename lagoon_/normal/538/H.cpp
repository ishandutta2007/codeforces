#include<bits/stdc++.h>
#define re register
struct eg{int to;eg*nx;}e[200100],*la[100100],*cnt=e;
inline void addE(re int a,re int b)
{
	*++cnt=(eg){b,la[a]};la[a]=cnt;
	*++cnt=(eg){a,la[b]};la[b]=cnt;
}
int aa[200100],l[100100],r[100100],bl[100100],vis[100100],n,tot,cct,cmt,l1,r1,l2,r2,ll[100100][2],rr[100100][2];
bool in[100100][2],cho[100100];
int qmt;
struct par{int x,no,in;}pp[400100];
void dfs(re int a)
{
	bl[a]=cct;
	if(vis[a]==2)l1=std::max(l1,l[a]),r1=std::min(r1,r[a]);
	else l2=std::max(l2,l[a]),r2=std::min(r2,r[a]);
	for(re eg*i=la[a];i;i=i->nx)if(!vis[i->to])
	{
		vis[i->to]=vis[a]^1;dfs(i->to);
	}else if(vis[i->to]==vis[a]){puts("IMPOSSIBLE");exit(0);}
}
int ff[800100],f1[800100],tg[800100],x1;
void build(re int i,re int l,re int r)
{
	f1[i]=l;
	if(l==r)return;
	re int mid=(l+r)/2;
	build(i*2,l,mid);
	build(i*2+1,mid+1,r);
}
void pu(re int i){if(ff[i*2]>=ff[i*2+1])ff[i]=ff[i*2],f1[i]=f1[i*2];else ff[i]=ff[i*2+1],f1[i]=f1[i*2+1];}
void ad1(re int i,re int v){ff[i]+=v;tg[i]+=v;}
void pd(re int i)
{
	if(tg[i])
	{
		ad1(i*2,tg[i]);ad1(i*2+1,tg[i]);
		tg[i]=0;
	}
}
void add(re int i,re int l,re int r)
{//printf("*****%d %d %d %d %d\n",i,l,r,ff[i],f1[i]);
	if(l>=l1&&r<=r1){ad1(i,x1);return;}
	pd(i);
	re int mid=(l+r)/2;
	if(l1<=mid)add(i*2,l,mid);
	if(r1>mid)add(i*2+1,mid+1,r);
	pu(i);
}
void qry(re int i,re int l,re int r)
{
	if(l>=l1&&r<=r1){if(ff[i]==cct)x1=f1[i];return;}
	pd(i);
	re int mid=(l+r)/2;
	if(l1<=mid)qry(i*2,l,mid);
	if(r1>mid)qry(i*2+1,mid+1,r);
}
void adk(re int i)
{
	if(in[i][0]&&in[i][1])
	{
		if(ll[i][0]<=rr[i][1]&&ll[i][1]<=rr[i][0])
		{
			l1=std::min(ll[i][0],ll[i][1]);
			r1=std::max(rr[i][0],rr[i][1]);
			add(1,1,cmt);
		}else
		{
			l1=ll[i][0];r1=rr[i][0];
			add(1,1,cmt);
			l1=ll[i][1];r1=rr[i][1];
			add(1,1,cmt);
		}
	}else if(in[i][0])
	{
		l1=ll[i][0];r1=rr[i][0];add(1,1,cmt);
	}else if(in[i][1])
	{
		l1=ll[i][1];r1=rr[i][1];add(1,1,cmt);
	}
}
inline bool cmp(const par&A,const par&B){return A.x<B.x;}
int main()
{
	re int t,T,m,x,y;
	scanf("%d%d%d%d",&t,&T,&n,&m);
	for(re int i=1;i<=n;i++)scanf("%d%d",&l[i],&r[i]),aa[++cmt]=l[i],aa[++cmt]=r[i]+1;
	aa[++cmt]=1e9+1;aa[++cmt]=0;
	for(re int i=1;i<=m;i++)scanf("%d%d",&x,&y),addE(x,y);
	std::sort(aa+1,aa+cmt+1);
	cmt=std::unique(aa+1,aa+cmt+1)-aa-1;
	aa[cmt+1]=1e9+2;
	for(re int i=1;i<=n;i++)l[i]=std::lower_bound(aa+1,aa+cmt+1,l[i])-aa,r[i]=std::lower_bound(aa+1,aa+cmt+1,r[i]+1)-aa-1;
	for(re int i=1;i<=n;i++)if(!vis[i])
	{
		cct++;
		l1=1;r1=cmt;l2=1;r2=cmt;
		vis[i]=2;dfs(i);
		ll[cct][0]=l1;rr[cct][0]=r1;
		ll[cct][1]=l2;rr[cct][1]=r2;
		//printf("***%d %d %d %d\n",l1,r1,l2,r2);
		pp[++qmt]=(par){aa[l1],cct,1};
		pp[++qmt]=(par){aa[r1+1],cct,1};
		pp[++qmt]=(par){aa[l2],cct,0};
		pp[++qmt]=(par){aa[r2+1],cct,0};
		if(l1>r1||l2>r2){puts("IMPOSSIBLE");return 0;}
	}
	build(1,1,cmt);
	std::sort(pp+1,pp+qmt+1,cmp);
	for(re int i=1;i<=qmt;i++)
	{
		x=pp[i].no,y=pp[i].in;
		x1=-1;
		adk(x);
		in[x][y]^=1;
		x1=1;
		adk(x);
		if(i==qmt||pp[i].x==pp[i+1].x)continue;
		l1=std::upper_bound(aa+1,aa+cmt+1,t-pp[i+1].x+1)-aa-1;
		if(!l1)l1++;
		r1=std::upper_bound(aa+1,aa+cmt+1,T-pp[i].x)-aa-1;
		//printf("******%d %d %d %d\n",ff[1],f1[1],l1,r1);
		//printf("**%d %d %d %d %d %d %d %d %d\n",pp[i].x,l1,r1,in[1][0],in[1][1],in[2][0],in[2][1],in[3][0],in[3][1]);
		if(l1<=r1)
		{
			x1=-1;
			qry(1,1,cmt);
			if(x1!=-1)
			{
				puts("POSSIBLE");
				re int kk,kk1;
				if(aa[x1]<t-pp[i+1].x+1)kk1=t-pp[i+1].x+1;
				else kk1=aa[x1];
				if(t-kk1>pp[i].x)kk=t-kk1;
				else kk=pp[i].x;
				for(re int i1=1;i1<=cct;i1++)
				{
					if(aa[ll[i1][0]]<=kk&&aa[rr[i1][0]+1]>kk&&aa[ll[i1][1]]<=kk1&&aa[rr[i1][1]+1]>kk1)
						cho[i1]=0;
					else cho[i1]=1;
				}//printf("**********%d %d %d %d %d %d %d\n",x1,aa[x1],cho[4],
				//aa[ll[4][0]],aa[rr[4][0]],aa[ll[4][1]],aa[rr[4][1]]);
				printf("%d %d\n",kk,kk1);
				for(re int i=1;i<=n;i++)putchar((vis[i]-2)==cho[bl[i]]?'1':'2');puts("");
				return 0;
			}
		}
	}
	puts("IMPOSSIBLE");
}