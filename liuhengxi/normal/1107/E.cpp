#include<cstdio>
#include<algorithm>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=105;
const long long LLINF=0x3fffffffffffffffll;
int n;char s[N];
long long a[N],f[N][N][N];
int main()
{
	scanf("%d",&n);scanf("%s",s);
	F(i,1,n+1)scanf("%lld",&a[i]);
	F(i,0,n+1)F(j,0,n+1)F(k,0,n+2)f[i][j][k]=-LLINF;
	F(i,0,n)F(j,0,n)f[i][i+1][j]=a[j+1],f[i][i][j]=a[j];
	F(len,2,n+1)
	{
		F(l,0,n-len+1)
		{
			int r=l+len;
			F(k,0,n)
			{
				f[l][r][k]=f[l][r-1][0]+a[k+1];
				F(mid,l,r-1)
				{
					if(s[mid]==s[r-1])
					{
						f[l][r][k]=max(f[l][r][k],f[l][mid+1][k+1]+f[mid+1][r-1][0]);
					}
				}
			}
		}
	}
	printf("%lld\n",f[0][n][0]);
	return 0;
}