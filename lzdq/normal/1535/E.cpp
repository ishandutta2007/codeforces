#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN=3e5+5;
int q,a[MAXN],c[MAXN];
int rt=3e5+1;
#define lc ch[u][0]
#define rc ch[u][1]
int fa[MAXN],ch[MAXN][2];
ll val[MAXN],s1[MAXN],s2[MAXN];
bool tag[MAXN];
inline void add(int u){
	val[u]=s1[u]=s2[u]=0;
	tag[u]=1;
}
inline void pushup(int u){
	s1[u]=s1[lc]+s1[rc]+val[u];
	s2[u]=s2[lc]+s2[rc]+val[u]*c[u];
}
inline void pushdwn(int u){
	if(tag[u]){
		add(lc);
		add(rc);
		tag[u]=0;
	}
}
inline bool nrt(int u){
	return ch[fa[u]][0]==u||ch[fa[u]][1]==u;
}
inline bool chks(int u){
	return ch[fa[u]][1]==u;
}
inline void rotate(int u){
	int f=fa[u],ff=fa[f],x=chks(u),y=ch[u][!x];
	if(nrt(f)) ch[ff][chks(f)]=u;
	ch[f][x]=y;
	ch[u][!x]=f;
	if(y) fa[y]=f;
	fa[u]=ff;
	fa[f]=u;
	pushup(f);
	pushup(u);
}
void pushall(int u){
	if(nrt(u)) pushall(fa[u]);
	pushdwn(u);
}
inline void Splay(int u){
	pushall(u);
	for(int &f=fa[u]; nrt(u); rotate(u))
		if(nrt(f)) rotate(chks(u)==chks(f)?f:u);
}
inline void Access(int u){
	for(int p=0; u; u=fa[p=u])
		Splay(u),rc=p,pushup(u);
}
int Query(int u,int y){
	pushdwn(u);
	if(s1[lc]>=y) return Query(lc,y);
	if(y<=s1[lc]+val[u]) return u;
	return Query(rc,y-s1[lc]-val[u]);
}
int main(){
	//freopen("in1.txt","r",stdin);
	scanf("%d%d%d",&q,a+rt,c+rt);
	val[rt]=a[rt];
	pushup(rt);
	for(int i=1; i<=q; i++){
		int op,x,y;
		scanf("%d%d%d",&op,&x,&y);
		if(!x) x=rt;
		//printf("i %d\n",i);
		if(op==1){
			fa[i]=x;
			val[i]=y;
			scanf("%d",c+i);
			pushup(i);
		}else{
			Access(x);
			Splay(x);
			if(y>s1[x]) y=s1[x];
			printf("%d ",y);
			if(!y){
				puts("0");
				fflush(stdout);
				continue;
			}
			//printf("s1 %lld x %d lc %d fa %d\n",s1[x],x,ch[x][0],fa[x]);
			Splay(x=Query(x,y));
			y-=s1[ch[x][0]];
			ll ans=s2[ch[x][0]];
			add(ch[x][0]);
			val[x]-=y;
			ans+=1ll*y*c[x];
			pushup(x);
			printf("%lld\n",ans);
			fflush(stdout);
		}
	}
	return 0;
}