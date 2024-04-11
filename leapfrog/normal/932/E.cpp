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
const int N=5005,P=1e9+7,I=(P+1)>>1;int n,K,S[N][N];
inline int ksm(int x,int q=P-2) {int r=1;for(;q;q>>=1,x=1ll*x*x%P) if(q&1) r=1ll*r*x%P;return r;}
int main()
{
	read(n),read(K),S[0][0]=S[1][1]=1;int rs=0,pw=ksm(2,n),fc=1;
	for(int i=2;i<=K;i++) for(int j=1;j<=i;j++) S[i][j]=(S[i-1][j-1]+1ll*S[i-1][j]*j)%P;
	for(int i=0;i<=K&&i<=n;i++) rs=(rs+1ll*fc*S[K][i]%P*pw)%P,pw=1ll*pw*I%P,fc=1ll*fc*(n-i)%P;
	return printf("%d\n",rs),0;
}