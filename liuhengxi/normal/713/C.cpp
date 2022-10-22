#include<cstdio>
#include<algorithm>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=3005;
template<typename T>void read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
int n,a[N],d[N];long long f[N][N],ans;
inline int dif(int a,int b){return a<b?d[b]-d[a]:d[a]-d[b];}
int main()
{
	read(n);
	F(i,0,n)read(a[i]),d[i]=a[i]-=i;
	sort(d,d+n);
	F(i,0,n)a[i]=lower_bound(d,d+n,a[i])-d;
	F(i,0,n)
	{
		F(j,0,n)f[i+1][j]=f[i][j]+dif(j,a[i]);
		F(j,1,n)f[i+1][j]=min(f[i+1][j],f[i+1][j-1]);
	}
	ans=f[n][0];
	F(i,1,n)ans=min(ans,f[n][i]);
	printf("%lld\n",ans);
	return 0;
}