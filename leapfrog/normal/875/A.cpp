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
inline int calc(int x) {int r=0;while(x) r+=x%10,x/=10;return r;}
int a[100005],rt;
int main()
{
	int n;read(n);for(int i=n-81;i<=n;i++) if(i>0&&calc(i)+i==n) a[++rt]=i;
	printf("%d\n",rt);for(int i=1;i<=rt;i++) printf("%d\n",a[i]);
	return 0;
}