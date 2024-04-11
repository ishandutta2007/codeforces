#include<bits/stdc++.h>
#define ll long long
#define N 50005
#define isrt(x) (c[fa[x]][0]!=x && c[fa[x]][1]!=x)
using namespace std;

int n,m,tot,tp,q[N],fa[N],c[N][2],fst[N],pnt[N],nxt[N]; ll ans;
struct node{ int dsz,sz,icr,val; ll w,sum; }P[N];
void add(int x,int y){
	pnt[++tot]=y; nxt[tot]=fst[x]; fst[x]=tot;
}
void maintain(int x){
	node &o=P[x],&l=P[c[x][0]],&r=P[c[x][1]];
	o.sz=o.dsz+l.sz+r.sz;
	o.sum=(ll)o.dsz*o.val+l.sum+r.sum;
}
void mdy(int x,int y){
	node &o=P[x]; o.icr+=y; o.w+=(ll)y*o.dsz;
}
void pushdn(int x){
	if (P[x].icr){
		mdy(c[x][0],P[x].icr); mdy(c[x][1],P[x].icr); P[x].icr=0;
	}
}
void rot(int x){
	int y=fa[x],z=fa[y],l=(c[y][1]==x),r=l^1;
	if (!isrt(y)) c[z][c[z][1]==y]=x;
	fa[x]=z; fa[y]=x; fa[c[x][r]]=y;
	c[y][l]=c[x][r]; c[x][r]=y;
	maintain(y);
}
void splay(int x){
	int i,y,z; q[tp=1]=x;
	for (i=x; !isrt(i); i=fa[i]) q[++tp]=fa[i];
	while (tp) pushdn(q[tp--]);
	for (; !isrt(x); rot(x)){
		y=fa[x]; z=fa[y];
		if (!isrt(y)) rot((c[z][0]==y ^ c[y][0]==x)?x:y);
	}
	maintain(x);
}
void acss(int x){
	int y=0;
	for (; x; y=x,x=fa[x]){
		splay(x); P[x].dsz+=P[c[x][1]].sz;
		c[x][1]=y; P[x].dsz-=P[y].sz;
		maintain(x);
	}
}
void dfs(int x){
	int i,y; node &o=P[x]; o.w=o.dsz=1;
	for (i=fst[x]; i; i=nxt[i]){
		y=pnt[i];
		dfs(y);
		o.w+=(ll)o.dsz*P[y].dsz<<1; o.dsz+=P[y].dsz;
	}
	ans+=o.val*o.w; maintain(x);
}
int main(){
	scanf("%d",&n);
	int i,x,y,z;
	for (i=2; i<=n; i++){
		scanf("%d",&fa[i]); add(fa[i],i);
	}
	for (i=1; i<=n; i++) scanf("%d",&P[i].val);
	dfs(1);
	printf("%.15f\n",(double)ans/n/n);
	scanf("%d",&m);
	char cr;
	while (m--){
		cr=getchar(); while (cr<'A' || cr>'Z') cr=getchar();
		scanf("%d%d",&x,&y);
		if (cr=='P'){
			acss(y); splay(x);
			for (z=x; !isrt(z); z=c[z][0]);
			if (fa[z]) acss(x); else  swap(x,y);
			if (!c[x][0]) z=fa[x]; else for (z=c[x][0]; c[z][1]; z=c[z][1]);
			if (z!=y){
				acss(z); splay(z); splay(x);
				P[z].dsz-=P[x].sz; mdy(z,-(P[x].sz<<1));
				maintain(z);
				ans-=P[z].sum*P[x].sz<<1;
				acss(y); splay(y);
				ans+=P[y].sum*P[x].sz<<1;
				mdy(y,P[x].sz<<1); P[y].dsz+=P[x].sz;
				maintain(y); fa[x]=y;
			}
		} else{
			splay(x);
			ans+=(y-P[x].val)*P[x].w; P[x].val=y;
		}
		printf("%.15f\n",(double)ans/n/n);
	}
	return 0;
}