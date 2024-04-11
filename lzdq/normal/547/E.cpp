#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;
const int MAXN=2e5+5,MAXP=MAXN*4,MAXQ=5e5+5;
int n,q,m[MAXN];
struct node{
	int k,sgn,id;
};
vector<node> que[MAXN];
int ans[MAXQ];
int pt[MAXN];
char *buf,*s[MAXN];
struct SAM{
	int ch[27],fa,len;
}dat[MAXP];
int cntp,las;
void Extend(int c){
	int p=las;
	int np=las=++cntp;
	dat[np].len=dat[p].len+1;
	while(p&&!dat[p].ch[c])
		dat[p].ch[c]=np,p=dat[p].fa;
	if(p){
		int q=dat[p].ch[c];
		if(dat[q].len>dat[p].len+1){
			int nq=++cntp;
			dat[nq]=dat[q];
			dat[nq].len=dat[p].len+1;
			dat[np].fa=dat[q].fa=nq;
			while(p&&dat[p].ch[c]==q)
				dat[p].ch[c]=nq,p=dat[p].fa;
		}else dat[np].fa=q;
	}else dat[np].fa=1;
	return ;
}
int cnte,h[MAXP],nx[MAXP],to[MAXP];
inline void adde(int u,int v){
	cnte++;
	nx[cnte]=h[u];
	to[cnte]=v;
	h[u]=cnte;
}
int dfn[MAXP],siz[MAXP];
void Dfs(int u){
	//printf("Dfs %d\n",u);
	siz[u]=1;
	dfn[u]=++*dfn;
	for(int i=h[u]; i; i=nx[i]){
		int v=to[i];
		Dfs(v);
		siz[u]+=siz[v];
	}
	return ;
}
int rsum[MAXP];
inline int query(int x){
	int res=0;
	for(int i=x; i<=cntp; i+=i&-i)
		res+=rsum[i];
	return res;
}
inline void add(int x){
	for(int i=x; i; i-=i&-i)
		rsum[i]++;
}
int main(){
	//freopen("in","r",stdin);
	scanf("%d%d",&n,&q);
	buf=new char[MAXN*2];
	cntp=las=1;
	for(int i=1; i<=n; i++){
		s[i]=buf;
		scanf("%s",s[i]);
		m[i]=strlen(s[i]);
		buf+=m[i]+1;
		for(int j=0; j<m[i]; j++)
			Extend(s[i][j]-='a');
		Extend(26);
	}
	for(int i=1; i<=n; i++){
		pt[i]=1;
		for(int j=0; j<m[i]; j++)
			pt[i]=dat[pt[i]].ch[s[i][j]];
		//printf("pt %d\n",pt[i]);
	}
	for(int i=1; i<=q; i++){
		int l,r,k;
		scanf("%d%d%d",&l,&r,&k);
		if(l>1) que[l-1].push_back((node){k,-1,i});
		que[r].push_back((node){k,1,i});
	}
	//printf("cntp %d\n",cntp);
	for(int i=2; i<=cntp; i++)
		adde(dat[i].fa,i);
	Dfs(1);
	for(int i=1; i<=n; i++){
		int u=1;
		for(int j=0; j<m[i]; j++){
			u=dat[u].ch[s[i][j]];
			add(dfn[u]);
		}
		for(node j:que[i])
			ans[j.id]+=j.sgn*(query(dfn[pt[j.k]])-query(dfn[pt[j.k]]+siz[pt[j.k]]));
	}
	for(int i=1; i<=q; i++)
		printf("%d\n",ans[i]);
	return 0;
}