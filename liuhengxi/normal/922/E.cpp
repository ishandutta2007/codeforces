#include<cstdio>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=1e3+5,M=1e4+5;
const long long LLINF=0x3fffffffffffffffll;
template<typename T>void read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
int n,m,w,x,a[N]/*cnt*/,ans;
long long b,c[N]/*cost*/,f[N/*tree*/][M/*bird summon*/]/*mana*/;
int main()
{
	read(n);read(w);read(b);read(x);
	F(i,0,n)read(a[i]),m+=a[i];
	F(i,0,n)read(c[i]);
	F(i,0,n+1)F(j,0,m+1)f[i][j]=-LLINF;
	f[0][0]=w;
	F(i,0,n)F(j,0,m+1)if(f[i][j]!=-LLINF)F(k,0,a[i]+1)
	{
		long long mana=f[i][j],cap=w+j*b;
		if(mana<k*c[i])break;
		mana-=k*c[i];cap+=k*b;
		mana+=x;mana=mana<cap?mana:cap;
		f[i+1][j+k]=f[i+1][j+k]>mana?f[i+1][j+k]:mana;
	}
	while(ans<m&&f[n][ans+1]>=0)++ans;
	printf("%d\n",ans);
	return 0;
}