#include<cstdio>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=1e5+5,HASH_MOD=1030742513,DP_MOD=1000000007;
template<typename T>void read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
int n,m,tt,ss[N],off=1,a[N],f[N]/*left*/,ff,g[N]/*right*/,gg=1;
char s[N],t[N];
inline bool ok(int l,int r){return a[r]>a[l+m-1];}
int main()
{
	gets(s);gets(t);
	while(s[n])++n;
	while(t[m])++m;
	F(i,0,m)tt=(tt*27ll+t[i]-64)%HASH_MOD,off=off*27ll%HASH_MOD;
	F(i,0,n)ss[i+1]=(ss[i]*27ll+s[i]-64)%HASH_MOD;
	F(i,m,n+1)
	{
		a[i]=a[i-1];
		if(((ss[i]-ss[i-m]*(long long)off)%HASH_MOD+HASH_MOD)%HASH_MOD==tt)
			++a[i];
	}
	F(i,0,n)f[i]=1;
	for(int i=m,j=-1;i<=n;++i)
	{
		while(ok(j+1,i))
		{
			++j;
			(ff+=f[j])%=DP_MOD;
		}
		(gg+=(g[i]=ff))%=DP_MOD;
		f[i]=gg;
	}
	--gg;(gg+=DP_MOD)%=DP_MOD;
	printf("%d\n",gg);
	return 0;
}