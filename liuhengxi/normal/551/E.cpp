#include<cstdio>
#include<algorithm>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
const int N=5e5+5;
template<typename T>void read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
int n,q,b,m,id[N],bl[N],lb[N],rb[N];
long long a[N],tag[N];
constexpr int min(int a,int b){return (unsigned)a<(unsigned)b?a:b;}
constexpr int max(int a,int b){return a>b?a:b;}
bool cmp(int u,int v){return a[u]!=a[v]?a[u]<a[v]:u<v;}
inline void block_modify(int x,int v){tag[x]+=v;}
inline void small_modify(int x,int v,int l,int r){F(i,l,r)a[i]+=v;std::sort(id+lb[x],id+rb[x],cmp);}
int lower_bound(int x,long long v)
{
	int l=lb[x]-1,r=rb[x]-1,mid;
	while(r-l>1)if(a[id[mid=(l+r)>>1]]>=v)r=mid;else l=mid;
	return id[r];
}
int upper_bound(int x,long long v)
{
	int l=lb[x],r=rb[x],mid;
	while(r-l>1)if(a[id[mid=(l+r)>>1]]<=v)l=mid;else r=mid;
	return id[l];
}
inline int block_queryl(int x,long long v){int ans=lower_bound(x,v-=tag[x]);return a[ans]==v?ans:-1;}
inline int block_queryr(int x,long long v){int ans=upper_bound(x,v-=tag[x]);return a[ans]==v?ans:-1;}
inline void modify(int l,int r,int v)
{
	int L=bl[l]+1,R=bl[r];
	if(L>R)return small_modify(R,v,l,r);
	F(i,L,R)block_modify(i,v);
	small_modify(L-1,v,l,lb[L]);
	if(R<m)small_modify(R,v,lb[R],r);
}
inline int queryl(int v)
{
	int ans=-1;
	F(i,0,m)ans=min(ans,block_queryl(i,v));
	return ans;
}
inline int queryr(int v)
{
	int ans=-1;
	F(i,0,m)ans=max(ans,block_queryr(i,v));
	return ans;
}
int main()
{
	read(n);read(q);
	while(b*b<n)++b;
	b>>=1;if(!b)++b;
	m=(n+b-1)/b;
	F(i,0,n)read(a[i]);
	F(i,0,n+1)bl[i]=i/b;
	F(i,0,m)lb[i]=i*b,rb[i]=i*b+b;
	rb[m-1]=n;
	F(i,0,n)id[i]=i;
	F(i,0,m)std::sort(id+lb[i],id+rb[i],cmp);
	lb[m]=n;
	while(q--)
	{
		int op;read(op);
		if(op==1)
		{
			int l,r,v;read(l);read(r);read(v);--l;
			modify(l,r,v);
		}
		else
		{
			int v,l,r;read(v);
			l=queryl(v);
			if(!~l)puts("-1");
			else
			{
				r=queryr(v);
				printf("%d\n",r-l);
			}
		}
	}
	return 0;
}