#include<cstdio>
#include<algorithm>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=55,M=110,MOD=998244353;
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
inline int pow(int aa,int b)
{
	long long a=aa,c=1;
	for(;b;b>>=1,(a*=a)%=MOD)if(b&1)(c*=a)%=MOD;
	return (int)c;
}
inline int inv(int a){return pow(a,MOD-2);}
inline int C(int n,int m)
{
	int num=1,den=1;
	if(m<0||m>n)return 0;
	F(i,0,m)num=int(num*(long long)(n-i)%MOD);
	F(i,1,m+1)den=int(den*(long long)i%MOD);
	return int((long long)num*inv(den)%MOD);
}
int n,l[N],r[N],v[M],m,f[N/*index*/][M/*last*/][N/*repeat*/],ans,tot=1,g[M][N];
inline void add(int &a,int b){(a+=b)-=MOD;a+=a>>31&MOD;}
int main()
{
	++read(n);
	l[0]=-5,r[0]=-4;
	for(int i=n;--i;)read(l[i],r[i]),++r[i];
	l[n]=MOD+2,r[n++]=MOD+3;
	F(i,0,n)v[i<<1]=l[i],v[i<<1|1]=r[i];
	sort(v,v+(n<<1));m=int(unique(v,v+(n<<1))-v);
	F(i,0,n)l[i]=int(lower_bound(v,v+m,l[i])-v),r[i]=int(lower_bound(v,v+m,r[i])-v);;
	f[0][0][0]=1;
	F(i,0,m-1)F(j,0,n+1)g[i][j]=C(v[i+1]-v[i]+j-1,j);
	F(i,1,n)F(now,l[i],r[i])
	{
		F(last,0,now)F(rep,0,i+1)add(f[i][now][1],(int)((long long)f[i-1][last][rep]*g[last][rep]%MOD));
		F(rep,0,i+1)add(f[i][now][rep+1],f[i-1][now][rep]);
	}
	--n;
	ans=f[n][m-2][1];
	F(i,0,n)tot=int((long long)tot*(v[r[i]]-v[l[i]])%MOD);
	ans=int((long long)ans*inv(tot)%MOD);
	printf("%d\n",ans);
	return 0;
}