#include<cstdio>
#include<cstring>
#include<algorithm>
#include<utility>
#define mp make_pair
#define fi first
#define se second
using std::max;
using std::pair;
using std::make_pair;
typedef long long ll;
const int base=10;
const int mod1=969758357,mod2=969758359;
const int N=1e6+7;
int n;
char s[N];
pair<int,int> h[N],powb[N];
inline pair<int,int> hash(int l,int r)
{
	return mp((h[r].fi-(ll)powb[r-l+1].fi*h[l-1].fi%mod1+mod1)%mod1,(h[r].se-(ll)powb[r-l+1].se*h[l-1].se%mod2+mod2)%mod2);
}
inline bool legal(int l,int r)
{
	if((r-l+1)>1&&s[l]=='0')
		return false;
	return true;
}
inline void check(int x1,int x2)
{
	if(x1<1||x1>n||x2<1||x2>n)
		return;
	if(max(x1-1,x2-x1)!=n-x2+1&&max(x1-1,x2-x1)+1!=n-x2+1)
		return;
	if(!legal(1,x1-1)||!legal(x1,x2-1)||!legal(x2,n))
		return;
	pair<int,int> a,b;
	register int i;
	a=hash(1,x1-1);b=hash(x1,x2-1);
	if(mp((a.fi+b.fi)%mod1,(a.se+b.se)%mod2)==hash(x2,n))
	{
		for(i=1;i<=x1-1;i++)
			putchar(s[i]);
		putchar('+');
		for(i=x1;i<=x2-1;i++)
			putchar(s[i]);
		putchar('=');
		for(i=x2;i<=n;i++)
			putchar(s[i]);
		putchar('\n');
		exit(0);
	}
	return;
}
signed main()
{
	register int i;
	scanf("%s",s+1);
	n=strlen(s+1);
	powb[0]=mp(1,1);
	for(i=1;i<=n;i++)
	{
		h[i]=mp(((ll)h[i-1].fi*base+s[i]-'0')%mod1,((ll)h[i-1].se*base+s[i]-'0')%mod2);
		powb[i]=mp((ll)powb[i-1].fi*base%mod1,(ll)powb[i-1].se*base%mod2);
	}
	for(i=1;i*2<=n;i++)
	{
		check(i+1,n-i+1);
		check(i+1,n-i);
		if((n-i)&1)
			check(i+1,n-(n-i)/2);
		else
			check(i+1,n-(n-i)/2+1);
	}
	puts("???");
	return 0;
}