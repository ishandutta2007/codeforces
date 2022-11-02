//Coded by Kamiyama_Shiki on 2021.11.03 {{{
//
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
const int N=200005,V=2000005;
struct ${int a,b,m,id;}a[N];vector<$>v[V];int n,tn[N];
struct node{int l,r,id;}b[N];int bt,rs[N];
inline int work(int w)
{
	bt=0;for(auto x:v[w]) b[++bt]=(node){max(0,x.a-x.m),x.a-max(x.m-x.b,0),x.id};
	sort(b+1,b+bt+1,[&](node a,node b){return a.r<b.r||(a.r==b.r&&a.l<b.l);});
	int ls=1,cnt=1;rs[b[1].id]=a[b[1].id].a-b[1].r;
	for(int i=2;i<=bt;i++) {if(b[i].l>b[ls].r) cnt++,ls=i;rs[b[i].id]=a[b[i].id].a-b[ls].r;}
	return v[w].clear(),cnt;
}
inline void solve()
{
	read(n);for(int i=1;i<=n;i++) read(a[i].a,a[i].b,a[i].m),a[i].id=i;
	for(int i=1;i<=n;i++) v[tn[i]=a[i].a+a[i].b-a[i].m].push_back(a[i]);
	int ut=n;sort(tn+1,tn+ut+1),ut=unique(tn+1,tn+ut+1)-tn-1;
	int res=0;for(int i=1;i<=ut;i++) res+=work(tn[i]);
	printf("%d\n",res);for(int i=1;i<=n;i++) printf("%d %d\n",rs[i],a[i].m-rs[i]);
}
int main() {int Ca;for(read(Ca);Ca--;) solve();return 0;}