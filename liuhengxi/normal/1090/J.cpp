#include<cstdio>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=1e5+5;
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
char s[N],t[N];
int n,m,p[N],o[N];
long long ans;
int main()
{
	scanf("%s%s",s,t);
	while(s[n])++n;
	while(t[m])++m;
	for(int i=1,j=0;i<m;p[++i]=j)
	{
		while(j&&t[i]!=t[j])j=p[j];
		if(t[i]==t[j])++j;
	}
	for(int i=1,j=0;i<n;++i)
	{
		while(j&&s[i]!=t[j])j=p[j];
		if(s[i]==t[j])++j;
		++o[j];
	}
	for(int i=m;i;--i)o[p[i]]+=o[i];
	F(i,1,m+1)ans+=n-(p[i]?o[i-p[i]]:0);
	printf("%lld\n",ans);
	return 0;
}