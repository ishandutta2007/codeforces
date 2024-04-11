#include<bits/stdc++.h>//{{{
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
    x=0;char c=getchar(),f=0;
    for(;c<48||c>57;c=getchar()) if(!(c^45)) f=1;
    for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
    f?x=-x:x;
}
template<typename T,typename...L>inline void read(T &x,L&...l) {read(x),read(l...);}/*}}}*/
int n,P1,T1,P2,T2,P3,L[105],R[105];ll rs=0;
inline int calc(int len)
{
	if(len<=T1) return P1*len;
	else if(len<=T1+T2) return P1*T1+P2*(len-T1);
	else return P1*T1+P2*T2+P3*(len-T2-T1);
}
int main()
{
	read(n,P1,P2,P3,T1,T2);for(int i=1;i<=n;i++) read(L[i],R[i]);
	for(int i=1;i<=n;i++) rs+=(R[i]-L[i])*P1;
	for(int i=1;i<n;i++) rs+=calc(L[i+1]-R[i]);
	return printf("%lld\n",rs),0;
}