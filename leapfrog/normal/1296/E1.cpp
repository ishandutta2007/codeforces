#include<bits/stdc++.h>
using namespace std;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}
int n,nt,a[200005],g[35];char c[200005];
int main()
{
	read(n),scanf("%s",c+1),nt=0,memset(g,0,sizeof(g)),a[0]=0;
	for(int i=n;i;i--)
	{
		a[i]=g[c[i]-'a']+1,nt=max(nt,a[i]);
		for(int j=c[i]-'a'+1;j<26;j++) g[j]=max(g[j],a[i]);
	}
	if(nt>2) return puts("NO"),0;else puts("YES");
	for(int i=1;i<=n;i++) putchar((a[i]-1)^48);
	return putchar('\n'),0;
}