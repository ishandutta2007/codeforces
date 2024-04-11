//
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<48||c>57;c=getchar()) if(!(c^45)) f=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	f?x=-x:0;
}
const int P=998244353;
int n,q,d[200005],s[200005];
inline int ksm(int x,int q=P-2) {int r=1;for(;q;q>>=1,x=1ll*x*x%P) if(q&1) r=1ll*r*x%P;return r;}
inline void solve()
{
	read(n),read(q);for(int i=1;i<=n;i++) read(d[i]);
	sort(d+1,d+n+1);for(int i=1;i<=n;i++) s[i]=(s[i-1]+d[i])%P;
	for(int a,b;q--;)
	{
		read(a),read(b);int x=lower_bound(d+1,d+n+1,b)-d-1;
		int cn=n-x;if(cn<a) {puts("0");continue;}
		int rs=1ll*(s[n]-s[x]+P)*(cn-a)%P*ksm(cn)%P;
		rs=(rs+1ll*s[x]*(cn-a+1)%P*ksm(cn+1))%P;
		printf("%d\n",rs);
	}
}
int main() {solve();return 0;}