#include<bits/stdc++.h>
#define re register
using namespace std;
long long t[100100];
int f[100100],d[100100];
long long c[100100];
struct par{int x;long long val;};
bool operator < (const par&A,const par&B){return A.val<B.val;}
std::priority_queue<par>p[100100],p1[100100],q,q1;
void clr(re int i)
{
	for(;!p[i].empty();p[i].pop())
	{
		re int x=p[i].top().x;
		if(f[x]==i&&c[x]==p[i].top().val)break;
	}
	for(;!p1[i].empty();p1[i].pop())
	{
		re int x=p1[i].top().x;
		if(f[x]==i&&-c[x]==p1[i].top().val)break;
	}
}
void rr(re int i)
{
	clr(i);
	if(!p[i].empty())q.push((par){i,p[i].top().val+t[i]/(d[i]+2)}),
	q1.push((par){i,p1[i].top().val-t[i]/(d[i]+2)});
}
void rec(re int a,re int ad)
{
	c[a]+=(t[a]-(d[a]+1)*(t[a]/(d[a]+2)))*ad;
	c[f[a]]+=t[a]/(d[a]+2)*ad;
}
void rk(re int a)
{
	p[f[a]].push((par){a,c[a]});p1[f[a]].push((par){a,-c[a]});
}
int main()
{
	re int n,m,tp,x,y;
	scanf("%d%d",&n,&m);
	for(re int i=1;i<=n;i++)scanf("%lld",&t[i]);
	for(re int i=1;i<=n;i++)scanf("%d",&f[i]),d[f[i]]++;
	for(re int i=1;i<=n;i++)c[i]+=t[i]-(d[i]+1)*(t[i]/(d[i]+2)),c[f[i]]+=t[i]/(d[i]+2);
	for(re int i=1;i<=n;i++)p[f[i]].push((par){i,c[i]}),p1[f[i]].push((par){i,-c[i]});
	for(re int i=1;i<=n;i++)if(!p[i].empty())q.push((par){i,p[i].top().val+t[i]/(d[i]+2)}),q1.push((par){i,p1[i].top().val-t[i]/(d[i]+2)});
	for(;m--;)
	{
		scanf("%d",&tp);
		if(tp==1)
		{
			scanf("%d%d",&x,&y);
			re int xx=f[x];
			rec(xx,-1);rec(y,-1);
			d[xx]--;d[y]++;f[x]=y;
			rec(xx,1);rec(y,1);
			c[xx]-=t[x]/(d[x]+2);c[y]+=t[x]/(d[x]+2);
			rk(x);rk(y);rk(xx);rk(f[xx]);rk(f[y]);
			rr(y);rr(xx);rr(f[xx]);rr(f[y]);rr(f[f[xx]]);rr(f[f[y]]);
		}else if(tp==2)
		{
			scanf("%d",&x);
			printf("%lld\n",c[x]+t[f[x]]/(d[f[x]]+2));
		}else
		{
			for(;!q.empty();q.pop())
			{
				re int x=q.top().x;
				clr(x);
				if((!p[x].empty())&&(p[x].top().val+t[x]/(d[x]+2)==q.top().val))break;
			}
			for(;!q1.empty();q1.pop())
			{
				re int x=q1.top().x;
				clr(x);
				if((!p1[x].empty())&&(p1[x].top().val-t[x]/(d[x]+2)==q1.top().val))break;
			}
			printf("%lld %lld\n",-q1.top().val,q.top().val);
		}
	}
}