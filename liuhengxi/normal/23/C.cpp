#include<cstdio>
#include<algorithm>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=2e5+5;
template<typename T>void read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
int t,n,a[N],b[N],id[N];
bool cmp(int u,int v){return a[u]>a[v];}
int main()
{
	read(t);
	while(t--)
	{
		long long e=0,o=0;
		read(n);
		F(i,0,2*n-1)read(a[i]),read(b[i]),id[i]=i;
		sort(id,id+2*n-1,cmp);
		F(i,0,2*n-1)(i&1?o:e)+=b[id[i]];
		puts("YES");
		if(e>=o)F(i,0,2*n-1){if(!(i&1))printf("%d ",id[i]+1);}
		else F(i,0,2*n-1){if((!i)||(i&1))printf("%d ",id[i]+1);}
		puts("");
	}
	return 0;
}