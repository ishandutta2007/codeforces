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
int x,y,a,b;
inline void solve()
{
	read(x),read(y),read(a),read(b);
	if(a==b) return printf("%d\n",min(x,y)/a),void();
	(a>b?swap(a,b):void()),(x>y?swap(x,y):void());
	int dx=min((y-x)/(b-a),min(y/b,x/a)),res=dx;y-=b*dx,x-=a*dx;
	int ans=res+min(x,y)/(a+b)*2;
	if(x>=a&&y>=b) x-=a,y-=b,res++,ans=max(ans,res+min(x,y)/(a+b)*2);
	printf("%d\n",ans);
}
int main() {int Ca;for(read(Ca);Ca--;) solve();return 0;}