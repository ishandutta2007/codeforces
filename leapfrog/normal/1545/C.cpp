//{{{
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<48||c>57;c=getchar()) if(!(c^45)) f=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	f?x=-x:x;
}
template<typename T,typename...L>inline void read(T &x,L&...l) {read(x),read(l...);}//}}}
const int P=998244353;vector<int>as;
int n,a[1005][505],c[505][505];char vs[505];
inline void solve()
{
	read(n);for(int i=1;i<=n;i++) {vs[i]=vs[i+n]=0;for(int j=1;j<=n;j++) c[i][j]=0;}
	for(int i=1;i<=n+n;i++) for(int j=1;j<=n;j++) read(a[i][j]),c[a[i][j]][j]++;
	int rs=1;as.clear();for(int i=1;i<=n;i++)
	{
		int fg=0;for(int j=1;j<=n+n&&!fg;j++) if(!vs[j])
			for(int k=1;k<=n;k++) if(c[a[j][k]][k]==1) fg=j;
		if(!fg) {rs=2ll*rs%P,fg++;while(vs[fg]) fg++;}
		as.push_back(fg),vs[fg]=1;
		for(int j=1;j<=n+n;j++) if(!vs[j])
		{
			for(int k=1;k<=n;k++) if(a[j][k]==a[fg][k]) {vs[j]=1;break;}
			if(vs[j]) for(int k=1;k<=n;k++) c[a[j][k]][k]--;
		}
		for(int j=1;j<=n;j++) c[a[fg][j]][j]--;
	}
	printf("%d\n",rs);for(auto x:as) printf("%d ",x);
	putchar('\n');
}
int main() {int Ca;for(read(Ca);Ca--;) solve();return 0;}