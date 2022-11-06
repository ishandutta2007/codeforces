#include<cstdio>
#include<cstring>
#include<algorithm>
using std::max;
using std::min;
const int mod1=1e9+7,mod2=1e9+9;
inline int add(int a,int b,int mod)
{
	return (a+=b)>=mod?a-mod:a;
}
inline int sub(int a,int b,int mod)
{
	return (a-=b)<0?a+mod:a;
}
inline int mul(int a,int b,int mod)
{
	return (long long)a*b%mod;
}
struct hash_t
{
	int h1,h2;
	hash_t(int x=0)
	{
		h1=h2=x;
		return;
	}
	inline bool operator==(const hash_t &th) const
	{
		return h1==th.h1&&h2==th.h2;
	}
	inline hash_t operator+(const hash_t &th)
	{
		hash_t res;
		res.h1=add(h1,th.h1,mod1);
		res.h2=add(h2,th.h2,mod2);
		return res;
	}
	inline hash_t operator-(const hash_t &th)
	{
		hash_t res;
		res.h1=sub(h1,th.h1,mod1);
		res.h2=sub(h2,th.h2,mod2);
		return res;
	}
	inline hash_t operator*(const hash_t &th)
	{
		hash_t res;
		res.h1=mul(h1,th.h1,mod1);
		res.h2=mul(h2,th.h2,mod2);
		return res;
	}
};
const int base=31;
const int N=1e6+5;
int n,m;
char s[N],t[N];
int l[N],res[N];
hash_t ht[N],powb[N];
int next[N],next2[N];
inline hash_t hasht(int l,int r)
{
	return ht[r]-powb[r-l+1]*ht[l-1];
}
inline void kmp()
{
	register int i,j;
	next[0]=-1;
	for(i=1;i<=m;i++)
	{
		for(j=next[i-1];(~j)&&t[j+1]!=t[i];j=next[j]);
		next[i]=j+1;
	}
	return;
}
inline int lcp(int a,int b)
{
	int l=0,r=min(m-a+1,m-b+1),mid;
	while(l<r)
	{
		mid=(l+r+1)>>1;
		if(hasht(a,a+mid-1)==hasht(b,b+mid-1))
			l=mid;
		else
			r=mid-1;
	}
	return l;
}
inline void kmp2()
{
	register int i,j;
	next2[0]=-1;
	for(i=1;i<=n;i++)
	{
		for(j=next2[i-1];(~j)&&t[j+1]!=s[i];j=next[j]);
		next2[i]=j+1;
	}
	return;
}
signed main()
{
	register int i;
	scanf("%s%s",s+1,t+1);
	n=strlen(s+1);m=strlen(t+1);
	powb[0]=1;
	for(i=1;i<=100000;i++)
		powb[i]=powb[i-1]*base;
	for(i=1;i<=m;i++)
		ht[i]=ht[i-1]*base+t[i]-'a'+1;
	s[0]='@';s[n+1]='#';
	t[0]='$';t[m+1]='%';
	kmp();
	for(i=1;i<=m;i++)
	{
		l[i]=lcp(1,i+1);
		res[i]=max(res[next[i]],l[i]);
	}
	kmp2();
	int cur=0;
	long long ans=0;
	for(i=1;i<=n;i++)
	{
		cur=res[next2[i]];
		ans+=m-cur;
	}
	printf("%lld\n",ans);
	return 0;
}