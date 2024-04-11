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
constexpr int N=(1<<18)+5;
void dis(long long *begin,long long *end)
{
	static long long v[N];int n=0;
	for(long long *i=begin;i!=end;++i)v[n++]=*i;
	sort(v,v+n);
	for(long long *i=begin;i!=end;++i)*i=lower_bound(v,v+n,*i)-v;
}
int n;
long long a[20][N];
char s[N];
int dfs(int dep,int l,int r)
{
	int mid=(l+r)>>1,h=mid^l;
	if(r-l==1)return 0;
	F(i,0,h)a[dep+1][l^i]=a[dep][l^i<<1]<<20|a[dep][l^i<<1^1],a[dep+1][mid^i]=a[dep][l^i<<1^1]<<20|a[dep][l^i<<1];
	dis(a[dep+1]+l,a[dep+1]+r);
	int ls=dfs(dep+1,l,mid);
	int rs=dfs(dep+1,mid,r);
	bool le=true;
	F(i,0,h)if(a[dep+1][l^i^ls]!=a[dep+1][mid^i^rs]){le=a[dep+1][l^i^ls]<a[dep+1][mid^i^rs];break;}
	if(le)return ls<<1;
	else return rs<<1|1;
}
int main()
{
	read(n);
	scanf("%s",s);
	F(i,0,1<<n)a[0][i]=s[i];
	dis(a[0],a[0]+(1<<n));
	int ans=dfs(0,0,1<<n);
	F(i,0,1<<n)putchar(s[i^ans]);
	puts("");
	return 0;
}