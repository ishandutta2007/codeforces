#include<bits/stdc++.h>
#define re register
struct seg{int v,no;seg*l,*r;}sg[4000000],*cct=sg;
struct nd{int mx;seg*no;nd*la[20],*nx[26];}nc[200100],*lc[500100],*nw=nc,*cnt=nc;
void pu(re seg*a)
{
	if(a->l&&((!a->r)||a->l->v>=a->r->v))a->v=a->l->v,a->no=a->l->no;
	else a->v=a->r->v,a->no=a->r->no;
}
int I,m;
void ads(re seg*&a,re int l,re int r)
{
	if(!a)a=++cct,a->no=l;
	if(l==r){a->v++;return;}
	re int mid=(l+r)/2;
	if(I<=mid)ads(a->l,l,mid);
	else ads(a->r,mid+1,r);
	pu(a);
}
seg*meg(re seg*a,re seg*b)
{
	if(!a)return b;
	if(!b)return a;
	re seg*nw=++cct;
	if((!a->l)&&(!a->r))
	{
		nw->v=a->v+b->v;
		nw->no=a->no;
		return nw;
	}
	nw->l=meg(a->l,b->l);
	nw->r=meg(a->r,b->r);
	pu(nw);
	return nw;
}
void add(re int a)
{
	re nd*p=nw,*q;
	if(q=nw->nx[a])
	{
		if(q->mx==nw->mx+1)nw=q;
		else
		{
			*++cnt=(nd){p->mx+1,0};
			cnt->la[0]=q->la[0];
			nw=q->la[0]=cnt;
			memcpy(cnt->nx,q->nx,26*sizeof(nd*));
			for(;p&&p->nx[a]==q;p=p->la[0])p->nx[a]=cnt;
		}
		ads(nw->no,1,m);
		return;
	}
	nw=++cnt;cnt->mx=p->mx+1;
	cnt->no=0;
	for(;p&&!p->nx[a];p=p->la[0])p->nx[a]=cnt;
	if(!p)cnt->la[0]=nc;
	else
	{
		q=p->nx[a];
		if(q->mx==p->mx+1)cnt->la[0]=q;
		else
		{
			*++cnt=(nd){p->mx+1,0},cnt->la[0]=q->la[0];
			q->la[0]=cnt;nw->la[0]=cnt;
			memcpy(cnt->nx,q->nx,26*sizeof(nd*));
			for(;p&&p->nx[a]==q;p=p->la[0])p->nx[a]=cnt;
		}
	}
	ads(nw->no,1,m);
}
char ss[500100],s1[50010];
int d[100100],q1[100100],lk[500100],nwno,nwans,ll,rr;
void qry(re seg*a,re int l,re int r)
{
	if(!a)return;
	if(l>=ll&&r<=rr){if(a->v>nwans)nwans=a->v,nwno=a->no;return;}
	re int mid=(l+r)/2;
	if(ll<=mid)qry(a->l,l,mid);
	if(rr>mid)qry(a->r,mid+1,r);
}
int main()
{
	re int n,q,n1,ta=0;
	scanf("%s%d",ss+1,&m);
	n=strlen(ss+1);
	for(re int i=1;i<=m;i++)
	{
		scanf("%s",s1+1);n1=strlen(s1+1);I=i;
		for(re int j=1;j<=n1;j++)add(s1[j]-'a');
		nw=nc;
	//printf("***%d %d %d\n",i,cnt-nc,cct-sg);
	}
	for(re int i=1;i<=cnt-nc;i++)
	{
		d[nc[i].la[0]-nc]++;
	}
	for(re int i1=1;(1<<i1)<=n;i1++)
	{
		for(re int i=1;i<=cnt-nc;i++)
			if(nc[i].la[i1-1])nc[i].la[i1]=nc[i].la[i1-1]->la[i1-1];
			else nc[i].la[i1]=0;
	}
	for(re int i=1;i<=cnt-nc;i++)if(!d[i])q1[++ta]=i;
	for(re int i=1;i<=ta;i++)
	{
		re int x=q1[i];
		if(!x)continue;
		nc[x].la[0]->no=meg(nc[x].la[0]->no,nc[x].no);
		if((--d[nc[x].la[0]-nc])==0)q1[++ta]=nc[x].la[0]-nc;
	}
	re nd*nk=nc;
	for(re int i=1;i<=n;i++)
	{
		for(;nk&&!nk->nx[ss[i]-'a'];nk=nk->la[0]);
		if(!nk)nk=nc,lk[i]=0;
		else lk[i]=std::min(lk[i-1],nk->mx)+1,nk=nk->nx[ss[i]-'a'];
		lc[i]=nk;
	}
	scanf("%d",&q);
	for(re int i=1;i<=q;i++)
	{
		re int l1,r1;
		scanf("%d%d%d%d",&ll,&rr,&l1,&r1);
		if(lk[r1]<r1-l1+1)printf("%d %d\n",ll,0);
		else
		{
			nk=lc[r1];
			for(re int j=19;j>=0;j--)if(nk->la[j]&&nk->la[j]->mx>=r1-l1+1)nk=nk->la[j];
			nwno=ll;nwans=0;
			qry(nk->no,1,m);
			//if(i==210)printf("***%d %d %d %d %d %d %d %d %d %d %d\n",i,l1,r1,ll,rr,nk->mx,nk->la[0]->mx,nk->no->no,nk->no->v,nk->no->l->no,nk->no->l->v);
			printf("%d %d\n",nwno,nwans);
		}
	}
}