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
struct qwqn{int w,x;char operator<(qwqn b) const {return x^b.x?x<b.x:w<b.w;}}a[100005];
set<qwqn>st;int Ca,n,m,K,rs[100005];
inline void solve()
{
	st.clear(),read(n),read(m),read(K);
	for(int i=1;i<=n;i++) read(a[i].x),a[i].w=i;
	sort(a+1,a+n+1);for(int i=1;i<=m;i++) st.insert((qwqn){i,0});
	for(int i=n;i;i--)
	{
		qwqn x=*st.begin();st.erase(st.begin());
		x.x+=a[i].x,rs[a[i].w]=x.w,st.insert(x);
	}
	qwqn x=*st.begin(),y=*--st.end();
	if(y.x-x.x>K) return puts("NO"),void();else puts("YES");
	for(int i=1;i<=n;i++) printf("%d%c",rs[i],i==n?'\n':' ');
}
int main() {for(read(Ca);Ca--;) solve();return 0;}