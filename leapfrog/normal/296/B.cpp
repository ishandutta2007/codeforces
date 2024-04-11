#include<cstdio>
#include<algorithm>
using namespace std;const int P=1000000007;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(!(c^45)) f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}
int n,tt;char a[100005],b[100005];
inline int work1(char *a,char *b)
{
	int r=1;
	for(int i=1;i<=n;i++)
		if(a[i]=='?'&&b[i]=='?') r=1ll*r*55%P;
		else if(a[i]=='?') r=1ll*r*(b[i]-'0'+1)%P;
		else if(b[i]=='?') r=1ll*r*(10-a[i]+'0')%P;
		else if(a[i]>b[i]) return 0;
	return r;
}
inline int work2(char *a,char *b)
{
	int r=1;
	for(int i=1;i<=n;i++)
		if(a[i]=='?'&&b[i]=='?') r=r*10%P;
		else if(a[i]=='?'||b[i]=='?') continue;
		else if(a[i]!=b[i]) return 0;
	return r;
}
int main()
{
	read(n),scanf("%s%s",a+1,b+1),tt=1;
	for(int i=1;i<=n;i++) if(a[i]=='?') tt=1ll*tt*10%P;
	for(int i=1;i<=n;i++) if(b[i]=='?') tt=1ll*tt*10%P;
	tt=(tt-work1(a,b)-work1(b,a)+work2(a,b)+P)%P;
	return !printf("%d\n",tt);
}