#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<iostream>
using namespace std;
typedef long long LL;
const LL MAX=(1<<30);
const LL N=20005;
LL n,k,p;
LL sum[N];
LL f[2][N];
LL get (LL l,LL r){return ((sum[r]-sum[l-1])%p+p)%p;}
struct qq
{
	LL l,r;
	LL s1,s2;
	LL c;// 
}tr[205*2];LL num;
void update (LL x)
{
	LL s1=tr[x].s1,s2=tr[x].s2;
	tr[x].c=max(tr[s1].c,tr[s2].c);
}
void bt (LL l,LL r)
{
	LL a=++num;
	tr[a].l=l;tr[a].r=r;
	tr[a].c=-MAX;
	if (l==r) return ;
	LL mid=(l+r)>>1;
	tr[a].s1=num+1;bt(l,mid);
	tr[a].s2=num+1;bt(mid+1,r);
	update(a);
}
void change (LL now,LL x,LL c)
{
	if (tr[now].l==tr[now].r)		{tr[now].c=max(tr[now].c,c);return ;}
	LL s1=tr[now].s1,s2=tr[now].s2;
	LL mid=(tr[now].l+tr[now].r)>>1;
	if (x<=mid) change(s1,x,c);
	else change(s2,x,c);
	update(now);
}
LL get (LL now,LL l,LL r)
{
//	printf("%I64d %I64d %I64d %I64d\n",l,r,tr[now].l,tr[now].r);
	if (tr[now].l==l&&tr[now].r==r)	return tr[now].c;
	LL s1=tr[now].s1,s2=tr[now].s2;
//	printf("TYB:%I64d %I64d %I64d\n",now,s1,s2);
//	system("pause");
	LL mid=(tr[now].l+tr[now].r)>>1;
	if (r<=mid) get(s1,l,r);
	else if (l>mid) get(s2,l,r);
	else return max(get(s1,l,mid),get(s2,mid+1,r));
}
int main()
{
	scanf("%I64d%I64d%I64d",&n,&k,&p);
	for (LL u=1;u<=n;u++)
	{
		scanf("%I64d",&sum[u]);
		sum[u]=(sum[u]+sum[u-1])%p;
		f[0][u]=sum[u];
	}
	LL o=0;
	for (LL u=2;u<=k;u++)//
	{
		//printf("%I64d\n",u);
		o^=1;
		num=0;bt(0,2*p);
		for (LL i=0;i<u;i++)	change(1,sum[i],f[o^1][i]-sum[i]);
	//	printf("YES\n");
		for (LL i=u;i<=n;i++)
		{
			//printf("%d %d %d\n",i,sum[i],get(1,0,sum[i]));
			f[o][i]=max(sum[i]+get(1,0,sum[i]),sum[i]+p+get(1,sum[i]+1,2*p));
			///printf("OZY\n");
			change(1,sum[i],f[o^1][i]-sum[i]);
		//	printf("%I64d ",f[o][i]);
		}
		//printf("\n");
	}
	printf("%I64d\n",f[o][n]);
	return 0;
}