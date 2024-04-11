#include<bits/stdc++.h>
#define re register
#define ld double
struct par{ld x;int no;}p[200100],p1[200100];
inline bool cmp(const par&A,const par&B){return A.x>B.x;}
inline bool cmp1(const par&A,const par&B){return A.no>B.no;}
long long a[200100],b[200100],c[200100];
int bs[200100];
int main()
{
	re int n,m,x,k,n1=0,n2=0;
	scanf("%d%d%d",&n,&k,&m);
	for(re int i=1;i<=n;i++)scanf("%lld",&a[i]);
	for(re int i=1;i<=k;i++)
	{
		scanf("%d%lld%lld",&x,&b[i],&c[i]);
		switch(x)
		{
			case 1:if(c[bs[b[i]]]<c[i])bs[b[i]]=i;break;
			case 2:p1[++n2]=(par){(ld)c[i],i};break;
			case 3:p[++n1]=(par){(ld)c[i],i};break;
		}
	}
	for(re int i=1;i<=n;i++)if(c[bs[i]]>a[i])p1[++n2]=(par){(ld)c[bs[i]]-a[i],bs[i]+(int)1e8};
	std::sort(p1+1,p1+n2+1,cmp);
	for(re int i=1;i<=n2;i++)
	{
		re int pos=b[p1[i].no%(int)1e8];
		p[++n1]=(par){(a[pos]+p1[i].x)/a[pos],p1[i].no+(int)1e8};
		a[pos]+=p1[i].x+0.5;
	}
	std::sort(p+1,p+n1+1,cmp);
	if(m>n1)m=n1;
	std::sort(p+1,p+m+1,cmp1);
	printf("%d\n",m);
	for(re int i=1;i<=m;i++)printf("%d ",p[i].no%(int)1e8);
}