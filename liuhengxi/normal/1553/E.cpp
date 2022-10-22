#include<cstdio>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=3e5+5;
template<typename T>void read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
int t,n,m,p[N],c[N],q[N],f[N],ans;
bool is[N];
int find(int x){return f[x]==x?x:f[x]=find(f[x]);}
int main()
{
	read(t);
	while(t--)
	{
		int ans=0;
		read(n);read(m);
		F(i,0,n)read(p[i]),--p[i];
		F(i,0,n)c[i]=0;
		F(i,0,n)++c[(i-p[i]+n)%n];
		F(i,0,n)is[i]=false;
		F(i,0,n)if(c[i]>=n-2*m)
		{
			int cir=0;
			F(j,0,n)q[j]=p[(j+i)%n];
			F(j,0,n)f[j]=j;
			F(j,0,n)f[find(j)]=find(q[j]);
			F(j,0,n)if(find(j)==j)++cir;
			if(cir>=n-m)
			{
				++ans;is[i]=true;
			}
		}
		printf("%d ",ans);
		F(i,0,n)if(is[i])printf("%d ",i);
		puts("");
	}
	return 0;
}