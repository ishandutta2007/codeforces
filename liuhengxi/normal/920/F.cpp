#include<cstdio>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
const int N=3e5+5,K=1e6+5;
template<typename T>void read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
int n,m,a[N],d[K]={0,1},r[K],t[K],k,pri[N],cnt,f[N];
long long c[N];bool vis[K];
void add(int x,int y){for(++x;x<=n;x+=x&-x)c[x]+=y;}
long long sum(int x){long long ans=0;for(;x;x-=x&-x)ans+=c[x];return ans;}
int find(int x){return f[x]==x?x:f[x]=find(f[x]);}
int main()
{
	read(n);read(m);
	F(i,0,n)read(a[i]),k=a[i]>k?a[i]:k;
	F(i,1,n+1)
	{
		int j=i+(i&-i);
		c[i]+=a[i-1];
		if(j<=n)c[j]+=c[i];
	}
	F(i,2,k+1)
	{
		if(!vis[i])pri[cnt++]=i,d[i]=2,t[i]=r[i]=1;
		F(j,0,cnt)
		{
			if(i*pri[j]>k)break;
			vis[i*pri[j]]=true;
			if(i%pri[j]==0)
			{
				t[i*pri[j]]=t[i]+1;
				r[i*pri[j]]=r[i];
				d[i*pri[j]]=d[r[i]]*(t[i*pri[j]]+1);
				break;
			}
			t[i*pri[j]]=1;
			r[i*pri[j]]=i;
			d[i*pri[j]]=d[i]<<1;
		}
	}
	F(i,0,n+1)f[i]=i;
	for(int i=n-1;~i;--i)if(a[i]==d[a[i]])f[i]=f[i+1];
	while(m--)
	{
		int op,l,r;read(op);read(l);read(r);--l;
		if(op==1)
		{
			for(int i=find(l);i<r;i=find(i+1))
			{
				add(i,d[a[i]]-a[i]);
				a[i]=d[a[i]];
				if(a[i]==d[a[i]])f[i]=find(i+1);
			}
		}
		else printf("%lld\n",sum(r)-sum(l));
	}
	return 0;
}