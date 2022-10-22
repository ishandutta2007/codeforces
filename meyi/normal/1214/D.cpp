#include<bits/stdc++.h>
using namespace std;
#define ri int
typedef long long ll;
const int inf=0x3f3f3f3f,maxn=2e6+10;
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,1:0;}
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,1:0;}
template<class T>inline void clear(T *arr,int siz,int val=0){memset(arr,val,sizeof(T)*(siz+1));}
struct edge{
	int to,nxt,f;
}e[maxn*3];
int hd[maxn],len=1,tmp[maxn];
inline void addedge(int fr,int to,int f){
	e[++len]={to,hd[fr],f};
	hd[fr]=len;
	e[++len]={fr,hd[to],0};
	hd[to]=len;
}
int dep[maxn],m,n,nm,S,T;
inline int idx(int x,int y,bool z){return (x-1)*m+y+(z?nm:0);}
inline bool bfs(){
	clear(dep,idx(n,m,2));
	dep[S]=1;
	queue<int>q;
	q.push(S);
	while(q.size()){
		ri p=q.front();q.pop();
		for(ri i=hd[p];i;i=e[i].nxt)
			if(e[i].f>0&&!dep[e[i].to])
				dep[e[i].to]=dep[p]+1,q.push(e[i].to);
	}
	return dep[T];
}
int dfs(int p,int lim){
	if(p==T)return lim;
	ri sum=0;
	for(ri &i=hd[p];i;i=e[i].nxt)
		if(e[i].f>0&&dep[p]+1==dep[e[i].to]){
			ri f=dfs(e[i].to,min(lim-sum,e[i].f));
			if(f){
				e[i].f-=f,e[i^1].f+=f;
				sum+=f;
				if(sum==lim)break;
			}
		}
	if(!sum)dep[p]=0;
	return sum;
}
inline int dinic(){
	memcpy(tmp,hd,idx(n,m,1)+1<<1);
	ri ret=0;
	while(bfs()){
		ret+=dfs(S,inf);
		memcpy(hd,tmp,idx(n,m,1)+1<<1);
	}
	return ret;
}
char s[maxn];
int main(){
	scanf("%d%d",&n,&m);
	nm=n*m;
	for(ri i=0;i<n;++i)scanf("%s",s+i*m+1);
	for(ri i=1;i<=n;++i)
		for(ri j=1;j<=m;++j)
			if(s[idx(i,j,0)]=='.'){
				addedge(idx(i,j,0),idx(i,j,1),(i==1&&j==1)||(i==n&&j==m)?inf:1);
				if(i<n&&s[idx(i+1,j,0)]=='.')addedge(idx(i,j,1),idx(i+1,j,0),inf);
				if(j<m&&s[idx(i,j+1,0)]=='.')addedge(idx(i,j,1),idx(i,j+1,0),inf);
			}
	S=idx(1,1,0),T=idx(n,m,1);
	printf("%d",dinic());
	return 0;
}