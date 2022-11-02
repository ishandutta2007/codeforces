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
typedef set<pair<int,int> >::iterator IT;set<pair<int,int> >st;
const int N=300005;struct edge{int to,nxt;}e[N];int et,head[N];
int n,dt,L[N],R[N],ans,cn,fg[N<<1],vl[N<<1],vr[N<<1];vector<int>E[N];
inline void adde(int x,int y) {e[++et]=(edge){y,head[x]},head[x]=et;}
inline void dfs0(int x) {L[x]=++dt;for(auto y:E[x]) dfs0(y);R[x]=++dt;}
inline void ins(int l,int r) {fg[++cn]=1,vl[cn]=l,vr[cn]=r,st.insert(make_pair(l,r));}
inline void del(IT it) {fg[++cn]=0,vl[cn]=it->first,vr[cn]=it->second,st.erase(it);}
inline void back()
{
	if(fg[cn]) st.erase(st.find(make_pair(vl[cn],vr[cn])));
	else st.insert(make_pair(vl[cn],vr[cn]));
}
inline void qwqwq(int l,int r)
{
	if(st.empty()) return ins(l,r);
	IT x=st.lower_bound(make_pair(l,r));
	if(x!=st.end()&&x->second<r) return;else if(x==st.begin()) return ins(l,r);
	x--;if(r<x->second) return del(x),ins(l,r);else if(l>x->second) return ins(l,r);
}
inline void work(int x)
{
	int id=cn;qwqwq(L[x],R[x]),ans=max(ans,(int)st.size());
	for(int i=head[x];i;i=e[i].nxt) work(e[i].to);
	while(cn>id) back(),cn--;
}
inline void solve()
{
	read(n),et=ans=cn=dt=0;for(int i=1;i<=n;i++) E[i].clear(),head[i]=0;
	for(int i=2,f;i<=n;i++) read(f),adde(f,i);
	for(int i=2,f;i<=n;i++) read(f),E[f].push_back(i);
	dfs0(1),work(1),printf("%d\n",ans);
}
int main() {int Ca;for(read(Ca);Ca--;) solve();return 0;}