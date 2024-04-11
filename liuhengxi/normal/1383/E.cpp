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
constexpr int N=1e6+5,MOD=1'000'000'007;
int n,m,sl,sr,a[N],f[N],g[N],sta[N],stav[N],top;
char s[N];
int main()
{
	scanf("%s",s);
	while(s[m])++m;
	while(s[sl]=='0')++sl;
	if(sl==m)return printf("%d\n",m),0;
	for(sr=m;s[--sr]=='0';);
	++sr;
	a[n++]=-1;
	for(int i=sl+1,c=0;i<sr;++i)
	{
		if(s[i]=='0')++c;
		else a[n++]=c,c=0;
	}
	g[1]=f[0]=1;
	sta[top]=0;
	stav[top++]=-1;
	F(i,1,n)
	{
		int l=i;
		long long tmp=0;
		while(top&&stav[top-1]<a[i])
		{
			--top;
			(tmp+=(a[i]-stav[top])*(long long)(g[l]-g[sta[top]]+MOD))%=MOD;
			l=sta[top];
		}
		f[i]=(int)tmp;
		g[i+1]=g[i]+f[i];
		(g[i+1]>=MOD)&&(g[i+1]-=MOD);
		if(l!=i)
		{
			sta[top]=l;
			stav[top++]=a[i];
		}
		sta[top]=i;
		stav[top++]=-1;
	}
	long long ans=g[n];
	ans%=MOD;
	(ans*=sl+1)%=MOD;
	(ans*=m-sr+1)%=MOD;
	printf("%lld\n",ans);
	return 0;
}