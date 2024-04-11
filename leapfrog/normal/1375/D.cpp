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
const int N=1005;int n,a[N],tn[N];vector<int>rs;
inline int Mex() {for(int i=0;i<=n;i++) if(!tn[i]) return i;return 0;}
inline char chk() {for(int i=1;i<n;i++) if(a[i]>a[i+1]) return 1;return 0;}
inline void chg(int w,int c) {tn[a[w]]--,tn[a[w]=c]++,rs.push_back(w);}
inline void solve()
{
	read(n),rs.clear(),memset(tn,0,sizeof(tn));
	for(int i=1;i<=n;i++) read(a[i]),tn[a[i]]++;
	int r=n;while(chk()) {int t=Mex();if(t==r) chg(r--,t);else chg(t+1,t);}
	printf("%d\n",(int)rs.size());for(auto x:rs) printf("%d ",x);puts("");
}
int main() {int Ca;for(read(Ca);Ca--;) solve();return 0;}