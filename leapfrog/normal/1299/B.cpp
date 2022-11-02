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
int n,X[100005],Y[100005];
inline ll ds(int a,int b) {return 1ll*(X[a]-X[b])*(X[a]-X[b])+1ll*(Y[a]-Y[b])*(Y[a]-Y[b]);}
inline char chk(int a,int b,int x,int y)
{
	if(X[a]-X[b]!=X[x]-X[y]) return 0;
	if(Y[a]-Y[b]!=Y[x]-Y[y]) return 0;
	return 1;
}
int main()
{
	read(n);for(int i=1;i<=n;i++) read(X[i]),read(Y[i]);
	if(n&1) return puts("NO"),0;else X[n+1]=X[1],Y[n+1]=Y[1];
	for(int i=1;i<=(n>>1);i++) if(!chk(i,i+1,i+(n>>1)+1,i+(n>>1))) return puts("NO"),0;
	return puts("YES"),0;
}