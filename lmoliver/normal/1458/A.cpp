#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef vector<int> V;
#define F(N,S,E) for(int N=(int)(S);N<=(int)(E);N++)
#define R(N,S,E) for(int N=(int)(S);N>=(int)(E);N--)
#define D(N,E) for(int N=0;N<(int)(E);N++)
LL read(){LL x;scanf("%lld",&x);return x;}

LL gcd(LL a,LL b){return b?gcd(b,a%b):a;}
const int N=2.1e5;
LL a[N],b[N];
int main(){
	int n=read(),m=read();
	F(i,1,n)a[i]=read();
	F(i,1,m)b[i]=read();
	LL qaq=0;
	F(i,1,n-1)qaq=gcd(qaq,abs(a[i]-a[i+1]));
	F(i,1,m)printf("%lld ",gcd(a[1]+b[i],qaq));
	printf("\n");
	// a1+b,a2+b...
	// =a1+b,a1-a2,...
	return 0;
}