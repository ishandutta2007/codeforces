#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-fdelete-null-pointer-checks")
#include<cstdio>
#include<vector>
#include<algorithm>
#include<random>
#include<chrono>
#include<ctime>
using namespace std;
const int MAXN=1e5+5;
mt19937 rnd(chrono::system_clock::now().time_since_epoch().count());
int n,q;
vector<int> son[MAXN];
#define lc ch[u][0]
#define rc ch[u][1]
namespace Treap{
	int rt,ch[MAXN][2],fa[MAXN],tag[MAXN],mx[MAXN],siz[MAXN],val[MAXN];
	inline void add(int u,int v){
		if(u){
			val[u]+=v;
			mx[u]+=v;
			tag[u]+=v;
		}
	}
	inline void pushup(int u){
		siz[u]=siz[lc]+siz[rc]+1;
		mx[u]=max(val[u],max(mx[lc],mx[rc]));
	}
	inline void pushdwn(int u){
		if(tag[u]){
			add(lc,tag[u]);
			add(rc,tag[u]);
			tag[u]=0;
		}
	}
	void Split(int u,int &x,int &y,int k){
		if(!u){
			x=y=0;
			return ;
		}
		pushdwn(u);
		fa[u]=0;
		if(siz[lc]<k){
			x=u;
			Split(rc,ch[x][1],y,k-siz[lc]-1);
			fa[ch[x][1]]=x;
		}else{
			y=u;
			Split(lc,x,ch[y][0],k);
			fa[ch[y][0]]=y;
		}
		pushup(u);
		return ;
	}
	int Merge(int x,int y){
		if(!x||!y) return x+y;
		if(rnd()%(siz[x]+siz[y])<siz[x]){
			pushdwn(x);
			ch[x][1]=Merge(ch[x][1],y);
			fa[ch[x][1]]=x;
			pushup(x);
			return x;
		}
		pushdwn(y);
		ch[y][0]=Merge(x,ch[y][0]);
		fa[ch[y][0]]=y;
		pushup(y);
		return y;
	}
	void Build(int u){
		siz[u]=1;
		mx[u]=val[u];
		rt=Merge(rt,u);
	}
	int Query(int u,int k){
		pushdwn(u);
		if(rc&&mx[rc]>=k) return Query(rc,k);
		if(val[u]>=k) return u;
		return Query(lc,k);
	}
	int getrk(int u){
		int res=siz[lc]+1;
		while(fa[u]){
			int f=fa[u];
			if(ch[f][1]==u) res+=siz[ch[f][0]]+1;
			u=f;
		}
		return res;
	}
	void Modify(int f,int sf,int u,int s,int k){
		int df=getrk(f),du=getrk(u);
		int a,b,c,d;
		Split(rt,a,b,du-1);
		Split(b,b,c,s);
		Split(c,c,d,df+sf-du-s);
		add(b,1-k);
		rt=Merge(Merge(a,c),Merge(b,d));
		return ;
		a=Merge(a,c);
		b=Merge(b,d);
		rt=Merge(a,b);
	}
	void Print(int u){
		if(!u) return ;
		pushdwn(u);
		Print(lc);
		printf("%d lc %d rc %d fa %d\n",u,lc,rc,fa[u]);
		Print(rc);
		return ;
	}
	void Debug(){
		Print(rt);
		puts("");
	}
}
namespace LCT{
	int ch[MAXN][2],fa[MAXN],siz[MAXN],val[MAXN],tag[MAXN];
	inline bool chk(int u){
		return ch[fa[u]][1]==u;
	}
	inline bool nrt(int u){
		return ch[fa[u]][chk(u)]==u;
	}
	inline void add(int u,int v){
		val[u]+=v;
		tag[u]+=v;
	}
	inline void pushup(int u){
		siz[u]=siz[lc]+siz[rc]+1;
	}
	inline void pushdwn(int u){
		if(tag[u]){
			add(lc,tag[u]);
			add(rc,tag[u]);
			tag[u]=0;
		}
	}
	inline void rotate(int u){
		bool x=chk(u);
		int f=fa[u],ff=fa[f],y=ch[u][!x];
		pushdwn(f);
		pushdwn(u);
		if(nrt(f)) ch[ff][chk(f)]=u;
		fa[u]=ff;
		ch[u][!x]=f;
		fa[f]=u;
		ch[f][x]=y;
		fa[y]=f;
		pushup(f);
		pushup(u);
	}
	void pushall(int u){
		if(nrt(u)) pushall(fa[u]);
		pushdwn(u);
	}
	void Splay(int u){
		pushall(u);
		for(int &f=fa[u]; nrt(u); rotate(u))
			if(nrt(f)) rotate(chk(u)==chk(f)?f:u);
	}
	void Access(int u){
		for(int x=0; u; x=u,u=fa[u])
			Splay(u),rc=x,pushup(u);
	}
	int QueryDis(int x,int y){
		Access(x);
		Splay(x);
		int res=siz[x];
		Access(y);
		Splay(y);
		res+=siz[y];
		Splay(x);
		if(fa[x]) x=fa[x];
		res-=siz[ch[x][0]]+1<<1;
		return res;
	}
	int QueryKth(int u,int k){
		pushdwn(u);
		if(k<=siz[lc]) return QueryKth(lc,k);
		if(k==siz[lc]+1) return u;
		return QueryKth(rc,k-siz[lc]-1);
	}
	void Modify(int u,int k){
		Access(u);
		Splay(u);
		int f=QueryKth(u,siz[u]-1),ff=QueryKth(u,siz[u]-k),s=val[u],sf=val[ff];
		Splay(ff);
		add(ch[ff][0],s);
		val[ff]+=s;
		Splay(f);
		add(ch[f][0],-s);
		val[f]-=s;
		ch[f][1]=0;
		fa[u]=ff;
		pushup(f);
		Treap::Modify(ff,sf,u,s,k);
	}
	int QueryFa(int u,int k){
		Access(u);
		Splay(u);
		return QueryKth(u,k+1);
	}
}
#undef lc
#undef rc
void Dfs(int u){
#define siz LCT::val
#define dep Treap::val
#define fa LCT::fa
	siz[u]=1;
	Treap::Build(u);
	for(int v:son[u]){
		dep[v]=dep[u]+1;
		fa[v]=u;
		Dfs(v);
		siz[u]+=siz[v];
	}
	return ;
#undef siz
#undef dep
#undef fa
}
int main(){
	//freopen("in","r",stdin);
	scanf("%d%d",&n,&q);
	for(int i=1; i<=n; i++){
		int s,x;
		scanf("%d",&s);
		while(s--){
			scanf("%d",&x);
			son[i].push_back(x);
		}
	}
	Dfs(1);
	int ans=0;
	while(q--){
		int op,x,y;
		scanf("%d%d",&op,&x);
		if(op==1){
			scanf("%d",&y);
			printf("%d\n",LCT::QueryDis(x,y));
		}
		if(op==2){
			scanf("%d",&y);
			LCT::Modify(x,y);
		}
		if(op==3){
			y=Treap::Query(Treap::rt,x);
			printf("%d\n",ans=LCT::QueryFa(y,x));
		}
		//Treap::Debug();
		//if((double)(clock())/CLOCKS_PER_SEC>3.9) break;
	}
	return 0;
}