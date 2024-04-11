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
constexpr int N=2005,M=2e5+5,L=25,l=22,MOD=1000000007;
int pow(int aa,int b)
{
	long long a=aa,c=1;
	for(;b;b>>=1,(a*=a)%=MOD)if(b&1)(c*=a)%=MOD;
	return (int)c;
}
inline void addeqmul(int &a,const int &b,const int &c){a=(int)((a+(long long)b*c)%MOD);}
struct cell
{
	int x,y;
	friend bool operator<(cell a,cell b){return a.x!=b.x?a.x<b.x:a.y<b.y;}
}c[N];
int fac[M],invfac[M],n,m,k,s,f[N][L],g[L];
bool lt,rb;
int C(int a,int b){return (int)((long long)fac[a]*invfac[a-b]%MOD*invfac[b]%MOD);}
int C2(int a,int b){return (int)((long long)fac[a+b]*invfac[a]%MOD*invfac[b]%MOD);}
int main()
{
	F(i,fac[0]=1,M)fac[i]=(int)((long long)fac[i-1]*i%MOD);
	invfac[M-1]=pow(fac[M-1],MOD-2);
	for(int i=M;--i;)invfac[i-1]=(int)((long long)invfac[i]*i%MOD);
	read(n,m,k,s);--n,--m;
	F(i,0,k)read(c[i].x,c[i].y),--c[i].x,--c[i].y,lt=lt||!(c[i].x|c[i].y),rb=rb||(c[i].x==n&&c[i].y==m);
	if(lt)s-=s>>1;
	else c[k++]=cell({0,0});
	if(!rb)s<<=1,c[k++]=cell({n,m});
	sort(c,c+k);
	f[0][0]=1;
	F(i,1,k)
	{
		F(j,0,i)if(c[j].y<=c[i].y)
		{
			int d=C2(c[i].y-c[j].y,c[i].x-c[j].x);
			F(p,0,l)addeqmul(f[i][p+1],f[j][p],d);
		}
		F(p,1,l)f[i][p]-=f[i][p+1],f[i][p]+=(int)f[i][p]>>31&MOD;
		f[i][0]=0;
	}
	int ans=C2(n,m);
	F(p,0,l)
	{
		addeqmul(ans,f[k-1][p],s-1);
		s-=s>>1;
	}
	ans=(int)((long long)ans*pow(C2(n,m),MOD-2)%MOD);
	printf("%d\n",ans);
	return 0;
}