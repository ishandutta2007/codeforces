//
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	char c=getchar();int f=0;x=0;
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<3)+(x<<1)+(c^48);
	f?x=-x:x;
}
int T,n,a,b,c,d;
int main() {for(read(T);T--;) read(a),read(b),read(c),read(d),printf("%d\n",max(a+b,c+d));}