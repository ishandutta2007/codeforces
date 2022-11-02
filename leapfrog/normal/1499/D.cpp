//
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<48||c>57;c=getchar()) if(!(c^45)) f=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	f?x=-x:0;
}
int T,C,D,X,num[20000005],pw[15];
inline void init()
{
	for(int i=2;i<=20000000;i++)
	{
		if(num[i]) continue;
		for(int j=i;j<=20000000;j+=i) num[j]++;
	}
	pw[0]=1;for(int i=1;i<=10;i++) pw[i]=pw[i-1]<<1;
}//lcm(a,b)=(x/g+d)/c*g
inline int solve(int g) {int q;if((X/g+D)%C) return 0;else return q=(X/g+D)/C,pw[num[q]];}
inline void solve()
{
	read(C),read(D),read(X);ll res=0;
	for(int i=1;i*i<=X;i++) if(X%i==0) {res+=solve(i);if(i*i!=X) res+=solve(X/i);}
	printf("%lld\n",res);
}
int main() {for(init(),read(T);T--;) solve();return 0;}