#include<cstdio>
#include<algorithm>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=2e5+5,K=17;
template<typename T>void readmain(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
template<typename T>T& read(T &x){readmain(x);return x;}
template<typename T,typename ...Tr>void read(T &x,Tr&... r){readmain(x);read(r...);}
int n,k,f[1<<K],pre[K][N],nex[K][N];
char s[N];
bool check(int v)
{
	F(i,0,k)
	{
		nex[i][n+1]=n+1;
		for(int j=n;~j;--j)nex[i][j]=j+v<=n&&pre[i][j]==pre[i][j+v]?j+v:nex[i][j+1];
	}
	F(i,1,1<<k)
	{
		f[i]=n+1;
		F(j,0,k)if(i>>j&1)f[i]=min(f[i],nex[j][f[i^1<<j]]);
	}
	return f[(1<<k)-1]<=n;
}
int solve()
{
	int l=0,r=n/k+1,mid;
	while(r-l>1)
	{
		mid=(l+r)>>1;
		if(check(mid))l=mid;
		else r=mid;
	}
	return l;
}
int main()
{
	read(n,k);
	scanf("%s",s);
	F(i,0,k)F(j,0,n)pre[i][j+1]=pre[i][j]+(s[j]!='?'&&s[j]-'a'!=i);
	printf("%d\n",solve());
	return 0;
}