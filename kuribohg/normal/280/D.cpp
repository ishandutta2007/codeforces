#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=100010;
int n,m,a[MAXN];
struct Interval
{
	int sum,l,r;
	Interval(){}
	Interval(int _sum,int _l,int _r):sum(_sum),l(_l),r(_r){}
};
Interval operator+(const Interval &p,const Interval &q)
{
	Interval con;
	con.l=p.l,con.r=q.r;
	con.sum=p.sum+q.sum;
	return con;
}
Interval min(const Interval &p,const Interval &q)
{
	if(p.sum<q.sum) return p;
	else return q;
}
Interval max(const Interval &p,const Interval &q)
{
	if(p.sum<q.sum) return q;
	else return p;
}
struct Seg
{
	int l,r;
	Interval All;
	Interval lMax,rMax,Max;
	Interval lMin,rMin,Min;
	int lazy;
}T[MAXN<<2];
Seg Merge(const Seg &p,const Seg &q)
{
	Seg con;
	con.lazy=0;
	con.l=p.l,con.r=q.r;
	con.All=p.All+q.All;
	con.lMax=max(p.lMax,p.All+q.lMax);
	con.lMin=min(p.lMin,p.All+q.lMin);
	con.rMax=max(q.rMax,p.rMax+q.All);
	con.rMin=min(q.rMin,p.rMin+q.All);
	con.Max=max(max(p.Max,q.Max),p.rMax+q.lMax);
	con.Min=min(min(p.Min,q.Min),p.rMin+q.lMin);
	return con;
}
void PushDown(int x)
{
	if(!T[x].lazy) return;
	x<<=1;
	T[x].lazy^=1;
	swap(T[x].lMax,T[x].lMin);
	T[x].lMax.sum=-T[x].lMax.sum,T[x].lMin.sum=-T[x].lMin.sum;
	swap(T[x].rMax,T[x].rMin);
	T[x].rMax.sum=-T[x].rMax.sum,T[x].rMin.sum=-T[x].rMin.sum;
	swap(T[x].Max,T[x].Min);
	T[x].Max.sum=-T[x].Max.sum,T[x].Min.sum=-T[x].Min.sum;
	T[x].All.sum=-T[x].All.sum;
	x|=1;
	T[x].lazy^=1;
	swap(T[x].lMax,T[x].lMin);
	T[x].lMax.sum=-T[x].lMax.sum,T[x].lMin.sum=-T[x].lMin.sum;
	swap(T[x].rMax,T[x].rMin);
	T[x].rMax.sum=-T[x].rMax.sum,T[x].rMin.sum=-T[x].rMin.sum;
	swap(T[x].Max,T[x].Min);
	T[x].Max.sum=-T[x].Max.sum,T[x].Min.sum=-T[x].Min.sum;
	T[x].All.sum=-T[x].All.sum;
	x>>=1;
	T[x].lazy^=1;
}
void MakeTree(int x,int l,int r)
{
	T[x].l=l,T[x].r=r;
	if(l==r)
	{
		T[x].All=Interval(a[l],l,r);
		T[x].lMax=max(Interval(a[l],l,r),Interval(0,l,l-1));
		T[x].lMin=min(Interval(a[l],l,r),Interval(0,l,l-1));
		T[x].rMax=max(Interval(a[l],l,r),Interval(0,r+1,r));
		T[x].rMin=min(Interval(a[l],l,r),Interval(0,r+1,r));
		T[x].Max=T[x].lMax,T[x].Min=T[x].lMin;
		return;
	}
	int mid=(l+r)>>1;
	MakeTree(x<<1,l,mid);
	MakeTree(x<<1|1,mid+1,r);
	T[x]=Merge(T[x<<1],T[x<<1|1]);
}
void Modify(int x,int pos)
{
	if(T[x].l==T[x].r)
	{
		int l=pos,r=pos;
		T[x].All=Interval(a[l],l,r);
		T[x].lMax=max(Interval(a[l],l,r),Interval(0,l,l-1));
		T[x].lMin=min(Interval(a[l],l,r),Interval(0,l,l-1));
		T[x].rMax=max(Interval(a[l],l,r),Interval(0,r+1,r));
		T[x].rMin=min(Interval(a[l],l,r),Interval(0,r+1,r));
		T[x].Max=T[x].lMax,T[x].Min=T[x].lMin;
		return;
	}
	int mid=(T[x].l+T[x].r)>>1;
	PushDown(x);
	if(pos<=mid) Modify(x<<1,pos);
	else Modify(x<<1|1,pos);
	T[x]=Merge(T[x<<1],T[x<<1|1]);
}
void Change(int x,int l,int r)
{
	if(T[x].l==l&&T[x].r==r)
	{
		T[x].lazy^=1;
		swap(T[x].lMax,T[x].lMin);
		T[x].lMax.sum=-T[x].lMax.sum,T[x].lMin.sum=-T[x].lMin.sum;
		swap(T[x].rMax,T[x].rMin);
		T[x].rMax.sum=-T[x].rMax.sum,T[x].rMin.sum=-T[x].rMin.sum;
		swap(T[x].Max,T[x].Min);
		T[x].Max.sum=-T[x].Max.sum,T[x].Min.sum=-T[x].Min.sum;
		T[x].All.sum=-T[x].All.sum;
		return;
	}
	int mid=(T[x].l+T[x].r)>>1;
	PushDown(x);
	if(r<=mid) Change(x<<1,l,r);
	else if(l>mid) Change(x<<1|1,l,r);
	else Change(x<<1,l,mid),Change(x<<1|1,mid+1,r);
	T[x]=Merge(T[x<<1],T[x<<1|1]);
}
Seg Query(int x,int l,int r)
{
	if(T[x].l==l&&T[x].r==r) return T[x];
	int mid=(T[x].l+T[x].r)>>1;
	PushDown(x);
	if(r<=mid) return Query(x<<1,l,r);
	else if(l>mid) return Query(x<<1|1,l,r);
	else return Merge(Query(x<<1,l,mid),Query(x<<1|1,mid+1,r));
}
int Q,L[31],R[31];
int op,pos,tar,l,r,k;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	MakeTree(1,1,n);
	scanf("%d",&Q);
	while(Q--)
	{
		scanf("%d",&op);
		if(op==0)
		{
			scanf("%d%d",&pos,&tar);
			a[pos]=tar;
			Modify(1,pos);
		}
		else
		{
			int con=0;
			scanf("%d%d%d",&l,&r,&k);
			for(int i=1;i<=k;i++)
			{
				Seg tmp=Query(1,l,r);
				con+=tmp.Max.sum;
				if(tmp.Max.l>tmp.Max.r) {L[i]=-1,R[i]=-1;continue;}
				L[i]=tmp.Max.l,R[i]=tmp.Max.r;
				Change(1,L[i],R[i]);
			}
			printf("%d\n",con);
			for(int i=1;i<=k;i++) if(L[i]!=-1) Change(1,L[i],R[i]);
		}
	}
	return 0;
}