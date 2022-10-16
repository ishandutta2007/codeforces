#include<bits/stdc++.h>
#define ll long long
#define re register
using namespace std;
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
int n,q,L[1200002],R[1200002],stk[1200002],tp,pos[1200002],rt,tot,dep[1200002],son[1200002],siz[1200002],head[1200002],cnt,fa[1200002],top[1200002];
struct edge{int to,next;}e[1200002];
inline void add(re int x,re int y){e[++cnt]=(edge){y,head[x]},head[x]=cnt;}
ll f[1200002];
char s[1200002];
vector<int>V[1200002];
vector<ll>S[1200002];
inline int build(re int l,re int r){
	++tot;re int x=tot;pos[l]=pos[r]=x;
	for(re int i=l+1;i<r;++i){
		if(s[i]=='.')pos[i]=x;
		else V[x].push_back(i),add(x,build(i,R[i])),i=R[i];
	}
	return x;
}
inline void dfs1(re int x,re int y){
	fa[x]=y,dep[x]=dep[y]+1,siz[x]=1;
	for(re int i=head[x];i;i=e[i].next)
		if(e[i].to^y){
			dfs1(e[i].to,x),siz[x]+=siz[e[i].to];
			if(siz[e[i].to]>siz[son[x]])son[x]=e[i].to;
		}
}
inline void dfs2(re int x,re int y){
	top[x]=y;
	if(son[x])dfs2(son[x],y);
	for(re int i=head[x];i;i=e[i].next)
		if(e[i].to^fa[x]&&e[i].to^son[x])
			dfs2(e[i].to,e[i].to);
}
inline void dfs3(re int x,re int y){
	for(re int i=head[x];i;i=e[i].next)
		if(e[i].to^y){
			dfs3(e[i].to,e[i].to);
			S[x].push_back(f[e[i].to]);
			f[x]+=f[e[i].to];
		}
	reverse(S[x].begin(),S[x].end());
	if(S[x].size()>1)f[x]+=1ll*S[x].size()*(S[x].size()-1)/2;
	++f[x];
	for(re int i=1;i<S[x].size();++i)S[x][i]+=S[x][i-1];
}
inline int lca(re int x,re int y){
	while(top[x]^top[y]){
		if(dep[top[x]]<dep[top[y]])swap(x,y);
		x=fa[top[x]];
	}
	return dep[x]<dep[y]?x:y;
}
int main(){
	n=read(),q=read(),scanf("%s",s+1);int nn=n;
	for(re int i=1;i<=n;++i)s[i+n]=s[i];
	for(re int i=1;i<=n;++i)s[i]='(';n+=n;
	for(re int i=1;i<=n;++i){
		if(s[i]=='(')stk[++tp]=i;
		else if(s[i]==')')R[stk[tp]]=i,L[i]=stk[tp],--tp;
	}
	while(tp){
		++n;
		s[n]=')',L[n]=stk[tp],R[stk[tp]]=n,--tp;
	}
	R[0]=n+1,L[n+1]=0;
	++n;
	rt=build(0,n);
	dfs1(rt,rt),dfs2(rt,rt),dfs3(rt,rt);
	while(q--){
		re int o=read(),l=read()+nn,r=read()+nn;
		if(pos[l]==pos[r]){
			printf("%lld\n",f[pos[l]]);
			continue;
		}
		re int x=lca(pos[l],pos[r]);
		re int p1=lower_bound(V[x].begin(),V[x].end(),l)-V[x].begin(),p2=lower_bound(V[x].begin(),V[x].end(),r)-V[x].begin()-1;
		printf("%lld\n",S[x][p2]-(p1?S[x][p1-1]:0)+1ll*(p2-p1)*(p2-p1+1)/2);
	}
}