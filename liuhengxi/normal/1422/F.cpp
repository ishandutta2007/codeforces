#include<cstdio>
#include<algorithm>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=1e5+5,M=2e5+5,MOD=1000000007;
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
struct euler
{
	int pri[M],cnt,mpf[M];
	bool vis[M];
	euler()
	{
		F(i,2,M)
		{
			if(!vis[i])pri[cnt++]=i,mpf[i]=i;
			F(j,0,cnt)
			{
				int x=i*pri[j];
				if(x>=M)break;
				vis[x]=true;
				mpf[x]=pri[j];
				if(i%pri[j]==0)break;
			}
		}
	}
}e;
const int *mpf=e.mpf;
int pow(int aa,int b)
{
	long long a=aa,c=1;
	for(;b;b>>=1,(a*=a)%=MOD)if(b&1)(c*=a)%=MOD;
	return (int)c;
}
int n,a[N],q,pt[M],last[N],rt[N],lc[350*N],rc[350*N],prod[350*N],ind;
int build(int l,int r)
{
	int p=++ind,mid=(l+r)>>1;
	prod[p]=1;
	if(r-l>1)
	{
		lc[p]=build(l,mid);
		rc[p]=build(mid,r);
	}
	return p;
}
int update(int p,int l,int r,int x,int v)
{
	int s=++ind,mid=(l+r)>>1;
	if(r-l==1)
	{
		prod[s]=(int)((long long)prod[p]*v%MOD);
		return s;
	}
	lc[s]=lc[p];
	rc[s]=rc[p];
	if(x<mid)lc[s]=update(lc[s],l,mid,x,v);
	else rc[s]=update(rc[s],mid,r,x,v);
	prod[s]=(int)((long long)prod[lc[s]]*prod[rc[s]]%MOD);
	return s;
}
int query(int p,int l,int r,int x)
{
	int mid=(l+r)>>1;
	if(r-l==1)return x>l?prod[p]:1;
	if(x>=mid)return (int)((long long)prod[lc[p]]*query(rc[p],mid,r,x)%MOD);
	return query(lc[p],l,mid,x);
}
int main()
{
	F(i,2,M-1)
	{
		int cnt=0;
		if(mpf[i]==i)for(int j=i;j<M;j*=i)++cnt;
		pt[i+1]=pt[i]+cnt;
	}
	F(i,0,read(n))read(a[i]);
	rt[0]=build(0,n);
	F(i,0,n)
	{
		int &p=rt[i+1];p=rt[i];
		while(a[i]>1)
		{
			int x=mpf[a[i]],t=0;
			while(a[i]%x==0)a[i]/=x,++t;
			F(k,pt[x],pt[x]+t)
			{
				p=update(p,0,n,last[k],x);
				last[k]=i+1;
			}
		}
	}
	read(q);
	for(int ans=0;q--;)
	{
		int l,r;
		read(l,r);
		(l+=ans)%=n;(r+=ans)%=n;
		if(l>r)swap(l,r);
		++r;
		ans=query(rt[r],0,n,l+1);
		ans=(int)(ans*(long long)pow(query(rt[l],0,n,l+1),MOD-2)%MOD);
		printf("%d\n",ans);
	}
	return 0;
}