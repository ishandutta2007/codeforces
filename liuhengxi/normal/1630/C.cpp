#include<cstdio>
#include<algorithm>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=2e5+5;
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
int n,a[N],b[N],m,k,ans,rightmost,other[N],last[N],f[N],l[N],r[N];
bool isf[N],isl[N],app[N],covered[N];
int main()
{
	F(i,0,k=read(n))--read(a[i]);
	F(i,0,n)if(!app[a[i]])isf[i]=true,app[a[i]]=true;
	F(i,0,n)app[i]=false;
	for(int i=n;~--i;)if(!app[a[i]])isl[i]=true,app[a[i]]=true;
	F(i,0,n)if(isf[i]||isl[i])b[m++]=a[i];else ++ans;
	F(i,0,n=m)a[i]=b[i];
	rightmost=-1;
	F(i,0,k)last[i]=-1;
	F(i,0,n)other[i]=i;
	F(i,0,n)if(~last[a[i]])other[other[i]=last[a[i]]]=i;else last[a[i]]=i;
	F(i,0,n)if(other[i]>=i)
	{
		if(other[i]>rightmost)rightmost=other[i];
		else covered[a[i]]=true;
	}
	m=0;
	F(i,0,n)if(!covered[a[i]]){if(other[i]!=i)b[m++]=a[i];}else ++ans;
	F(i,0,n=m)a[i]=b[i];
	F(i,0,k)last[i]=-1;
	F(i,0,n)other[i]=i;
	F(i,0,n)if(~last[a[i]])other[other[i]=last[a[i]]]=i;else last[a[i]]=i;
	m=0;
	F(i,0,n)if(i<other[i])l[m]=i,r[m]=other[i],++m;
	n=m;
	for(int i=0,j=0;i<n;i=j+(i==j))
	{
		while(j+1<n&&l[j+1]<r[i])++j;
		if(i!=j)ans+=(j-i-1)<<1|1;
	}
	printf("%d\n",ans);
	return 0;
}