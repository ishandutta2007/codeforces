#include<cstdio>
#include<algorithm>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int M=2e5,INF=0x3fffffff;
template<typename T>void read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
struct power
{
	int a,b,l;
	long long c;
	bool operator<(power x)const{return c<x.c;}
}p[M];
long long n;
int m,len,pos;
char ans[20];
int length(int x){return x==0?0:length(x/10)+1;}
int length(long long x){return x==0?0:length(x/10)+1;}
void uni(int &m)
{
	int del=0;
	for(int i=0;i+del<m;)
	{
		if(i+del==0||p[i+del].c!=p[i-1].c)
		{
			p[i]=p[i+del];
			++i;
		}
		else
		{
			if(p[i+del].l<p[i-1].l)p[i-1]=p[i+del];
			++del;
		}
	}
	m-=del;
}
int find(long long x)
{
	int l=0,r=m,mid;
	while(r-l>1)
	{
		mid=(l+r)>>1;
		if(x<p[mid].c)r=mid;
		else l=mid;
	}
	return l;
}
int main()
{
	read(n);
	for(int i=2;(long long)i*i<=n;++i)
	{
		int ll=length(i);
		long long k=(long long)i*i;
		for(int j=2;k<=n;k*=i,++j)
		{
			p[m].a=i;p[m].b=j;
			p[m].c=k;
			p[m++].l=ll+length(j)+1;
		}
	}
	sort(p,p+m);
	uni(m);
	len=length(n);
	sprintf(ans,"%lld",n);
	F(i,0,m)if(n%p[i].c==0)
	{
		if(n==p[i].c)
		{
			if(p[i].l<len)
			{
				len=p[i].l;
				sprintf(ans,"%d^%d",p[i].a,p[i].b);
			}
		}
		else
		{
			int tmp,r=find(n/p[i].c);
			if(p[r].c==n/p[i].c)
			{
				tmp=p[r].l+1+p[i].l;
				if(tmp<len)
				{
					len=tmp;
					sprintf(ans,"%d^%d*%d^%d",p[r].a,p[r].b,p[i].a,p[i].b);
				}
			}
			tmp=length(n/p[i].c)+1+p[i].l;
			if(tmp<len)
			{
				len=tmp;
				sprintf(ans,"%lld*%d^%d",n/p[i].c,p[i].a,p[i].b);
			}
		}
	}
	F(i,0,m)
	{
		int tmp=p[i].l+1+length(n-p[i].c),r;
		if(tmp<len)
		{
			len=tmp;
			sprintf(ans,"%d^%d+%lld",p[i].a,p[i].b,n-p[i].c);
		}
		r=find(n-p[i].c);
		if(p[r].c!=n-p[i].c)continue;
		tmp=p[i].l+1+p[r].l;
		if(tmp<len)
		{
			len=tmp;
			sprintf(ans,"%d^%d+%d^%d",p[i].a,p[i].b,p[r].a,p[r].b);
		}
	}
	F(i,0,m)
	{
		int tmp=length(n/p[i].c)+1+p[i].l+1+length(n%p[i].c);
		if(tmp<len)
		{
			len=tmp;
			sprintf(ans,"%lld*%d^%d+%lld",n/p[i].c,p[i].a,p[i].b,n%p[i].c);
		}
	}
	if(len==10)
	F(i1,2,10)
	{
		int j1=i1;
		F(i2,2,10)
		{
			j1*=i1;
			F(i3,2,10)
			{
				int j2=i3;
				F(i4,2,10)
				{
					j2*=i3;
					F(i5,1,10)
					{
						long long val=(long long)j1*j2+i5;
						int tmp=9;
						if(val==n&&tmp<len)
						{
							len=tmp;
							sprintf(ans,"%d^%d*%d^%d+%d",i1,i2,i3,i4,i5);
						}
						val=(long long)i5*j1+j2;
						if(val==n&&tmp<len)
						{
							len=tmp;
							sprintf(ans,"%d*%d^%d+%d^%d",i5,i1,i2,i3,i4);
						}
					}
				}
			}
		}
	}
	puts(ans);
	return 0;
}