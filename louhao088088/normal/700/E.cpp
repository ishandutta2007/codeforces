#include<bits/stdc++.h>
using namespace std;
#define pi pair<int,int>
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define mid (l+r>>1)
const int maxn=4e5+5,M=34005;
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
int tot=0,n,m,l,r,lx,rx,q,ans=0,f[maxn],top[maxn];
int ls[maxn*40],rs[maxn*40],rt[maxn];
struct node{int l,r,id;};vector<node>d[maxn];
char a[maxn],b[maxn]; 
void build(int &rt,int l,int r,int pos){
	if(l>pos||r<pos)return;if(!rt)rt=++tot;
	if(l==r){return;}
	build(ls[rt],l,mid,pos),build(rs[rt],mid+1,r,pos);
}
int merge(int x,int y,int l,int r){
	if(!x||!y)return x+y;int rt=++tot;
	if(l==r){return rt;}
	ls[rt]=merge(ls[x],ls[y],l,mid);
	rs[rt]=merge(rs[x],rs[y],mid+1,r);return rt;
	
	return x;
}
int query(int rt,int l,int r,int L,int R){
	if(l>R||r<L||!rt)return 0;
	if(l>=L&&r<=R){return 1;}
	return query(ls[rt],l,mid,L,R)+query(rs[rt],mid+1,r,L,R);
}
struct Sam{
	int len[maxn],fa[maxn],ch[maxn][26],tot=1,las=1,pos[maxn];vector<int>e[maxn];
	void ins(int x,int id){
		int p=las,t=++tot;las=t;len[t]=len[p]+1;
		pos[t]=id;build(rt[t],1,n,id);
		for(;!ch[p][x];p=fa[p])ch[p][x]=t;
		if(!p){fa[t]=1;return;}int q=ch[p][x];
		if(len[q]==len[p]+1){fa[t]=q;return;}
		len[++tot]=len[p]+1,fa[tot]=fa[q],fa[q]=fa[t]=tot;pos[tot]=id;
		memcpy(ch[tot],ch[q],sizeof ch[q]);
		for(;ch[p][x]==q;p=fa[p])ch[p][x]=tot;
	}
	void dfs(int x){
		for(auto i:e[x])
			dfs(i),rt[x]=merge(rt[x],rt[i],1,n);
	}
	void dfs1(int x){
		ans=max(ans,f[x]);//cout<<ans<<" "<<x<<endl;
		for(auto i:e[x]){
			if(x==1)top[i]=i,f[i]=1;
			else if(query(rt[top[x]],1,n,pos[i]-len[i]+len[top[x]],pos[i]-1))top[i]=i,f[i]=f[x]+1;
			else top[i]=top[x],f[i]=f[x];
			//if(x!=1)cout<<x<<" "<<i<<" "<<query(rt[top[x]],1,n,pos[i]-len[i]+len[top[x]],pos[i]-1)<<" "<<pos[i]-len[i]+len[top[x]]<<" "<<pos[i]-1<<endl;
			dfs1(i);
		}	
	}
	void work(){
		for(int i=2;i<=tot;i++)e[fa[i]].pb(i);
		dfs(1);dfs1(1);
	}
}sam;
signed main()
{
	n=read();scanf("%s",a+1);
	for(int i=1;i<=n;i++)sam.ins(a[i]-'a',i);
	sam.work();cout<<ans<<endl;	
 	return 0;
}