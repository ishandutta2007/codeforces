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
double F[1<<21|5],p[1<<21|5],rs[1<<21|5];int n,K,tp;
inline int cnt(int x) {int k=0;while(x) k++,x-=x&(-x);return k;}
int main()
{
	read(n),read(K),F[0]=1;for(int i=1;i<=n;i++) scanf("%lf",p+i),tp+=(p[i]>0);
	if(tp<=K) {for(int i=1;i<=n;i++) if(p[i]>0) printf("1 ");else printf("0 ");return putchar('\n'),0;}
	for(int i=0;i<(1<<n);i++)
	{
		double tp=0;if(cnt(i)>K) continue;
		if(cnt(i)==K) {for(int j=0;j<n;j++) if((i>>j)&1) rs[j+1]+=F[i];continue;}
		for(int j=0;j<n;j++) if((i>>j)&1) tp+=p[j+1];
		F[i]/=(1-tp);for(int j=0;j<n;j++) if((i>>j)&1);else F[i|(1<<j)]+=F[i]*p[j+1];
	}
	for(int i=1;i<=n;i++) printf("%.10lf%c",rs[i],i==n?'\n':' ');
	return 0;
}