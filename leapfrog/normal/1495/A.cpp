//
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}
int T,n,a[100005],b[100005],ac,bc;//a mine b worker
inline double ggg(int x,int y) {return sqrt(1.0*x*x+1.0*y*y);}
inline void solve()
{
	read(n),n<<=1,ac=bc=0;
	for(int i=1,x,y;i<=n;i++) {read(x),read(y);if(x) a[++ac]=abs(x);else b[++bc]=abs(y);}
	sort(a+1,a+ac+1),sort(b+1,b+bc+1,greater<int>());double res=0;
	for(int i=1;i<=ac;i++) res+=ggg(a[i],b[bc-i+1]);
	printf("%.15lf\n",res);
}
int main() {for(read(T);T--;) solve();return 0;}