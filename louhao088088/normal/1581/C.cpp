#include<bits/stdc++.h>
using namespace std;
//static char buf[1000000],*p1=buf,*p2=buf;
//#define getchar() p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++
#define re register
const int maxn=405;
inline int read()
{
	char ch=getchar();bool f=0;int x=0;
	for(;!isdigit(ch);ch=getchar())if(ch=='-')f=1;
	for(;isdigit(ch);ch=getchar())x=(x<<1)+(x<<3)+(ch^48);
	if(f==1)x=-x;return x;
}
void print(int x)
{
    if(x<0) putchar('-'),x=-x;
    if(x>9) print(x/10);
    putchar(x%10+'0');
}
int n,m,a[maxn][maxn],sum[maxn][maxn],ans,T;
char b[maxn][maxn];
int S(int x,int y,int x2,int y2)
{
	return sum[x2][y2]-sum[x2][y-1]-sum[x-1][y2]+sum[x-1][y-1];
}
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	T=read();
	while(T--)
	{
		ans=20;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)a[i][j]=b[i][j]=sum[i][j]=0;
		n=read(),m=read();
		for(int i=1;i<=n;i++)scanf("%s",b[i]+1);
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)a[i][j]=b[i][j]-'0',sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+a[i][j];
		for(int i=1;i<=n;i++)
			for(int j=i+4;j<=n;j++)
			{
				for(int k=1;k<=m;k++)
				{
					int res=j-i-1-S(i+1,k,j-1,k);
					res+=4-(a[i][k+1]+a[i][k+2]+a[j][k+1]+a[j][k+2]);
					res+=S(i+1,k+1,j-1,k+2);
					if(res>=ans)continue;
					for(int l=k+3;l<=m;l++)
					{
						ans=min(ans,res+j-i-1-S(i+1,l,j-1,l));
						res=res+2-(a[i][l]+a[j][l])+S(i+1,l,j-1,l);
						if(res>=ans)break;
					}
				}
				//cout<<ans<<" "<<i<<" "<<j<<endl;
			}
		printf("%d\n",ans);
	}
 	return 0;
}