//
//
#include<bits/stdc++.h>
using namespace std;const int X=303;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}
inline char gc() {char c=getchar();while(c!='+'&&c!='-') c=getchar();return c;}
int n,v[200005],tp,st[200005],r[200005];char op[200005],vis[200005];
int main()
{
	read(n),n<<=1;int cnt=0;
	for(int i=1;i<=n;i++) {op[i]=gc();if(op[i]=='-') read(v[i]);}
	for(int i=1;i<=n;i++)
	{
		if(op[i]=='+') {st[++tp]=++cnt;continue;}
		if(tp==0||v[i]<r[st[tp]]||vis[v[i]]) return puts("NO"),0;
		r[st[tp]]=v[i],r[st[tp-1]]=max(r[st[tp-1]],r[st[tp]]),--tp;
	}
	puts("YES");
	for(int i=1;(i<<1)<=n;i++) printf("%d%c",r[i],(i<<1)==n?'\n':' ');
	return 0;
}