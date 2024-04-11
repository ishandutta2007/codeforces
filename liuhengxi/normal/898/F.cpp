#include<cstdio>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
#define output \
{F(i,0,n){if(i==a)putchar('+');if(i==b)putchar('=');putchar(s[i]);}return 0;}
using namespace std;
const int N=1e6+5,MOD=2144225243;
template<typename T>void read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
char s[N];
int n,h[N],a,b;
long long t[N]={1};
int calc(int l,int r){return (h[r]-h[l]*t[r-l]%MOD+MOD)%MOD;}
bool check()
{
	int res=0;
	if(!(0<a&&a<b&&b<n))return false;
	if(a-0>1&&s[0]=='0')return false;
	if(b-a>1&&s[a]=='0')return false;
	if(n-b>1&&s[b]=='0')return false;
	res=(calc(0,a)+(long long)calc(a,b))%MOD;
	return res==calc(b,n);
}
int main()
{
	gets(s);
	while(s[n])++n;
	F(i,0,n)h[i+1]=(h[i]*10ll+s[i]-'0')%MOD;
	F(i,0,n)t[i+1]=t[i]*10%MOD;
	F(i,1,n/2+1)
	{
		b=n-i;a=i;
		if(check())output;
		--a;
		if(check())output;
		a=b-i;
		if(check())output;
		++a;
		if(check())output;
	}
	return 0;
}