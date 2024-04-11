#include<cstdio>
#include<cstring>
#include<algorithm>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
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
constexpr int N=705,MOD=1000000007;
int m,f[N][N][2],ans;
char n[N];
int main()
{
	scanf("%s",n);
	while(n[m])++m;
	F(i,1,10)
	{
		memset(f,0,sizeof f);
		f[0][0][1]=1;
		F(j,0,m)
		{
			F(k,0,j+1)
			{
				f[j+1][k][0]=(int)((f[j+1][k][0]+f[j][k][0]*(long long)i)%MOD);
				f[j+1][k+1][0]=(int)((f[j+1][k+1][0]+f[j][k][0]*(10ll-i))%MOD);
				f[j+1][k][0]=(int)((f[j+1][k][0]+f[j][k][1]*(long long)min(i,n[j]-'0'))%MOD);
				f[j+1][k+1][0]=(int)((f[j+1][k+1][0]+f[j][k][1]*(long long)(n[j]-'0'-min(i,n[j]-'0')))%MOD);
				if(n[j]-'0'>=i)f[j+1][k+1][1]+=f[j][k][1],(f[j+1][k+1][1]>=MOD)&&(f[j+1][k+1][1]-=MOD);
				else f[j+1][k][1]+=f[j][k][1],(f[j+1][k][1]>=MOD)&&(f[j+1][k][1]-=MOD);
			}
		}
		long long p10=1,s10=0;
		F(j,0,m+1)
		{
			ans=(int)((ans+s10*(f[m][j][0]+f[m][j][1]))%MOD);
			s10+=p10;(s10>=MOD)&&(s10-=MOD);
			(p10*=10)%=MOD;
		}
	}
	printf("%d\n",ans);
	return 0;
}