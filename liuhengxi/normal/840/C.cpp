#include<cstdio>
#include<algorithm>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=305,MOD=1000000007;
template<typename T>void read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
int n,a[N],f[N],g[N],C[2*N][2*N];
inline void delsqr(int &x){for(int i=2,j=4;j<=x;j+=i,j+=++i)while(x%j==0)x/=j;}
int main()
{
	read(n);
	F(i,0,n)read(a[i]),delsqr(a[i]);
	sort(a,a+n);
	f[0]=1;
	C[0][0]=1;
	F(i,1,2*n+1)
	{
		C[i][0]=1;
		F(j,1,2*n+1)C[i][j]=(C[i-1][j-1]+C[i-1][j])%MOD;
	}
	for(int l=0,r=0;l<n;l=r)
	{
		int len;
		while(r<n&&a[l]==a[r])++r;
		len=r-l;
		F(i,0,n)g[i]=0;
		F(i,1,len+1)// "connected component"
		{
			int distrib=C[len-1][i-1];
			F(j,1,len+1)distrib=(long long)distrib*j%MOD;
			F(j,0,l+1)// previous
			{
				F(k,0,min(j,i)+1)// number of (insert between two same numbers)
				{
					(g[j+len-i-k]+=(long long)f[j]*distrib%MOD*C[l-j+1][i-k]%MOD*C[j][k]%MOD)%=MOD;
				}
			}
		}
		F(i,0,n)f[i]=g[i];
	}
	printf("%d\n",f[0]);
	return 0;
}