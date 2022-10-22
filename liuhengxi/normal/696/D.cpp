#include<cstdio>
#include<algorithm>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=205,Sigma=28;
const long long LLINF=0x3fffffffffffffff;
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
int to[N][Sigma],fail[N],ind=1,q[N],qf,qr;
int insert(const char *s)
{
	int j=0;
	for(;*s;++s)
	{
		int x=*s-'a';
		if(!to[j][x])to[j][x]=ind++;
		j=to[j][x];
	}
	return j;
}
struct matrix
{
	static const int N=205;
	int n;
	long long a[N][N];
	matrix(int n_=0){n=n_;F(i,0,n)F(j,0,n)a[i][j]=-LLINF;}
	friend matrix operator*(const matrix &a,const matrix &b)
	{
		matrix c(a.n);
		F(i,0,a.n)F(k,0,a.n)F(j,0,b.n)c.a[i][j]=max(c.a[i][j],a.a[i][k]+b.a[k][j]);
		return c;
	}
}bas,ans;
int n,a[N],f[N];
long long l,finalans;
char s[N];
void build()
{
	F(i,0,26)if(to[0][i])q[qr++]=to[0][i];
	while(qf<qr)
	{
		int u=q[qf++];
		f[u]+=f[fail[u]];
		F(i,0,26)if(to[u][i])fail[q[qr++]=to[u][i]]=to[fail[u]][i];
		else to[u][i]=to[fail[u]][i];
	}
}
int main()
{
	read(n,l);
	F(i,0,n)read(a[i]);
	F(i,0,n)scanf("%s",s),f[insert(s)]+=a[i];
	build();
	bas.n=ind;ans.n=ind;
	F(i,0,ind)F(j,0,ind)bas.a[i][j]=-LLINF;
	F(i,0,ind)F(j,0,ind)ans.a[i][j]=-LLINF;
	F(i,0,ind)ans.a[i][i]=0;
	F(i,0,ind)F(j,0,26)bas.a[i][to[i][j]]=f[to[i][j]];
	for(;l;l>>=1,bas=bas*bas)if(l&1)ans=ans*bas;
	F(i,0,ind)finalans=max(finalans,ans.a[0][i]);
	printf("%lld\n",finalans);
	return 0;
}