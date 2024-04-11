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
int n,m,Q,fa[500005],de[500005],nid[500005],a[500005];char rs[500005];
struct edge{int x,y,w,id;char tg;}e[500005];int ut,tn[500005];
struct node{int id;vector<int>v;};vector<node>q[500005];
struct dsub{int x,y,de;}st[500005];int tp;
inline char cmp(edge a,edge b) {return a.w<b.w;}
inline char cpp(int a,int b) {return e[a].w<e[b].w;}
inline int getf(int x) {return fa[x]==x?x:getf(fa[x]);}
inline void mrg(int x,int y)
{
	x=getf(x),y=getf(y);if(x==y) return;else if(de[x]>de[y]) swap(x,y);
	st[++tp]=(dsub){x,y,de[y]},fa[x]=y,de[y]+=de[x]==de[y];
}
inline void pop() {fa[st[tp].x]=st[tp].x,de[st[tp].y]=st[tp].de,tp--;}
int main()
{
	read(n),read(m);for(int i=1;i<=m;i++) read(e[i].x),read(e[i].y),read(e[i].w),e[i].id=i;
	read(Q),sort(e+1,e+m+1,cmp);for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<=m;i++) nid[e[i].id]=i,tn[++ut]=e[i].w;
	sort(tn+1,tn+ut+1),ut=unique(tn+1,tn+ut+1)-tn-1;
	for(int i=1;i<=m;i++) e[i].w=lower_bound(tn+1,tn+ut+1,e[i].w)-tn;
	for(int K,xtw=1;xtw<=Q;xtw++)
	{
		read(K);for(int i=1;i<=K;i++) read(a[i]),a[i]=nid[a[i]];
		vector<int>v;sort(a+1,a+K+1,cpp);
		//for(int i=1;i<=n;i++) printf("%d%c",a[i],i==n?'\n':' ');
		for(int l=1,r=l;l<=K;l=++r)
		{
			while(e[a[l]].w==e[a[r+1]].w) r++;
			vector<int>v;for(int i=l;i<=r&&i<=K;i++) v.push_back(a[i]);
			q[e[a[l]].w].push_back((node){xtw,v});
		}
	}
	//puts("------------");for(int i=1;i<=m;i++) printf("%d %d %d\n",e[i].x,e[i].y,e[i].w);
	for(int i=1,j=1;j<=ut;j++)
	{
		//printf("nwj : %d\n",j);
		//for(int i=1;i<=n;i++) printf("%d%c",getf(i),i==n?'\n':' ');
		int qwq=tp;for(auto &nw:q[j])
		{
			for(auto &x:nw.v) if(getf(e[x].x)==getf(e[x].y)) rs[nw.id]=1;else mrg(e[x].x,e[x].y);
			//printf("%d : ",nw.id);{for(auto x:nw.v) printf("%d ",x);}putchar('\n');
			while(tp>qwq) pop();
		}
		for(;e[i].w==j;i++) if(getf(e[i].x)!=getf(e[i].y)) mrg(e[i].x,e[i].y);
	}
	for(int i=1;i<=Q;i++) if(rs[i]) puts("NO");else puts("YES");
	return 0;
}