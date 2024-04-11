#include<cstdio>
#include<algorithm>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=205,K=1005,MOD=1000000007;
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
inline void add(int &a,int b){a+=(a+=b-MOD)>>31&MOD;}
int n,k,a[N],f[N][N][K],ans;
int main()
{
	read(n,k);++k;
	F(i,0,n)read(a[i]);
	sort(a,a+n);
	f[0][0][0]=1;
	f[0][1][0]=1;
	F(i,1,n)
	{
		int delta=a[i]-a[i-1];
		F(l,0,k)add(f[i][1][l],f[i-1][0][l]),add(f[i][0][l],f[i-1][0][l]);
		F(j,1,i+1)
		{
			int d=j*delta;
			F(l,0,k-d)add(f[i][j-1][l+d],int((long long)j*f[i-1][j][l]%MOD)),
			add(f[i][j+1][l+d],f[i-1][j][l]),
			add(f[i][j][l+d],int((j+1ll)*f[i-1][j][l]%MOD));
		}
	}
	F(i,0,k)add(ans,f[n-1][0][i]);
	printf("%d\n",ans);
	return 0;
}