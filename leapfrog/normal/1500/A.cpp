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
int n,a[200005];pair<int,int>p[5000005];
int main()
{
	read(n);for(int i=1;i<=n;i++) read(a[i]);
	for(int i=1;i<=n;i++) for(int j=i+1;j<=n;j++)
	{
		int s=a[i]+a[j];if(!p[s].first) {p[s]=make_pair(i,j);continue;}
		int x=p[s].first,y=p[s].second;if(x==i||y==j||x==j||y==i) continue;
		return printf("YES\n%d %d %d %d\n",x,y,i,j),0;
	}
	return puts("NO"),0;
}