#include<bits/stdc++.h>
#define re register
struct seg{seg*l,*r;}fk[12001000],*cc=fk;
struct nd{int mx,cx;nd*nx[26],*la;seg*no;}nc[500100],*cnt=nc,*nw=nc;
int n,m,I,d[400100];
char ss[200100];
void mdf(re seg*&i,re int l,re int r,re int a)
{
	if(!i)i=cc++;
	if(l==r)return;
	re int mid=(l+r)/2;
	if(a<=mid)mdf(i->l,l,mid,a);
	else mdf(i->r,mid+1,r,a);//printf("*k*%d %d %d %d %d\n",i-fk,i->l-fk,i->r-fk,l,r);
}
seg*meg(re seg*l,re seg*r)
{//printf("**%d %d %d\n",l->r-fk,r->r-fk,cc-fk+1);
	if(!l)return r;
	if(!r)return l;
	re seg*aa=cc++;
	aa->l=meg(l->l,r->l);aa->r=meg(l->r,r->r);
	return aa;
}
void add(re int a)
{
	re nd*p,*q;
	p=nw;nw=++cnt;nw->mx=p->mx+1;
	for(;p&&!p->nx[a];p=p->la)p->nx[a]=nw;
	if(p)
	{
		q=p->nx[a];
		if(q->mx==p->mx+1)nw->la=q;
		else
		{
			cnt++;
			memcpy(cnt->nx,q->nx,sizeof(cnt->nx));
			cnt->mx=p->mx+1;cnt->la=q->la;q->la=cnt;cnt->cx=q->cx;
			nw->la=cnt;
			for(;p&&p->nx[a]==q;p=p->la)p->nx[a]=cnt;
		}
	}else nw->la=nc;
	nw->cx=I;
	mdf(nw->no,1,n,I);
}
int q[500100],f[500100],ff[500100],ta,ll;
void find(re seg*i,re int l,re int r)
{//printf("**%d %d %d %d\n",i-fk,l,r,I);
	if(!i||I||l>ll)return;
	if(l==r){I=l;return;}
	re int mid=(l+r)/2;
	find(i->r,mid+1,r);
	find(i->l,l,mid);
}
int main()
{
	scanf("%d%s",&n,ss+1);
	re int ans=1;
	for(I=1;I<=n;I++)add(ss[I]-'a');
	for(re nd*i=nc+1;i<=cnt;i++)d[i->la-nc]++;
	for(re int i=1;i<=cnt-nc;i++)if(!d[i])q[++ta]=i;
	for(re int i=1;i<=ta;i++)
	{
		re int x=q[i];
		if(x==0)continue;
		d[nc[x].la-nc]--;
		nc[x].la->no=meg(nc[x].la->no,nc[x].no);
		if(!d[nc[x].la-nc])q[++ta]=nc[x].la-nc;
	}
	for(re int i=ta;i;i--)
	{
		re int x=q[i];
		re nd*x1=nc+x,*x2;
		if(x1->la==nc)f[x]=1,ff[x]=x;
		if(x==0||x1->la==nc)continue;
		f[x]=f[x1->la-nc];ff[x]=ff[x1->la-nc];
		x2=ff[x]+nc;I=0;ll=x1->cx-1;
		find(x2->no,1,n);//printf("*j*%d %d %d %d %d\n",I,x,ff[x],ll,x2->no->r-fk);
		if(I-x2->mx+1>=x1->cx-x1->mx+1)f[x]++,ff[x]=x;
		if(f[x]>ans)ans=f[x];
	}
	printf("%d\n",ans);
	return 0;
}