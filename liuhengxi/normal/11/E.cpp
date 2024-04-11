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
constexpr int NN=1e6+5,N=2e6+5,D=100000000;
int n;
bool check(const char *s,int v)
{
	long long f0=0,f1=-v,t0,t1;
	F(i,0,n)
	{
		t1=f0+D*(s[i]=='L')-v;
		t0=f1+D*(s[i]=='R')-v;
		f0=max(t0,t1-v);
		f1=max(t1,t0-v);
	}
	return f0>=0;
}
int solve(const char *s)
{
	int l=0,r=D+1,mid;
	F(i,0,n)if(s[i]!='X')++l;
	l=(int)((long long)l*D/(n+(~n&1))>>1);
	if(!check(s,l))return l;
	while(r-l>1)
	{
		mid=(l+r)>>1;
		if(check(s,mid))l=mid;
		else r=mid;
	}
	return l;
}
char ss[NN],sss[N],*s=sss+1;
int main()
{
	int ans;
	scanf("%s",ss);
	for(int i=0;ss[i];s[n++]=ss[i++])if(i&&ss[i]!='X'&&ss[i]==ss[i-1])s[n++]='X';
	if(s[0]!='X'&&s[0]==s[n-1])
	{
		s[-1]=s[n]='X';
		++n;
		ans=max(solve(s),solve(s-1));
	}
	else ans=solve(s);
	printf("%d.%06d\n",ans/1000000,ans%1000000);
	return 0;
}