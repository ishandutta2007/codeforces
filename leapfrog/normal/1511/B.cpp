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
int Ca,a,b,c;
inline int count(int x) {int r=0;while(x) r++,x/=10;return r;}
inline void solve()
{
	read(a),read(b),read(c);int k=1;
	a-=c-1,b-=c-1;while(count(k)^a) k*=3;
	printf("%d",k);for(int i=1;i<c;i++) putchar('0');
	putchar(' '),k=1;while(count(k)^b) k*=3;
	printf("%d",k+1);for(int i=1;i<c;i++) putchar('0');
}
int main() {for(read(Ca);Ca--;) solve(),putchar('\n');return 0;}