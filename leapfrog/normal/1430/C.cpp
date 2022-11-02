//
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<48||c>57;c=getchar()) if(!(c^45)) f=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}
int T,n;
inline void solve(int n)
{
	if(n==1) return(void)(puts("1"));
	if(n==2) return(void)(puts("2\n1 2"));
	printf("2\n%d %d\n%d %d\n",n,n-2,n-1,n-1);
	for(int i=n-3;i;i--) printf("%d %d\n",i+2,i);
}
int main() {for(read(T);T--;) read(n),solve(n);return 0;}