//{{{
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}/*}}}*/
int n,m,rs[300005],at,bt,st[300005];//0(,1)
struct node{int id,ps;char fg;char operator<(node b) const {return ps<b.ps;}}a[300005],b[300005];
inline void work(int n,node *a)
{
	int tp=0;for(int i=1;i<=n;i++) if(!a[i].fg) st[++tp]=i;
	else if(!tp) a[i].fg^=1,a[i].ps=-a[i].ps,st[++tp]=i;
	else rs[a[st[tp]].id]=rs[a[i].id]=(a[i].ps-a[st[tp]].ps)>>1,tp--;
	for(int i=tp;i>1;i-=2) rs[a[st[i]].id]=rs[a[st[i-1]].id]=m-((a[st[i]].ps+a[st[i-1]].ps)>>1);
}
inline void solve()
{
	read(n),read(m),at=bt=0;for(int i=1;i<=n;i++) read(a[i].ps),a[i].id=i;
	for(int i=1;i<=n;i++) scanf("%s",&a[i].fg),a[i].fg=(a[i].fg=='L');
	sort(a+1,a+n+1);for(int i=1;i<=n;i++) if(a[i].ps&1) a[++at]=a[i];else b[++bt]=a[i];
	memset(rs+1,-1,n<<2),work(at,a),work(bt,b);
	for(int i=1;i<=n;i++) printf("%d%c",rs[i],i==n?'\n':' ');
}
int main() {int Ca;for(read(Ca);Ca--;) solve();return 0;}