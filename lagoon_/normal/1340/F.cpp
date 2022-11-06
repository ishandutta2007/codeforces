#include<bits/stdc++.h>
#define re register
unsigned long long base,el[100100];
int n,k;
struct nd
{
	unsigned long long hs;
	int vl,sz;
	nd*l,*r;
	void pu(){hs=(l?l->hs:0)+(l?el[l->sz]:1)*(1llu*vl+(r?r->hs:0)*base);sz=(l?l->sz:0)+(r?r->sz:0)+1;}
}nn[10801000],*cnt=nn;
std::mt19937 rad(time(0));
nd*meg(re nd*a,re nd*b)
{
	if(!a)return b;
	if(!b)return a;
	if((unsigned int)rad()%(a->sz+b->sz)<a->sz)
	{
		*++cnt=*a;re nd*nn=cnt;
		nn->r=meg(nn->r,b);nn->pu();return nn;
	}else
	{
		*++cnt=*b;re nd*nn=cnt;
		nn->l=meg(a,nn->l);nn->pu();return nn;
	}
}
std::pair<nd*,nd*>split(re nd*a,re int k)
{
	if(!a)return std::make_pair(a,a);
	std::pair<nd*,nd*>nw;
	if(k==0||(a->l&&a->l->sz>=k))
	{
		re nd*nn=++cnt;*nn=*a;
		nw=split(a->l,k);
		nn->l=nw.second;nn->pu();nw.second=nn;
		return nw;
	}
	if(a->l)k-=a->l->sz;
	k--;
	re nd*nn=++cnt;*nn=*a;
	nw=split(a->r,k);
	nn->r=nw.first;nn->pu();nw.first=nn;
	return nw;
}
int aa[100100];
bool exn;
struct seg
{
	nd*left,*right;
	void reset(re int i)
	{
		left=right=0;
		if(aa[i]>0)*++cnt=(nd){1llu*aa[i],1llu*aa[i],1},left=cnt;
		else *++cnt=(nd){1llu*-aa[i],1llu*-aa[i],1},right=cnt;
	}
	seg operator + (const seg&A)
	{
		seg c=(seg){A.left,right};
		if(!left){c.right=meg(A.right,c.right);return c;}
		else if(!A.right){c.left=meg(left,c.left);return c;}
		if(left->sz>=A.right->sz)
		{
			std::pair<nd*,nd*>nw=split(left,left->sz-A.right->sz);
			if(nw.second->hs!=A.right->hs)
			{//printf("*****%llu %llu %llu\n",left->vl,nw.second->hs,A.right->hs);
				exn=1;return (seg){0,0};
			}
			else
			{
				c.left=meg(nw.first,c.left);
				return c;
			}
		}
		else
		{
			std::pair<nd*,nd*>nw=split(A.right,A.right->sz-left->sz);
			if(nw.second->hs!=left->hs)
			{
				exn=1;return (seg){0,0};
			}
			else
			{
				c.right=meg(nw.first,c.right);
				return c;
			}
		}
	}
}ff[400100],nnw;
bool exl[401000];
void pu(re int i)
{
	if(exl[i*2]||exl[i*2+1])exl[i]=1;
	else
	{
		exn=0;
		ff[i]=ff[i*2]+ff[i*2+1];exl[i]=exn;
	}
}
void build(re int i,re int l,re int r)
{
	if(l==r){ff[i].reset(l);return;}
	re int mid=(l+r)/2;
	build(i*2,l,mid);
	build(i*2+1,mid+1,r);
	pu(i);
}
int l1,r1;
void add(re int i,re int l,re int r)
{
	if(r<l1||l>l1)return;
	if(l==r){ff[i].reset(l);return;}
	re int mid=(l+r)/2;
	add(i*2,l,mid);
	add(i*2+1,mid+1,r);
	pu(i);
}
void qry(re int i,re int l,re int r)
{
	if(r<l1||l>r1)return;
	if(l>=l1&&r<=r1){exn|=exl[i];if(!exn)nnw=nnw+ff[i];/*printf("***%d %d %d %d %d %d\n",i,l,r,(nnw.left?nnw.left->sz:0),(nnw.right?nnw.right->sz:0),exn);*/return;}
	re int mid=(l+r)/2;
	qry(i*2,l,mid);
	qry(i*2+1,mid+1,r);
}
int main()
{
	srand(time(0));
	scanf("%d%d",&n,&k);
	base=rand()+k+10;el[0]=1;
	for(re int i=1;i<=n;i++)el[i]=el[i-1]*base,scanf("%d",&aa[i]);
	re int q,no,x,y;
	scanf("%d",&q);
	build(1,1,n);
	for(;q--;)
	{
		scanf("%d%d%d",&no,&x,&y);
		if(no==1)
		{
			l1=x;aa[x]=y;add(1,1,n);
		}else
		{
			re nd*nk=cnt;
			l1=x;r1=y;exn=0;nnw=(seg){0,0};
			qry(1,1,n);
			if(!exn&&!nnw.left&&!nnw.right)puts("Yes");
			else puts("No");
			cnt=nk;
		}
		if(q>0&&!(q%33334))
		{
			cnt=nn;build(1,1,n);
		}
	}
}