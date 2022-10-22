#include<cstdio>
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
constexpr int N=2005,M=4005,MOD=1000000007;
void reduce(int &x){(x>=MOD)&&(x-=MOD);}
void addmuleq(int &x,int y,int z){x=(int)((x+(long long)y*z)%MOD);}
int c[M][M];
inline int C(int n,int m){return m<0||m>n?0:c[n][m];}
int tt,n,a[2][N],b[2][N];
char s[N],t[N];
int main()
{
	F(i,0,M)c[i][0]=1;
	F(i,1,M)F(j,1,i+1)reduce(c[i][j]=c[i-1][j]+c[i-1][j-1]);
	read(tt);
	while(tt--)
	{
		int ans=0;
		read(n);
		scanf("%s",s);
		scanf("%s",t);
		for(int i=1;i<n;i+=2)s[i]!='?'&&(s[i]^=1),t[i]!='?'&&(t[i]^=1);
		F(i,0,n)
		{
			a[0][i+1]=a[0][i]+(s[i]=='?'),a[1][i+1]=a[1][i]+(s[i]=='1');
			b[0][i+1]=b[0][i]+(t[i]=='?'),b[1][i+1]=b[1][i]+(t[i]=='1');
		}
		int t1=a[0][n]+b[0][n];
		int t2=a[0][n]+a[1][n]-b[1][n];
		F(i,0,n)if(s[i]!='0')
		{
			int t3=a[0][i],t4=t3+a[1][i],t5=t1-a[0][i+1],t6=t2-a[0][i+1]-a[1][i+1];
			F(j,0,n)if(t[j]!='0'&&j!=i)
ans=(int)((ans+(long long)abs(j-i)*C(t3+b[0][j],t4-b[1][j])%MOD*C(t5-b[0][j+1],t6+b[1][j+1]))%MOD);
		}
		printf("%d\n",ans);
	}
	return 0;
}