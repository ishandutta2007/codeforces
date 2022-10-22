#include<cstdio>
#include<algorithm>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=1005;
template<typename T>void read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
int n,a[N],m,u[N*N],v[N*N],id[N];
bool cmp(int u,int v){return a[u]!=a[v]?a[u]<a[v]:u<v;}
int main()
{
	read(n);
	F(i,0,n)read(a[i]),id[i]=i;
	sort(id,id+n,cmp);
	F(i,0,n)a[id[i]]=i;
	while(n)
	{
		F(i,0,n)id[a[i]]=i;
		F(i,a[n-1]+1,n)u[m]=id[i],v[m]=n-1,++m,swap(a[id[i]],a[n-1]);
		--n;
	}
	printf("%d\n",m);
	F(i,0,m)printf("%d %d\n",u[i]+1,v[i]+1);
	return 0;
}