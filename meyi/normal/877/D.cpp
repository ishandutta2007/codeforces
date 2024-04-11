#include<bits/stdc++.h>
using namespace std;
#define ri int
typedef long long ll;
const int maxn=1010;
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,1:0;}
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,1:0;}
template<class T>inline void clear(T *arr,int siz,int val=0){memset(arr,val,sizeof(T)*(siz+1));}
static char pbuf[1000000],*p1=pbuf,*p2=pbuf;
#define getchar() p1==p2&&(p2=(p1=pbuf)+fread(pbuf,1,1000000,stdin),p1==p2)?EOF:*p1++
inline int qr(){
	ri in=0;char ch;
	while(!isdigit(ch=getchar()));
	do in=(in<<1)+(in<<3)+(ch^48);while(isdigit(ch=getchar()));
	return in;
}
inline char gc(){
	char ch=getchar();
	while(ch!='.'&&ch!='#')ch=getchar();
	return ch;
}
int dis[maxn][maxn],D[maxn][maxn],k,L[maxn][maxn],m,n,R[maxn][maxn],sx,sy,tx,ty,U[maxn][maxn];
set<int>col[maxn],row[maxn];
char s[maxn][maxn];
typedef pair<int,int> pii;
#define fi first
#define se second
queue<pii>q;
inline void insert(int x,int y,int d,int t){
	if(t&1)row[x].erase(y);
	if(t&2)col[y].erase(x);
	dis[x][y]=d;
	q.emplace(x,y);
}
int main(){
	n=qr(),m=qr(),k=qr();
	for(ri i=1;i<=n;++i){
		for(ri j=1;j<=m;++j){
			s[i][j]=gc();
			if(s[i][j]=='.'){
				row[i].insert(j);
				col[j].insert(i);
			}
		}
	}
	for(ri i=1;i<=n;++i)
		for(ri j=1;j<=m;++j)
			if(s[i][j]=='.')U[i][j]=U[i-1][j],L[i][j]=L[i][j-1];
			else U[i][j]=i,L[i][j]=j;
	for(ri i=n;i;--i)
		for(ri j=m;j;--j)
			if(s[i][j]=='.')D[i][j]=(i==n?n+1:D[i+1][j]),R[i][j]=(j==m?m+1:R[i][j+1]);
			else D[i][j]=i,R[i][j]=j;
	sx=qr(),sy=qr(),tx=qr(),ty=qr();
	memset(dis,-1,sizeof dis);
	insert(sx,sy,0,3);
	while(q.size()){
		pii p=q.front();q.pop();
		auto it=row[p.fi].upper_bound(p.se);
		while(it!=row[p.fi].end()){
			if(*it-p.se>k||*it>=R[p.fi][p.se])break;
			insert(p.fi,*it,dis[p.fi][p.se]+1,2);
			it=row[p.fi].erase(it);
		}
		while(it!=row[p.fi].begin()){
			it=prev(it);
			if(p.se-*it>k||*it<=L[p.fi][p.se])break;
			insert(p.fi,*it,dis[p.fi][p.se]+1,2);
			it=row[p.fi].erase(it);
		}
		it=col[p.se].upper_bound(p.fi);
		while(it!=col[p.se].end()){
			if(*it-p.fi>k||*it>=D[p.fi][p.se])break;
			insert(*it,p.se,dis[p.fi][p.se]+1,1);
			it=col[p.se].erase(it);
		}
		while(it!=col[p.se].begin()){
			it=prev(it);
			if(p.fi-*it>k||*it<=U[p.fi][p.se])break;
			insert(*it,p.se,dis[p.fi][p.se]+1,1);
			it=col[p.se].erase(it);
		}
	}
	printf("%d",dis[tx][ty]);
	return 0;
}