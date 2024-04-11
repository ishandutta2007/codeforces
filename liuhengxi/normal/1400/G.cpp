#include<cstdio>
#include<algorithm>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=3e5+5,K=45,MOD=998244353;
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
int fac[N],invfac[N];
inline int pow(int aa,int b)
{
	long long a=aa,c=1;
	for(;b;b>>=1,(a*=a)%=MOD)if(b&1)(c*=a)%=MOD;
	return (int)c;
}
inline int inv(int a){return pow(a,MOD-2);}
inline int C(int n,int m){if(m<0||m>n)return 0;return int((long long)fac[n]*invfac[m]%MOD*invfac[n-m]%MOD);}
int n,m,l[N],r[N],x[K],y[K],s[N],p[K][N];
bool t[N];
long long ans;
int main()
{
	read(n,m);
	F(i,fac[0]=1,n+1)fac[i]=int(fac[i-1]*(long long)i%MOD);
	invfac[n]=pow(fac[n],MOD-2);
	for(int i=n;i;--i)invfac[i-1]=int(invfac[i]*(long long)i%MOD);
	F(i,0,n)read(l[i],r[i]),++s[l[i]],--s[++r[i]];
	F(i,0,m)read(x[i],y[i]),--x[i],--y[i];
	F(i,0,n)s[i+1]+=s[i];
	F(i,0,(m<<1)+1)F(j,0,n+1)p[i][j+1]=p[i][j]+C(s[j]-i,j-i)-MOD,p[i][j+1]+=p[i][j+1]>>31&MOD;
	F(i,0,1<<m)
	{
		int k=0,L=1,R=n+1;
		F(j,0,m)if(i>>j&1)
		{
			k+=!t[x[j]],t[x[j]]=true;
			k+=!t[y[j]],t[y[j]]=true;
			L=max(L,l[x[j]]);
			R=min(R,r[x[j]]);
			L=max(L,l[y[j]]);
			R=min(R,r[y[j]]);
		}
		F(j,0,m)if(i>>j&1)t[x[j]]=t[y[j]]=false;
		if(L<R)
		{
			if(__builtin_parity(i))ans+=p[k][L]-p[k][R]+MOD;
			else ans+=p[k][R]-p[k][L]+MOD;
		}
	}
	ans%=MOD;
	printf("%lld\n",ans);
	return 0;
}