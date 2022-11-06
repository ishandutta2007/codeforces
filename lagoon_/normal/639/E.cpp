#include<bits/stdc++.h>
#define re register
struct par{int p,t;long long l1,r1;}f[150010];
inline bool cmp(const par&A,const par&B){return (long long)A.p*B.t>(long long)B.p*A.t;}
inline bool cmp1(const par&A,const par&B){return A.p>B.p;}
int main()
{
	re int n;
	scanf("%d",&n);
	for(re int i=1;i<=n;i++)scanf("%d",&f[i].p);
	for(re int i=1;i<=n;i++)scanf("%d",&f[i].t);
	std::sort(f+1,f+n+1,cmp);
	re long long tt=f[1].t,T;
	for(re int i=2;i<=n;i++)
	{
		if((long long)f[i].p*f[i-1].t==(long long)f[i-1].p*f[i].t)f[i].l1=f[i-1].l1;
		else f[i].l1=tt;
		tt+=f[i].t;
	}
	T=f[n].r1=tt;tt-=f[n].t;
	for(re int i=n-1;i;i--)
	{
		if((long long)f[i].p*f[i+1].t==(long long)f[i+1].p*f[i].t)f[i].r1=f[i+1].r1;
		else f[i].r1=tt;
		tt-=f[i].t;
	}
	std::sort(f+1,f+n+1,cmp1);
	re double l=0,r=1,mid;
	for(mid=(l+r)/2;l<r-1e-9;mid=(l+r)/2)
	{
		re bool ok=0;re double nw=1e233;
		re int i;
		for(re int i1=1;i1<=n&&!ok;i1=i)
		{
			for(i=i1;i<=n&&f[i].p==f[i1].p;i++)if(f[i].p*(1-(double)(f[i].l1+f[i].t)/T*mid)>nw){ok=1;break;}
			for(re int ii=i1;ii<i;ii++)
			{
				nw=std::min(nw,f[ii].p*(1-(double)f[ii].r1/T*mid));
			}
		}
		if(ok)r=mid;
		else l=mid;
	}
	printf("%.12lf\n",l);
}