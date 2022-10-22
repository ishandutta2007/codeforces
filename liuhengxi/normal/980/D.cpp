#include<cstdio>
#include<algorithm>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=5e3+5;
template<typename T>void read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
int n,a[N],v[N],c[N],ans[N],fsb;
int main()
{
	read(n);
	F(i,0,n)
	{
		read(a[i]);
		for(int j=4,k=2;j<=a[i]||j<=-a[i];j+=k,j+=++k)while(a[i]%j==0)a[i]/=j;
		v[i]=a[i];
	}
	sort(v,v+n);
	F(i,0,n)a[i]=lower_bound(v,v+n,a[i])-v;
	fsb=lower_bound(v,v+n,0)-v;
	if(v[fsb])fsb=-1;
	F(i,0,n)
	{
		int now=0;
		F(j,0,n)c[j]=0;
		F(j,i,n)
		{
			if(a[j]!=fsb&&!c[a[j]])now+=c[a[j]]=1;
			++ans[now?now:1];
		}
	}
	F(i,1,n+1)printf("%d ",ans[i]);
	puts("");
	return 0;
}