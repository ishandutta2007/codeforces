//
#include<bits/stdc++.h>
using namespace std;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(!(c^45)) f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}
// typedef set<pair<int,int> >::iterator IT;
// struct edge{int to,nxt;}e[50005];int et,head[50005],tag[50005][505],vl1[50005][505],vl2[50005][505];
// struct node{int tim,addw1,addw2;};queue<node>q[50005];int bf1[50005],bf2[50005];
// int n,Q,FROG,fa[50005],a[50005],r1[50005],r2[50005],qry[50005],dep[50005],w1[50005],w2[50005];
// set<pair<int,int> >st;vector<int>v[50005];
// inline void adde(int x,int y) {e[++et]=(edge){y,head[x]},head[x]=et;}
// inline void dfs(int x,int d) {dep[x]=d;for(int i=head[x];i;i=e[i].nxt) dfs(e[i].to,d+1);}
// inline void SolveBig(int x,const set<pair<int,int> >&f)
// {
// 	int nw=(*f.begin()).first;++r1[nw],r2[nw]+=dep[x]-dep[(*f.begin()).second];
// 	while(1)
// 	{
// 		IT v=f.lower_bound(make_pair(nw+a[x],-1));if(v==f.end()) break;
// 		int y=v->second,id=v->first;
// 		//printf("%d th : %d <- %d\n",id,y,x);
// 		++r1[id],r2[id]+=dep[x]-dep[y],nw=id;
// 	}
// }
// inline void DfsBig(int x,const set<pair<int,int> >&f)
// {
// 	set<pair<int,int> >nw=f;
// 	for(int i=0;i<(int)v[x].size();i++) nw.insert(make_pair(v[x][i],x));
// 	if(a[x]>=FROG) SolveBig(x,nw);
// 	for(int i=head[x];i;i=e[i].nxt) DfsBig(e[i].to,nw);
// }
// inline void InitLow(int x)
// {
// 	w1[x]=1,w2[x]=0;if(a[x]<FROG) vl1[x][a[x]]++;
// 	for(int i=head[x];i;i=e[i].nxt) InitLow(e[i].to),w2[x]+=w2[e[i].to]+w1[e[i].to],w1[x]+=w1[e[i].to];
// 	for(int i=head[x];i;i=e[i].nxt) for(int w=1;w<=FROG;w++) vl1[x][w]+=vl1[e[i].to][w],vl2[x][w]+=vl2[e[i].to][w]+vl1[e[i].to][w];
// }
// int main()
// {
// 	read(n),read(Q),FROG=400,memset(tag,-1,sizeof(tag));
// 	for(int i=1;i<=n;i++) read(a[i]);
// 	for(int i=2;i<=n;i++) read(fa[i]),adde(fa[i],i);
// 	for(int i=1;i<=Q;i++) read(qry[i]),v[qry[i]].push_back(i);
// 	st.clear(),dfs(1,0),DfsBig(1,st),InitLow(1);
// 	memcpy(bf1,w1,sizeof(bf1)),memcpy(bf2,w2,sizeof(bf2));
// 	for(int i=1,x=qry[i];i<=Q;i++,x=qry[i]) if(a[x]<FROG)
// 	{
// 		while(!q[x].empty()&&q[x].front().tim<=i) w1[x]+=q[x].front().addw1,w2[x]+=q[x].front().addw2,q[x].pop();
// 		int W1=w1[x],W2=w2[x];w1[x]=w2[x]=0;
// 		//for(int y=x;y;y=fa[y]) qwq=max(qwq,tag[y]);
// 		//if(qwq==-1);else if(i-qwq>=FROG) w1[x]=bf1[x],w2[x]=bf2[x];else
// 		//{
// 		//	int qwq1=0,qwq2=0,len=i-qwq;
// 		//	for(int i=1;i<=len;i++) qwq1+=vl1[x][i],qwq2+=vl2[x][i];
// 		//	w1[x]=qwq1,w2[x]=qwq2;
// 		//}
// 		for(int j=1;j<=FROG;j++) if(~tag[x][j]&&tag[x][j]+j>=i) tag[x][j]=i,w1[x]+=vl1[x][j],w2[x]+=vl2[x][j];
// 		r1[i]+=w1[x],r2[i]+=w2[x];
// 		//for(int j=1;j<=n;j++) printf("<%d,%d>%c",w1[j],w2[j],j==n?'\n':' ');
// 		for(int y=x,ds=0;y;y=fa[y],ds++) w1[y]-=W1,w2[y]-=W2+ds*W1,q[y].push((node){i+a[x],W1,W2+ds*W1});
// 	}
// 	for(int i=1;i<=Q;i++) printf("%d %d\n",r2[i],r1[i]);
// 	return 0;
// }
struct edge{int to,nxt;}e[100005];int et,head[50005];
int n,Q,a[50005],ans[50005],tag[50005],r1[50005],r2[50005];vector<int>q[50005];
inline void adde(int x,int y) {e[++et]=(edge){y,head[x]},head[x]=et;}
inline void dfs(int x,int dep)
{
	for(auto i:q[x]) tag[i]=dep;
	for(int i=1;i<=Q;i++) if(tag[i]) r1[i]+=dep-tag[i],r2[i]++,i+=a[x]-1;
	for(int i=head[x];i;i=e[i].nxt) dfs(e[i].to,dep+1);
	for(auto i:q[x]) tag[i]=0;
}
int main()
{
	read(n),read(Q);
	for(int i=1;i<=n;i++) read(a[i]);
	for(int i=2,f;i<=n;i++) read(f),adde(f,i);
	for(int i=1,x;i<=Q;i++) read(x),q[x].push_back(i);
	dfs(1,1);for(int i=1;i<=Q;i++) printf("%d %d\n",r1[i],r2[i]);
	return 0;
}