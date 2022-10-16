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
int n,q,L[1200002],R[1200002],stk[1200002],tp,pos[1200002],rrt,tot,tim,dep[1200002],dfn[1200002],son[1200002],siz[1200002],head[1200002],cnt,fa[1200002],top[1200002],rt[600002],sz[2400002],ls[2400002],rs[2400002],num[1200002],SS[1200002];
inline void ins(re int &p,re int l,re int r,re int x){
	if(!p)p=++tot;++sz[p];
	if(l==r)return;
	re int mid=l+r>>1;
	if(x<=mid)ins(ls[p],l,mid,x);
	else ins(rs[p],mid+1,r,x);
}
inline int ask(re int p,re int l,re int r,re int x,re int y){
	if(l>=x&&r<=y)return sz[p];
	re int mid=l+r>>1,s=0;
	if(x<=mid)s+=ask(ls[p],l,mid,x,y);
	if(y>mid)s+=ask(rs[p],mid+1,r,x,y);
	return s;
}
struct edge{int to,next;}e[1200002];
inline void add(re int x,re int y){e[++cnt]=(edge){y,head[x]},head[x]=cnt;}
ll f[1200002],c[1200002];
char s[1200002];
vector<int>V[1200002];
vector<ll>S[1200002];
inline int build(re int l,re int r){
	++tot;re int x=tot;pos[l]=pos[r]=x;
	for(re int i=l+1,y;i<r;++i){
		if(s[i]=='.')pos[i]=x;
		else V[x].push_back(i),add(x,y=build(i,R[i])),num[y]=V[x].size(),i=R[i];
	}
	SS[x]=V[x].size();
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
inline void dfs4(re int x){
	vector<int>tmp;dfn[x]=++tim;
	for(re int i=head[x];i;i=e[i].next)tmp.push_back(e[i].to);
	reverse(tmp.begin(),tmp.end());
	for(re int i=0;i<tmp.size();++i)dfs4(tmp[i]);
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
inline void addd(re int x,re int y){
	for(;x<=n;x+=x&(-x))c[x]+=y;
}
inline ll ask(re int x,re ll s=0){
	for(;x;x^=x&(-x))s+=c[x];
	return s;
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
	rrt=build(0,n);
	dfs1(rrt,rrt),dfs2(rrt,rrt),dfs3(rrt,rrt),dfs4(rrt);
	tot=0;
	while(q--){
		re int o=read(),l=read()+nn,r=read()+nn;
		if(o==1){
			re int x=pos[l];
			ins(rt[fa[x]],1,V[fa[x]].size(),num[x]);
			addd(dfn[fa[x]],SS[fa[x]]),--SS[fa[x]];
			continue;
		}
		if(pos[l]==pos[r]){
			printf("%lld\n",f[pos[l]]-ask(dfn[pos[l]]+siz[pos[l]]-1)+ask(dfn[pos[l]]-1));
			continue;
		}
		re int x=lca(pos[l],pos[r]);
		re int p1=lower_bound(V[x].begin(),V[x].end(),l)-V[x].begin(),p2=lower_bound(V[x].begin(),V[x].end(),r)-V[x].begin()-1;
		re int len=p2-p1+1;
		int tt=ask(rt[x],1,V[x].size(),p1+1,p2+1);
		len-=tt;
		printf("%lld\n",S[x][p2]-(p1?S[x][p1-1]:0)+1ll*(len-1)*(len)/2-ask(dfn[pos[r]]+siz[pos[r]]-1)+ask(dfn[pos[l]]-1)-tt);
	}
}