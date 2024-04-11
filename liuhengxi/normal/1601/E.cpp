#include<cstdio>
#include<vector>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
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
constexpr int N=3e5+5;
int n,q,k,a[N],b[N],qq[N],qf,qr,f[N],l[N],r[N],bb[N],sta[N],top;
long long ans[N],sum[N];
vector<int> id[N];
int find(int x){return f[x]==x?x:f[x]=find(f[x]);}
int main()
{
	read(n,q,k);
	F(i,0,n)read(a[i]);
	F(i,0,k)
	{
		while(qf<qr&&a[qq[qr-1]]>a[i])--qr;
		qq[qr++]=i;
	}
	F(i,k,n)
	{
		while(qf<qr&&a[qq[qr-1]]>a[i])--qr;
		qq[qr++]=i;
		b[i-k]=a[qq[qf]];
		if(qf<qr&&qq[qf]==i-k)++qf;
	}
	F(i,0,q)
	{
		read(l[i],r[i]),--l[i];
		ans[i]=a[l[i]];
		r[i]=l[i]/k+(r[i]-l[i]-1)/k;
		id[l[i]].emplace_back(i);
	}
	F(i,0,k)
	{
		int m=(n-i-1)/k;
		top=0;sta[top++]=m;
		F(j,0,m)bb[j]=b[j*k+i];
		bb[m]=0;
		#define b bb
		F(j,0,m+1)f[j]=j,sum[j]=0;
		for(int j=m;~--j;)
		{
			while(b[sta[top-1]]>=b[j])f[find(sta[--top])]=find(j);
			sum[j]=(sta[top-1]-j)*(long long)b[j]+sum[sta[top-1]];
			sta[top++]=j;
			for(int p:id[j*k+i])
			{
				int rr=r[p],rb=find(rr);
				ans[p]+=sum[j]-sum[rb]+(rr-rb)*(long long)b[rb];
			}
		}
		#undef b
	}
	F(i,0,q)printf("%lld\n",ans[i]);
	return 0;
}