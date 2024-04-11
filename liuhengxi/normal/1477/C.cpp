#include<cstdio>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=5005;
template<typename T>void read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
int n,x[N],y[N];
bool vis[N];
long long dis(int a,int b)
{
	long long xx=x[a]-x[b],yy=y[a]-y[b];
	return xx*xx+yy*yy;
}
int main()
{
	int k=0;
	read(n);
	F(i,0,n)read(x[i]),read(y[i]);
	F(i,1,n)
	{
		long long mx=0,id=-1;
		vis[k]=true;
		printf("%d ",k+1);
		F(j,0,n)if(!vis[j])if(dis(k,j)>mx)mx=dis(k,j),id=j;
		k=id;
	}
	printf("%d\n",k+1);
	return 0;
}