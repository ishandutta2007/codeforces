#include<bits/stdc++.h>//{{{
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
    x=0;char c=getchar(),dp=0;
    for(;c<48||c>57;c=getchar()) if(!(c^45)) dp=1;
    for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
    dp?x=-x:x;
}
template<typename T,typename...L>inline void read(T &x,L&...l) {read(x),read(l...);}/*}}}*/
#define int long long
char ch[15];int n,vl[15],X;
inline int ksm(int x,int q) {int r=1;for(;q;q>>=1,x*=x) if(q&1) r*=x;return r;}
inline int get(int x) {int r=1;while(x) r*=x%10,x/=10;return r;}
signed main()
{
	scanf("%s",ch+1),n=strlen(ch+1),vl[0]=1;
	for(int i=1;i<=n;i++) ch[i]^=48,vl[i]=vl[i-1]*ch[i];
	for(int i=1;i<=n;i++) X=X*10+ch[i];
	int mx=0,ff=0;for(int i=0;i<=n;i++)
	{
		//printf("! %d : %d\n",i,ksm(9,i)*get(X/ksm(10,i)-ff));
		mx=max(mx,ksm(9,i)*get(X/ksm(10,i)-ff));
		if(vl[i]!=9) ff=1;
	}
	return printf("%lld\n",max(mx,vl[n])),0;
}