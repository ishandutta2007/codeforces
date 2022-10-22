#include<cstdio>
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
constexpr int N=405,MOD=1000000007;
void reduce(int &x){(x>=MOD)&&(x-=MOD);}
int n,f[N][N];
int main()
{
	read(n);
	f[0][0]=1;
	F(i,1,n+1)F(j,0,n+1)F(k,0,n-j+1)
	{
		int tmp=(int)((long long)f[i-1][j]*f[i-1][k]%MOD);
		reduce(f[i][j+k]+=tmp);
		reduce(f[i][j+k+1]+=tmp);
		f[i][j+k]=(int)((f[i][j+k]+2ll*(j+k)*tmp)%MOD);
		if(j+k>1)f[i][j+k-1]=(int)((f[i][j+k-1]+(j+k)*(j+k-1ll)*tmp)%MOD);
	}
	printf("%d\n",f[n][1]);
	return 0;
}