//{{{
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<48||c>57;c=getchar()) if(!(c^45)) f=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	f?x=-x:x;
}/*}}}*/
const int P=998244353;int n,F[1000005],s[1000005];
inline int ksm(int x,int q=P-2) {int r=1;for(;q;q>>=1,x=1ll*x*x%P) if(q&1) r=1ll*r*x%P;return r;}
inline int C2(int x) {return 1ll*x*(x+1)%P*499122177%P;}
inline int C3(int x) {return 1ll*x*(x+1)%P*(x+2)%P*166374059%P;}
int main()
{
	read(n),F[0]=1,F[1]=2,s[0]=1,s[1]=3;int rs=0;
	if(n==1) return puts("5"),0;else if(n==2) return puts("31"),0;
	for(int i=2;i<=n;i++) F[i]=(F[i-1]+1ll*F[i-1]*s[i-2]+C2(F[i-1]))%P,s[i]=(s[i-1]+F[i])%P;
	rs=(2ll*F[n]-1+2ll*C3(F[n-1])+2ll*F[n-1]*C2(s[n-2])+2ll*s[n-2]*C2(F[n-1]))%P;
	for(int i=0;i<n-1;i++) rs=(rs+1ll*(F[i]-1)*(F[n-i-1]-F[n-i-2]))%P;
	return printf("%d\n",rs),0;
}