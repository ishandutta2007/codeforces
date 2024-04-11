#include<cstdio>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=1e5+5,MOD=1000000007;
template<typename T>void read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
char s[N],tt[N];
int n,m,d[N],t[N],l[N],p[N],ans;
int pow(int aa,int b)
{
	long long c=1,a=aa;
	b%=MOD-1;
	while(b)
	{
		if(b&1)c*=a,c%=MOD;
		a*=a,a%=MOD;b>>=1;
	}
	return (int)c;
}
inline void add(int &a,int b,int l)
{
	a=(long long)a*pow(10,l)%MOD;
	(a+=b)%=MOD;
}
int main()
{
	scanf("%s",s);
	while(s[n])++n;
	read(m);
	F(i,0,10)t[i]=i,l[i]=1;
	F(i,0,m)
	{
		scanf("%d->",&d[i]);
		gets(tt+p[i]);
		p[i+1]=p[i];
		while(tt[p[i+1]])++p[i+1];
	}
	for(int i=m-1;~i;--i)
	{
		int ttt=0,lll=0;
		F(j,p[i],p[i+1])
		{
			add(ttt,t[(int)tt[j]-48],l[(int)tt[j]-48]);
			lll+=l[(int)tt[j]-48];
			lll%=MOD-1;
		}
		t[d[i]]=ttt;
		l[d[i]]=lll;
	}
	F(i,0,n)
	{
		int a=s[i]-48;
		add(ans,t[a],l[a]);
	}
	printf("%d\n",ans);
	return 0;
}