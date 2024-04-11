#include<bits/stdc++.h>
using namespace std;
#define pi pair<int,int>
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define mid (l+r>>1)
const int maxn=1e6+5,M=34005;
inline int read()
{
	char ch=getchar();bool f=0;int x=0;
	for(;!isdigit(ch);ch=getchar())if(ch=='-')f=1;
	for(;isdigit(ch);ch=getchar())x=(x<<1)+(x<<3)+(ch^48);
	if(f==1)x=-x;return x;
}
inline void print(int x)
{
    static int a[55];int top=0;
    if(x<0) putchar('-'),x=-x;
    do{a[top++]=x%10,x/=10;}while(x);
    while(top) putchar(a[--top]+48);
}
int tot=0,n,m,pos[maxn],g[maxn],l,r,lx,rx,f[maxn][22],q;
int ls[maxn*20],rs[maxn*20],rt[maxn];pi mx[maxn*20],ans[maxn];
struct node{int l,r,id;};vector<node>d[maxn];
char a[maxn],b[maxn]; 
void build(int &rt,int l,int r,int pos){
	if(l>pos||r<pos)return;if(!rt)rt=++tot;
	if(l==r){mx[rt]=mp(1,-pos);return;}
	build(ls[rt],l,mid,pos),build(rs[rt],mid+1,r,pos);
	mx[rt]=max(mx[ls[rt]],mx[rs[rt]]);
}
int merge(int x,int y,int l,int r){
	if(!x||!y)return x+y;
	if(l==r){mx[x].fi+=mx[y].fi;return x;}
	ls[x]=merge(ls[x],ls[y],l,mid);
	rs[x]=merge(rs[x],rs[y],mid+1,r);mx[x]=max(mx[ls[x]],mx[rs[x]]);
	
	return x;
}
pi query(int rt,int l,int r,int L,int R){
	if(l>R||r<L||!rt)return mp(0,-L);
	if(l>=L&&r<=R){return mx[rt];}
	return max(query(ls[rt],l,mid,L,R),query(rs[rt],mid+1,r,L,R));
}
struct Sam{
	int len[maxn],fa[maxn],ch[maxn][26],tot=1,las=1;vector<int>e[maxn];
	void ins(int x,int id){
		int p=las,t=++tot;las=t;len[t]=len[p]+1;build(rt[t],1,m,id);
		for(;!ch[p][x];p=fa[p])ch[p][x]=t;
		if(!p){fa[t]=1;return;}int q=ch[p][x];
		if(len[q]==len[p]+1){fa[t]=q;return;}
		len[++tot]=len[p]+1,fa[tot]=fa[q],fa[q]=fa[t]=tot;
		memcpy(ch[tot],ch[q],sizeof ch[q]);
		for(;ch[p][x]==q;p=fa[p])ch[p][x]=tot;
	}
	void dfs(int x){
		for(auto i:e[x])
			dfs(i),rt[x]=merge(rt[x],rt[i],1,m);
		for(auto i:d[x])ans[i.id]=query(rt[x],1,m,i.l,i.r);
	}
	void work(){
		for(int i=2;i<=tot;i++)e[fa[i]].pb(i),f[i][0]=fa[i];
		for(int j=1;j<=20;j++)
			for(int i=1;i<=tot;i++)f[i][j]=f[f[i][j-1]][j-1];
		int p=1,l=0;
		for(int i=1;i<=n;i++){
			int x=a[i]-'a';
			if(ch[p][x]){p=ch[p][x],l++;}
			else{
				while(p&&!ch[p][x])p=fa[p];
				if(!p)p=1,l=0;
				else l=len[p]+1,p=ch[p][x];
			}
			pos[i]=p;g[i]=l;
		}
	}
}sam;
signed main()
{
	scanf("%s",a+1);n=strlen(a+1);m=read();mx[0]=mp(-1,0);
	for(int i=1;i<=m;i++){
		scanf("%s",b+1);int len=strlen(b+1);sam.las=1;
		for(int j=1;j<=len;j++)sam.ins(b[j]-'a',i);
	}q=read();sam.work();
	for(int i=1;i<=q;i++){
		l=read(),r=read(),lx=read(),rx=read();
		if(g[rx]<(rx-lx+1)){ans[i]=mp(0,-l);continue;}
		int p=pos[rx];
		for(int j=20;j>=0;j--)if(sam.len[f[p][j]]>=(rx-lx+1))p=f[p][j];
		d[p].pb({l,r,i});
	}sam.dfs(1);
	for(int i=1;i<=q;i++)printf("%d %d\n",-ans[i].se,ans[i].fi);
 	return 0;
}