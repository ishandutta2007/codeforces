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
constexpr int N=1e5+5,LogN=19;
constexpr int log2(int x){return 31-__builtin_clz(x);}
char s[N],t[N];
int n,p[N],z[N],ans,st[LogN][N],ak,a1,a2,a3,a4,a5,a6;
int query(int l,int r)
{
	int k=log2(r-l);
	return max(st[k][l],st[k][r-(1<<k)]);
}
int solve(int x,int y)
{
	int l=0,r=(y-x+1)>>1,mid;
	while(r-l>1)
	{
		mid=(l+r)>>1;
		if(query(x+mid,y-mid)>=mid)l=mid;
		else r=mid;
	}
	return l;
}
int main()
{
	scanf("%s",s);
	while(s[n])++n;
	F(i,0,n)t[i]=s[n-1-i];
	for(int i=1,j=0;i<n;p[++i]=j)
	{
		while(j&&t[i]!=t[j])j=p[j];
		if(t[i]==t[j])++j;
	}
	for(int i=0,mid=0,mr=0;i<n;++i)
	{
		if(i<mr)z[i]=min(mr-i-1,z[2*mid-i]);
		while(i-z[i]>0&&s[i-z[i]-1]==s[i+z[i]+1])++z[i];
		if(i+z[i]+1>mr)mr=i+z[i]+1,mid=i;
	}
	F(i,0,n)st[0][i]=z[i];
	F(i,0,log2(n))F(j,0,n+1-(2<<i))st[i+1][j]=max(st[i][j],st[i][j+(1<<i)]);
	F(i,0,n)
	{
		if(2*z[i]+1>ans)
		{
			ans=2*z[i]+1;
			ak=1;
			a1=i-z[i];
			a2=2*z[i]+1;
		}
	}
	for(int i=0,j=0,n1=n-1;i<n1;++i)
	{
		while(j&&s[i]!=t[j])j=p[j];
		if(s[i]==t[j])++j;
		while(j>=n1-i)j=p[j];
		int res=solve(i+1,n-j);
		if(2*res+1+2*j>ans)
		{
			ans=2*res+1+2*j;
			ak=3;
			a1=i+1-j;
			a5=n-j;
			a2=a6=j;
			a4=res;
		}
	}
	printf("%d\n",ak);
	if(ak==3)
	{
		F(i,a1+a2+a4,a5-a4)if(z[i]>=a4)
		{
			a3=i-a4;
			break;
		}
		a4=2*a4+1;
		printf("%d %d\n",++a1,a2);
		printf("%d %d\n",++a3,a4);
		printf("%d %d\n",++a5,a6);
	}
	else printf("%d %d\n",++a1,a2);
	return 0;
}