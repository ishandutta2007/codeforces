#include<bits/stdc++.h>
#define re register
const double pi=acos(-1),eps=1e-4;
struct par{double x;int no;}p[1000100];
struct pp{int l,r,no;}p1[1000100];
double a[1000100],b[1000100],alp[1000100],ds[1000100],x,y;
int n,m,f[1000010];
inline bool cmp(const par&A,const par&B){return A.x<B.x;}
inline bool operator < (const pp&A,const pp&B){return A.l<B.l;}
void add(re int a)
{
	for(;a<=2*n;a+=a&-a)f[a]++;
}
int sum(re int a)
{if(a<0)a=0;
	re int sm=0;
	for(;a;a-=a&-a)sm+=f[a];
	return sm;
}
long long check(re double c)
{
	re long long ans=0;
	re int nm=0;
	memset(f,0,sizeof(f));
	for(re int i=1;i<=n;i++)
	{
		if(ds[i]<=c)
		{
			re double xa=acos(ds[i]/c),yy1,yy2;
			if(x*a[i]+b[i]>=y)yy1=pi/2+alp[i]-xa,yy2=pi/2+alp[i]+xa;
			else yy1=xa+alp[i]-pi/2,yy2=alp[i]-xa-pi/2;
			if(yy1<0)yy1+=2*pi;if(yy2<0)yy2+=2*pi;
			if(yy1>yy2)std::swap(yy1,yy2);
			nm++;
			p[nm*2-1]=(par){yy1,-nm};
			p[nm*2]=(par){yy2,nm};
		}
	}
	std::sort(p,p+2*nm+1,cmp);
	for(re int i=1;i<=2*nm;i++)if(p[i].no<0)p1[-p[i].no].l=i;else p1[p[i].no].r=i;
	std::sort(p1,p1+nm+1);
	for(re int i=1;i<=nm;i++)
	{
		ans+=sum(p1[i].r)-sum(p1[i].l-1);
		add(p1[i].r);
	}
	return ans;
}
double anss;
std::set<pp>ss; 
void cans(re int a1,re int b1)
{
	re double xx=(b[b1]-b[a1])/(a[a1]-a[b1]),yy=a[a1]*xx+b[a1];
	anss+=sqrt((xx-x)*(xx-x)+(yy-y)*(yy-y));
}
long long clac(re double c)
{
	re long long ans=0;
	re int nm=0;
	for(re int i=1;i<=n;i++)
	{
		if(ds[i]<=c)
		{
			re double xa=acos(ds[i]/c),yy1,yy2;
			if(x*a[i]+b[i]>=y)yy1=pi/2+alp[i]-xa,yy2=pi/2+alp[i]+xa;
			else yy1=xa+alp[i]-pi/2,yy2=alp[i]-xa-pi/2;
			if(yy1<0)yy1+=2*pi;if(yy2<0)yy2+=2*pi;
			if(yy1>yy2)std::swap(yy1,yy2);
			nm++;
			p1[nm].no=i;
			p[nm*2-1]=(par){yy1,-nm};
			p[nm*2]=(par){yy2,nm};
		}
	}
	std::sort(p,p+2*nm+1,cmp);
	for(re int i=1;i<=2*nm;i++)if(p[i].no<0)p1[-p[i].no].l=i;else p1[p[i].no].r=i;
	std::sort(p1,p1+nm+1);
	for(re int i=1;i<=nm;i++)
	{
		std::set<pp>::iterator it=ss.upper_bound((pp){p1[i].r,0,0});
		for(;it!=ss.begin()&&(--it)->l>=p1[i].l;){ans++;cans(p1[i].no,it->no);}
		ss.insert((pp){p1[i].r,0,p1[i].no});
	}
	return ans;
}
int main()
{
	scanf("%d%lf%lf%d",&n,&x,&y,&m);
	for(re int i=1;i<=n;i++)scanf("%lf%lf",&a[i],&b[i]),a[i]/=1000,alp[i]=atan(a[i]),ds[i]=fabs(a[i]*x-y+b[i])/sqrt(a[i]*a[i]+1);
	re double l=0,r=1e13,mid;
	for(mid=(l+r)/2;l+eps<r;mid=(l+r)/2)
	{
		re int x=check(mid);
		if(x==m)l=r=mid;
		else if(x>m)r=mid;
		else l=mid;
	}
	while(check(l)>m)l-=eps;
	anss+=(m-clac(l))*l;
	printf("%.15lf\n",anss/1000);
}