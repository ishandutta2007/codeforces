#include<cstdio>
#include<algorithm>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
#define ctz __builtin_ctz
using namespace std;
const int N=12,M=2005;
template<typename T>void read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
int t,n,m,a[M][N],f[1<<N],id[M],mx[M];
bool cmp(int u,int v){return mx[u]>mx[v];} 
inline int cyc(int x){return x>>1|(x&1)<<(n-1);}
int main()
{
	read(t);
	while(t--)
	{
		read(n);read(m);
		F(i,0,n)F(j,0,m)read(a[j][i]);
		F(i,0,m)mx[id[i]=i]=0;
		F(i,0,m)F(j,0,n)mx[i]=max(mx[i],a[i][j]);
		sort(id,id+m,cmp);
		F(i,0,1<<n)f[i]=0;
		F(i,0,min(n,m))
		{
			F(j,1,1<<n)for(int k=j;k;k^=k&-k)f[j]=max(f[j],f[j^(k&-k)]+a[id[i]][ctz(k)]);
			F(j,1,1<<n)for(int k=cyc(j);k!=j;k=cyc(k))f[j]=max(f[j],f[k]);
		}
		printf("%d\n",f[(1<<n)-1]);
	}
	return 0;
}