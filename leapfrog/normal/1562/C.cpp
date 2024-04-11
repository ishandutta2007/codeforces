#include<bits/stdc++.h>//{{{
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
    x=0;char c=getchar(),f=0;
    for(;c<48||c>57;c=getchar()) if(!(c^45)) f=1;
    for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
    f?x=-x:x;
}
template<typename T,typename...L>inline void read(T &x,L&...l) {read(x),read(l...);}/*}}}*/
int n;char ch[500005];
inline void solve()
{
	read(n),scanf("%s",ch+1);char fg=0;
	for(int i=1;i<=n;i++) fg|=ch[i]=='0';
	if(!fg) return printf("%d %d %d %d\n",1,n-1,2,n),void();
	int wh=0;for(int i=1;i<=n;i++) if(ch[i]=='0') {wh=i;break;}
	//if((n&1)&&wh==(n+1)>>1) return printf("%d %d %d %d\n",1,wh-1,wh+1,n),void();
	if(wh>n/2) printf("%d %d %d %d\n",1,wh,1,wh-1);
	else printf("%d %d %d %d\n",wh,n,wh+1,n);
}
int main() {int Ca;for(read(Ca);Ca--;) solve();return 0;}