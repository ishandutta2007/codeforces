//
#include<bits/stdc++.h>
#define int long long
using namespace std;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}
int n,t[105],sm=0,gx[1000005],K;char c[1000005];
inline int ksm(int x,int q) {int r=1;for(;q;q>>=1,x*=x) if(q&1) r*=x;return r;}
signed main()
{
	read(n),read(K),scanf("%s",c+1);for(int i=1;i<=n;i++) c[i]-='a',gx[i]=ksm(2,c[i]),sm-=gx[i];
//	if(n==1) {if(ksm(2,c[1])==K) puts("Yes");else puts("No");return 0;}
//	if(n==2) {if(ksm(2,c[2])-ksm(2,c[1])==K) puts("Yes");else puts("No");return 0;}
	sm+=gx[n]*2,K-=sm;for(int i=1;i<=n;i++) gx[i]*=2,c[i]++;
	for(int i=1;i<n-1;i++) t[(int)c[i]]++;
	for(int i=40;~i;i--) {int qwq=min(t[i],K/ksm(2,i));qwq=max(qwq,0ll),K-=qwq*ksm(2,i);}
	if(K) return puts("No"),0;else return puts("Yes"),0;
}