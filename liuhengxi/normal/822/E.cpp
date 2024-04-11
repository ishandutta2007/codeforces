#include<cstdio>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
#define mod(a,b) (((b)%a+a)%a)
using namespace std;
typedef long long ll;
const int N=1e5+5,INF=0x3fffffff,MOD[2]={14421401,14421443};
template<typename T>void read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
int n,m,x,f[N][33],a[N][2],b[N][2],p[N][2]={1,1};
char s[N],t[N];
int match(int x,int y)
{
	int l=0,r=(m-y<n-x?m-y:n-x)+1,mid;
	while(r-l>1)
	{
		bool ok=true;
		mid=(l+r)>>1;
		ok=ok&&mod(MOD[0],a[x+mid][0]-(ll)p[mid][0]*a[x][0])==
		mod(MOD[0],b[y+mid][0]-(ll)p[mid][0]*b[y][0]);
		ok=ok&&mod(MOD[1],a[x+mid][1]-(ll)p[mid][1]*a[x][1])==
		mod(MOD[1],b[y+mid][1]-(ll)p[mid][1]*b[y][1]);
		if(ok)l=mid;else r=mid;
	}
	return l;
}
int main()
{
	read(n);gets(s);read(m);gets(t);read(x);
	for(int k=0;k<2;++k)
	{
		F(i,0,n)a[i+1][k]=(a[i][k]*26+s[i]-'a')%MOD[k];
		F(i,0,m)b[i+1][k]=(b[i][k]*26+t[i]-'a')%MOD[k];
		F(i,0,n)p[i+1][k]=p[i][k]*26%MOD[k];
	}
	F(i,0,n)
	{
		F(j,0,x)
		{
			int tmp=match(i,f[i][j]);
			if(f[i][j]>f[i+1][j])f[i+1][j]=f[i][j];
			if(f[i][j]+tmp>f[i+tmp][j+1])f[i+tmp][j+1]=f[i][j]+tmp;
		}
		if(f[i][x]>f[i+1][x])f[i+1][x]=f[i][x];
	}
	puts(f[n][x]==m?"YES":"NO");
	return 0;
}