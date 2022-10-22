#include<cstdio>
#include<unordered_map>
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
constexpr int N=40;
int h;long long lm,l;
struct poly
{
	long long a;
	friend poly operator+(poly u,poly v){return {u.a^v.a};}
	friend poly &operator<<=(poly &u,int v)
	{
		while(v--)
		{
			u.a<<=1;
			u.a=(u.a&lm)^((u.a>>h)*l);
		}
		return u;
	}
	friend poly operator*(poly u,poly v)
	{
		poly w={0};
		for(;v.a;v.a>>=1,u<<=1)if(v.a&1)w.a^=u.a;
		return w;
	}
};
unordered_map<long long,int> mp;
int n,r,zero;
char s[N];
int main()
{
	scanf("%s",s);
	while(s[zero]=='0')++zero;
	while(s[zero+n])s[n]=s[zero+n],++n;
	while(n&&s[n-1]=='0')--n;
	if(!n)return puts("-1"),0;
	if(n==1)return printf("%d %d\n",zero+1,zero+2),0;
	if(n==2)return printf("%d %d\n",zero+1,zero+2),0;
	F(i,0,n-1)if(s[i]=='1')l|=1ll<<i;
	h=n-1;lm=(1ll<<h)-1;
	poly b={1},g={1};
	r=1<<(n>>1);
	long long ans=0;
	F(i,0,r)
	{
		if(mp.find(b.a)!=mp.end())
		{
			ans=i-mp[b.a];
			break;
		}
		mp.emplace(b.a,i);
		b<<=1;
	}
	for(long long j=0;!ans;j+=r)
	{
		if(mp.find(g.a)!=mp.end())ans=abs(j-mp[g.a]);
		g=g*b;
	}
	printf("%d %lld\n",zero+1,zero+1+ans);
	return 0;
}