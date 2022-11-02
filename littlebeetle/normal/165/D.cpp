#include<cstdio>
const int N=600002;
int n,m,i,j,k,x[N],y[N],h[N],t[N],v[N],d[N],fa[N],top[N],dfn[N],tim,sz[N],e[N],opt,c[N],C[N],a,b,p;
char ch;
void read(int &a){
	a=0;
	while((ch=getchar())<48);
	while(ch>47)
		a=(a<<3)+(a<<1)+(ch^48),ch=getchar();
}
void adde(int x,int y){
	t[++k]=h[x];h[x]=k;v[k]=y;
}
void dfs1(int i){
	sz[i]=1;
	for(int j=h[i];j;j=t[j])
		if(v[j]!=fa[i]){
			fa[v[j]]=i;
			d[v[j]]=d[i]+1;
			dfs1(v[j]);
			sz[i]+=sz[v[j]];
			if(sz[v[j]]>sz[e[i]])
				e[i]=v[j];
		}
	return;
}
void dfs2(int i){
	dfn[i]=++tim;
	if(e[i])
		top[e[i]]=top[i],dfs2(e[i]);
	for(int j=h[i];j;j=t[j])
		if(v[j]!=fa[i]&&v[j]!=e[i]){
			top[v[j]]=v[j];
			dfs2(v[j]);
		}
	return;
}
void swap(int &x,int &y){
	int t=x;x=y;y=t;
}
void init(){
	read(n);
	for(i=1;i<n;i++){
		read(x[i]);read(y[i]);
		adde(x[i],y[i]);
		adde(y[i],x[i]);
	}
	dfs1(1);
	top[1]=1;
	dfs2(1);
	for(i=1;i<n;i++)
		if(d[x[i]]>d[y[i]])
			swap(x[i],y[i]);
	return;
}
void add(int x,int y){
	for(;x<=n;x+=x&-x)
		c[x]+=y;
}
int sum(int x){
	int s=0;
	for(;x;x-=x&-x)
		s+=c[x];
	return s;
}
int LCA(int x,int y){
	while(top[x]!=top[y]){
		if(d[top[x]]>d[top[y]])
			x=fa[top[x]];
		else
			y=fa[top[y]];
	}
	return d[x]<d[y]?x:y;
}
void work(){
	read(m);
	while(m--){
		read(opt);
		if(opt==1){
			read(a);
			a=y[a];
			if(C[a]==1)
				C[a]=0,add(dfn[a],-1),add(dfn[a]+sz[a],1);
		}
		if(opt==2){
			read(a);
			a=y[a];
			if(C[a]==0)
				C[a]=1,add(dfn[a],1),add(dfn[a]+sz[a],-1);
		}
		if(opt==3){
			read(a);read(b);
			p=LCA(a,b);
			if(sum(dfn[a])+sum(dfn[b])-sum(dfn[p])*2)
				printf("-1\n");
			else
				printf("%d\n",d[a]+d[b]-d[p]*2);
		}
	}
	return;
}
int main(){
	init();
	work();
	return 0;
}