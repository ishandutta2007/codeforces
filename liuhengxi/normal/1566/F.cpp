#include<cstdio>
#include<algorithm>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=2e5+5,INF=0x3fffffff;
const long long LLINF=0x3fffffffffffffffll;
template<typename T>void readmain(T &x)
{
	bool neg=false;
	unsigned int c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
template<typename T>T& read(T &x){readmain(x);return x;}
template<typename T,typename ...Tr>void read(T &x,Tr&... r){readmain(x);read(r...);}
struct segment
{
	int l,r;
	friend bool operator<(segment u,segment v){return u.l<v.l;}
}s[N];
int tt,n,m,mm,a[N];
long long f1[N],f2[N],ans;
bool ch[N];
int main()
{
	read(tt);
	while(tt--)
	{
		read(n,m);
		F(i,0,n)read(a[i]);
		sort(a,a+n);
		F(i,0,m)read(s[i].l),read(s[i].r);
		sort(s,s+m);
		mm=0;
		for(int i=0,j=0;i<m;++i)
		{
			while(j<n&&a[j]<s[i].l)++j;
			if(!(j<n&&a[j]<=s[i].r))s[mm++]=s[i];
		}
		m=mm;
		for(int i=m,mn=INF;~--i;)if((ch[i]=s[i].r<mn))mn=s[i].r;
		mm=0;
		for(int i=0;i<m;++i)if(ch[i])s[mm++]=s[i];
		m=mm;
		for(int i=0,j=0;i<n;++i)
		{
			int p=j;
			while(j<m&&s[j].r<a[i])++j;
			if(i==0){if(j)f2[i]=(f1[i]=a[0]-s[0].r)<<1;else f2[i]=f1[i]=0;}
			else
			{
				f1[i]=f2[i]=LLINF;
				F(k,p,j+1)
				{
					long long d1,d2;
					d1=k==p?0:s[k-1].l-a[i-1];
					d2=k==j?0:a[i]-s[k].r;
					f1[i]=min(f1[i],min(f1[i-1]+2*d1+d2,f2[i-1]+d1+d2));
					f2[i]=min(f2[i],min(f1[i-1]+2*d1+2*d2,f2[i-1]+d1+2*d2));
				}
			}
			if(i==n-1)
			{
				long long dis=j==m?0:s[m-1].l-a[i];
				ans=min(f2[i]+dis,f1[i]+2*dis);
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}