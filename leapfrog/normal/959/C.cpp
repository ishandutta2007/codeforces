//{{{
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),bz=0;
	for(;c<48||c>57;c=getchar()) if(!(c^45)) bz=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	bz?x=-x:x;
}/*}}}*/
int main()
{
	int n;read(n);
	if(n<=5) puts("-1");else {puts("1 2\n2 3\n2 4");for(int i=5;i<=n;i++) printf("%d 4\n",i);}
	for(int i=1;i<n;i++) printf("%d %d\n",i,i+1);
	return 0;
}