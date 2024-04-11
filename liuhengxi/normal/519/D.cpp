#include<cstdio>
#include<algorithm>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=1e5+5;
template<typename T>void read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
int n,a[N],x[N],t[26][N];
long long c[N],v[N],ans;
char s[N];
int aaa(long long x)
{
	int l=0,r=n,mid;
	while(r-l>1)
	{
		mid=(l+r)>>1;
		if(x<v[mid])r=mid;
		else l=mid;
	}
	return l;
}
int main()
{
	F(i,0,26)read(x[i]);
	gets(s);
	while(s[n])++n;
	F(i,0,n)v[i+1]=c[i+1]=c[i]+x[s[i]-'a'];
	sort(v,v+n);
	F(i,0,n)a[i]=aaa(c[i]);
	F(i,0,n)
	{
		ans+=t[s[i]-'a'][a[i]];
		++t[s[i]-'a'][a[i+1]];
	}
	printf("%lld\n",ans);
	return 0;
}