#include<cstdio>
#include<cmath>
#include<algorithm>
#include<vector>
using std::max;
using std::swap;
using std::sort;
using std::lower_bound;
using std::unique;
using std::vector;
const int N=1e6+5;
struct update
{
	int pos,x;
}up[N];
struct query
{
	int id,l,r,x;
}q[N];
int n,Q;
int tot_up,tot_q;
int a[N],block[N];
int cnt[N],cc[N];
int have[N];
int res[N];
vector<int> V;
inline bool cmp(query a,query b)
{
	if(block[a.l]!=block[b.l])
		return block[a.l]<block[b.l];
	if(block[a.r]!=block[b.r])
		return block[a.r]<block[b.r];
	return a.x<b.x;
}
inline void add(int i)
{
	if(!--cc[cnt[a[i]]])
		have[block[cnt[a[i]]]]++;
	cnt[a[i]]++;
	if(!cc[cnt[a[i]]]++)
		have[block[cnt[a[i]]]]--;
	return;
}
inline void del(int i)
{
	if(!--cc[cnt[a[i]]])
		have[block[cnt[a[i]]]]++;
	cnt[a[i]]--;
	if(!cc[cnt[a[i]]]++)
		have[block[cnt[a[i]]]]--;
	return;
}
inline void work(int i,int j)
{
	if(up[i].pos>=q[j].l&&up[i].pos<=q[j].r)
	{
		if(!--cc[cnt[a[up[i].pos]]])
			have[block[cnt[a[up[i].pos]]]]++;
		cnt[a[up[i].pos]]--;
		if(!cc[cnt[a[up[i].pos]]]++)
			have[block[cnt[a[up[i].pos]]]]--;
		if(!--cc[cnt[up[i].x]])
			have[block[cnt[up[i].x]]]++;
		cnt[up[i].x]++;
		if(!cc[cnt[up[i].x]]++)
			have[block[cnt[up[i].x]]]--;
	}
	swap(a[up[i].pos],up[i].x);
	return;
}
signed main()
{
	int opt;
	register int i,j,k;
	scanf("%d%d",&n,&Q);
	for(i=1;i<=n;i++)
		scanf("%d",&k),V.push_back(k);
	while(Q--)
	{
		scanf("%d",&opt);
		if(opt==1)
			scanf("%*d%*d");
		else
			scanf("%*d%d",&k),V.push_back(k);
	}
	sort(V.begin(),V.end());
	int m=unique(V.begin(),V.end())-V.begin();
	while(V.size()>m)
		V.pop_back();
	rewind(stdin);
	scanf("%d%d",&n,&Q);
	for(i=1;i<=n;i++)
		scanf("%d",&a[i]),a[i]=lower_bound(V.begin(),V.end(),a[i])-V.begin();
	while(Q--)
	{
		scanf("%d",&opt);
		if(opt==1)
		{
			tot_q++;
			q[tot_q].id=tot_q;
			scanf("%d%d",&q[tot_q].l,&q[tot_q].r);
			q[tot_q].x=tot_up;
		}
		else
		{
			tot_up++;
			scanf("%d%d",&up[tot_up].pos,&up[tot_up].x);
			up[tot_up].x=lower_bound(V.begin(),V.end(),up[tot_up].x)-V.begin();
		}
	}
	int unit=pow(n,2.0/3.0),p=0;
	for(i=1;i<=n;i++)
		block[i]=((i-1)%unit?p:++p);
	sort(q+1,q+tot_q+1,cmp);
	int l=1,r=0,index=0;
	cc[0]=m;
	for(i=1;i<block[n];i++)
		have[i]=unit;
	have[block[n]]=n-unit*(block[n]-1);
	for(i=1;i<=tot_q;i++)
	{
		if(q[i].l>r)
		{
			for(;r<q[i].r;add(++r));
			for(;r>q[i].r;del(r--));
			for(;l>q[i].l;add(--l));
			for(;l<q[i].l;del(l++));
		}
		else
		{
			for(;l>q[i].l;add(--l));
			for(;l<q[i].l;del(l++));
			for(;r<q[i].r;add(++r));
			for(;r>q[i].r;del(r--));
		}
		for(;index<q[i].x;work(++index,i));
		for(;index>q[i].x;work(index--,i));
		for(j=1;j<=block[n];j++)
			if(have[j])
				break;
		for(k=max((j-1)*unit+1,0);k<=j*unit;k++)
			if(!cc[k])
				break;
		res[q[i].id]=k;
	}
	for(i=1;i<=tot_q;i++)
		printf("%d\n",res[i]);
	return 0;
}