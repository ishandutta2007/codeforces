#include<bits/stdc++.h>
#define re register
struct par{int l,l1,r1,no;}ss[2001000];
int x[200100],y[200100],x1[200100],y1[200100];
inline bool cmp(const par&A,const par&B){return A.l==B.l?A.no>B.no:A.l<B.l;}
std::pair<int,int> pq1[2001000],pq2[2001000];
bool in[2001000];
int main()
{
	re int n,cnt=0,ta1=0,ta2=0;
	scanf("%d",&n);
	for(re int i=1;i<=n;i++)
	{
		scanf("%d%d%d%d",&x[i],&y[i],&x1[i],&y1[i]);
		ss[++cnt]=(par){x[i],x1[i],y1[i],i};
		ss[++cnt]=(par){y[i],x1[i],y1[i],-i};
	}
	std::sort(ss+1,ss+cnt+1,cmp);
	for(re int i=1;i<=cnt;i++)
	{
		if(ss[i].no>0)
		{
			in[ss[i].no]=1;
			pq1[++ta1]=std::make_pair(ss[i].l1,ss[i].no);
			pq2[++ta2]=std::make_pair(-ss[i].r1,ss[i].no);
			std::push_heap(pq1+1,pq1+ta1+1);
			std::push_heap(pq2+1,pq2+ta2+1);
		}
		else
		{
			in[-ss[i].no]=0;
			while(ta1&&!in[pq1[1].second])std::pop_heap(pq1+1,pq1+ta1+1),ta1--;
			while(ta2&&!in[pq2[1].second])std::pop_heap(pq2+1,pq2+ta2+1),ta2--;
			if(ss[i].l1>-pq2[1].first||ss[i].r1<pq1[1].first)puts("NO"),exit(0);
		}
	}
	ta1=ta2=cnt=0;
	for(re int i=1;i<=n;i++)
	{
		ss[++cnt]=(par){x1[i],x[i],y[i],i};
		ss[++cnt]=(par){y1[i],x[i],y[i],-i};
		in[i]=0;
	}
	std::sort(ss+1,ss+cnt+1,cmp);
	for(re int i=1;i<=cnt;i++)
	{
		if(ss[i].no>0)
		{
			in[ss[i].no]=1;
			pq1[++ta1]=std::make_pair(ss[i].l1,ss[i].no);
			pq2[++ta2]=std::make_pair(-ss[i].r1,ss[i].no);
			std::push_heap(pq1+1,pq1+ta1+1);
			std::push_heap(pq2+1,pq2+ta2+1);
		}
		else
		{
			in[-ss[i].no]=0;
			while(ta1&&!in[pq1[1].second])std::pop_heap(pq1+1,pq1+ta1+1),ta1--;
			while(ta2&&!in[pq2[1].second])std::pop_heap(pq2+1,pq2+ta2+1),ta2--;
			if(ss[i].l1>-pq2[1].first||ss[i].r1<pq1[1].first)puts("NO"),exit(0);
		}
	}
	puts("YES");
}