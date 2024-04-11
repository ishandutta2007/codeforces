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
int T;int n,a[100005];char vs[100005];pair<int,int>p[1000005];
inline void solve()
{
	read(n),memset(vs+1,0,n<<2);for(int i=1;i<=n;i++) read(a[i]);
	for(int i=1;i<=n;i++) p[i]=make_pair(a[i],i);
	sort(p+1,p+n+1,greater<pair<int,int> >());
	for(int i=1;i<=n;i++)
	{
		int wh=p[i].second;
		while(wh<=n&&!vs[wh]) printf("%d ",a[wh]),vs[wh]=1,wh++;
	}
	putchar('\n');
}
int main() {for(read(T);T--;) solve();return 0;}
//int main() {return solve(),0;}