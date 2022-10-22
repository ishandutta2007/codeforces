#include<cstdio>
#include<cstring>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=3005,MOD=1000000007;
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
void reduce(int &x){(x>=MOD)&&(x-=MOD);}
int n,m,f[N][N];
char s[N][N];
int dp(int sx,int sy,int tx,int ty)
{
	memset(f,0,sizeof f);
	if(s[sx][sy]!='#')f[sx][sy]=1;
	F(i,0,n)F(j,0,m)if(s[i][j]!='#')
	{
		if(i)reduce(f[i][j]+=f[i-1][j]);
		if(j)reduce(f[i][j]+=f[i][j-1]);
	}
	return f[tx][ty];
}
int main()
{
	long long ans;
	read(n,m);
	F(i,0,n)scanf("%s",s[i]);
	ans=dp(0,1,n-2,m-1)*(long long)dp(1,0,n-1,m-2)-dp(1,0,n-2,m-1)*(long long)dp(0,1,n-1,m-2);
	ans%=MOD;ans+=MOD;ans%=MOD;
	printf("%lld\n",ans);
	return 0;
}