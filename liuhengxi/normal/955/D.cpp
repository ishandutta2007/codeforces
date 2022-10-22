#include<cstdio>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=5e5+5;
template<typename T>void read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
int n,m,k,f[N],g[N],next[N];
char a[N],b[N];
bool ans;
void solve(int *f)
{
	for(int i=1,j=0;i<m;++i)
	{
		while(j&&b[i]!=b[j])j=next[j];
		if(b[i]==b[j])++j;
		next[i+1]=j;
	}
	F(i,0,m+1)f[i]=-1;
	for(int i=0,j=0;i<n;++i)
	{
		while(j&&a[i]!=b[j])j=next[j];
		if(a[i]==b[j])++j;
		while(j>k)j=next[j];
		if(i<k-1&&j==m)f[j]=0;
		if(i>=k-1)if(!~f[j])f[j]=i-k+1;
	}
	for(int i=m;i;--i)if(f[i]!=-1)
		if(f[i]<f[next[i]]||f[next[i]]==-1)f[next[i]]=f[i];
}
int main()
{
	read(n);read(m);read(k);
	scanf("%s%s",a,b);
	solve(f);
	F(i,0,n/2)a[i]^=a[n-1-i]^=a[i]^=a[n-1-i];
	F(i,0,m/2)b[i]^=b[m-1-i]^=b[i]^=b[m-1-i];
	solve(g);
	F(i,0,m+1)if(~g[i])g[i]=n-1-g[i];
	F(i,0,m+1)if(~f[i]&&~g[m-i]&&g[m-i]-f[i]>=2*k-1&&!ans)
	{
		ans=true;
		puts("Yes");
		printf("%d %d\n",f[i]+1,g[m-i]-k+2);
	}
	if(!ans)puts("No");
	return 0;
}