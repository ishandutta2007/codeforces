//
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<48||c>57;c=getchar()) if(!(c^45)) f=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	f?x=-x:x;
}
int n;inline char check(int x) {for(int i=2,e=sqrt(x);i<=e;i++) if(x%i==0) return 0;return 1;}
inline int ksm(int x,int q,int P) {int r=1;for(;q;q>>=1,x=1ll*x*x%P) if(q&1) r=1ll*r*x%P;return r;}
int main()
{
	read(n);if(n==1) return puts("YES\n1"),0;else if(n==4) return puts("YES\n1\n3\n2\n4"),0;else if(!check(n)) return puts("NO"),0;
	printf("YES\n1\n");for(int i=2;i<n;i++) printf("%lld\n",1ll*i*ksm(i-1?i-1:1,n-2,n)%n);printf("%d\n",n);
}