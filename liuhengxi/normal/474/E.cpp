#include<cstdio>
#include<algorithm>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=1e5+5;
template<typename T>void read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
int n,d,f[N],p[N],c[N],c1[N],ans,s[N],t;
long long a[N],a1[N],v[N],v1[N];
int find1(long long *v,long long x)
{
	int l=-1,r=n,mid;
	while(r-l>1)
	{
		mid=(l+r)>>1;
		if(x<v[mid])r=mid;
		else l=mid;
	}
	return l;
}
void add(int *c,int i,int y)
{
	for(++y;y<=n;y+=y&-y)c[y]=!~c[y]||f[c[y]]<f[i]?i:c[y];
}
int query(int *c,int y)
{
	int ans=-1;
	for(++y;y;y-=y&-y)ans=!~ans||f[ans]<f[c[y]]?c[y]:ans;
	return ans;
}
int main()
{
	read(n);read(d);
	if(d==0)
	{
		printf("%d\n",n);
		F(i,0,n)printf("%d ",i+1);
		printf("\n");
		return 0;
	}
	F(i,0,n)read(a[i]),a1[i]=-a[i];
	F(i,0,n)v[i]=a[i],v1[i]=a1[i];
	sort(v,v+n);sort(v1,v1+n);
	F(i,0,n)f[i]=1,p[i]=-1,c[i]=-1,c1[i]=-1;
	c[n]=-1,c1[n]=-1;
	F(i,0,n)
	{
		int x=find1(v,a[i]-d),y=find1(v,a[i]);
		int x1=find1(v1,-a[i]-d),y1=find1(v1,-a[i]);
		int z=query(c,x),z1=query(c1,x1);
		if(f[z]+1>f[i])f[i]=f[z]+1,p[i]=z;
		if(f[z1]+1>f[i])f[i]=f[z1]+1,p[i]=z1;
		add(c,i,y);add(c1,i,y1);
		if(f[i]>f[ans])ans=i;
	}
	printf("%d\n",f[ans]);
	for(;~ans;ans=p[ans])s[t++]=ans;
	while(t)printf("%d ",s[--t]+1);
	printf("\n");
	return 0;
}