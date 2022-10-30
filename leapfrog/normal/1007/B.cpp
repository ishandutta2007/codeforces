//{{{
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}/*}}}*/
const int N=100005;int n,Ca,lev[N],pr[N],pc;char pv[N];ll F[N];
inline int gcd(int a,int b) {return b?gcd(b,a%b):a;}
inline void init()
{
	pv[1]=1,F[1]=F[0]=1;for(int i=2;i<N;i++)
	{
		if(!pv[i]) pr[++pc]=i,F[i]=2,lev[i]=2;
		for(int j=1;j<=pc&&i*pr[j]<N;j++)
		{
			if(i%pr[j]) F[i*pr[j]]=F[i]<<1,lev[i*pr[j]]=2;
			else F[i*pr[j]]=F[i]/lev[i]*(lev[i*pr[j]]=lev[i]+1);
			pv[i*pr[j]]=1;if(i%pr[j]==0) break;
		}
	}
}
inline void solve()
{
	int A,B,C;read(A),read(B),read(C);
	int AB=gcd(A,B),AC=gcd(A,C),BC=gcd(B,C),ABC=gcd(A,gcd(B,C));
	ll F1=1ll*F[A]*F[B]*F[C],F2=0,F3=0,F4,F5;//+-+-+
	F2+=(F[AB]-1)*F[AB]/2*F[C];
	F2+=(F[AC]-1)*F[AC]/2*F[B];
	F2+=(F[BC]-1)*F[BC]/2*F[A];
	F3+=F[AB]+F[BC]+F[AC]-F[ABC]*3;
	F3*=F[ABC]*(F[ABC]-1)/2;
	F4=1ll*(F[AB]-F[ABC])*(F[AC]-F[ABC])*(F[BC]-F[ABC]);
	F5=F[ABC]*(F[ABC]-1)+F[ABC]*(F[ABC]-1)*(F[ABC]-2)/6*4;
	printf("%lld\n",F1-F2+F3-F4+F5);
}
int main() {for(init(),read(Ca);Ca--;) solve();return 0;}