//{{{
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<48||c>57;c=getchar()) if(!(c^45)) f=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	f?x=-x:x;
}/*}}}*/
int n,m,sm[1000005];char ch[1000005];
int main()
{
	read(n),read(m),scanf("%s",ch+1);
	for(int i=1;i<=n;i++) sm[i]=sm[i-1]+(ch[i]-'a'+1);
	for(int i=1,l,r;i<=m;i++) read(l),read(r),printf("%d\n",sm[r]-sm[l-1]);
	return 0;
}