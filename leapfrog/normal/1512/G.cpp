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
int n,rs[10000005];ll qw[10000005];
int main()
{
	for(int i=1;i<=10000000;i++) for(int j=i;j<=10000000;j+=i) qw[j]+=i;
	for(int i=1;i<=10000000;i++) if(qw[i]<=10000000&&!rs[qw[i]]) rs[qw[i]]=i;
	int Ca,x;for(read(Ca);Ca--;) read(x),printf("%d\n",rs[x]?rs[x]:-1);
}