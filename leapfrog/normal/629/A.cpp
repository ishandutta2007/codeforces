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
int n;ll r=0;char ch[105][105];
int main()
{
	read(n);for(int i=1;i<=n;i++) scanf("%s",ch[i]+1);
	for(int i=1,cn=0;i<=n;i++,r+=cn*(cn-1)/2,cn=0)
		for(int j=1;j<=n;j++) cn+=ch[i][j]=='C';
	for(int i=1,cn=0;i<=n;i++,r+=cn*(cn-1)/2,cn=0)
		for(int j=1;j<=n;j++) cn+=ch[j][i]=='C';
	return printf("%lld\n",r),0;
}