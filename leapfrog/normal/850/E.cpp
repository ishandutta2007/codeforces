//{{{
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<48||c>57;c=getchar()) if(!(c^45)) f=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	f?x=-x:x;
}
template<typename T,typename...L>inline void read(T &x,L&...l) {read(x),read(l...);}//}}}
const int N=1048577,P=1e9+7;int n,a[N];char ch[N];
inline void FWT(int n,int *a,int fg)
{
	for(int d=1;d<n;d<<=1) for(int i=0;i<n;i+=(d<<1)) for(int j=0;j<d;j++)
		{int x=a[i+j],y=a[i+j+d];a[i+j]=1ll*(x+y)*fg%P,a[i+j+d]=1ll*(x-y+P)*fg%P;}
}
inline int bit(int x) {int rs=0;for(;x;rs+=(x&1),x>>=1);return rs;}
int main()
{
	read(n),scanf("%s",ch);
	for(int i=0;i<(1<<n);i++) a[i]=ch[i]^48;
	FWT(1<<n,a,1);for(int i=0;i<(1<<n);i++) a[i]=1ll*a[i]*a[i]%P;
	FWT(1<<n,a,(P+1)>>1);int rs=0;
	for(int i=0;i<(1<<n);i++) rs=(rs+(1ll<<(n-bit(i)))*a[i])%P;
	return printf("%lld\n",rs*3ll%P),0;
}