#include<bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll;
const int maxn=5e3+10,maxq=1e5+10;
#define lowbit(k) ((k)&(-k))
struct BIT{
	int c[maxn<<1],mx_idx;
	void clear(){memset(c,0,sizeof c);}
	inline void add(int k,int v){
		for(;k<=mx_idx;k+=lowbit(k))c[k]+=v;
	}
	inline void add(int l,int r,int v){
		add(l,v),add(r+1,-v);
	}
	inline int query(int k){
		int ret=0;
		for(;k;k^=lowbit(k))ret+=c[k];
		return ret;
	}
}t;
struct BIT2{
	int c[maxn<<1][maxn],mx_idx1,mx_idx2;
	void clear(){memset(c,0,sizeof c);}
	inline void add(int x,int y,int v){
		for(;x<=mx_idx1;x+=lowbit(x))
			for(ri yy=y;yy<=mx_idx2;yy+=lowbit(yy))
				c[x][yy]+=v;
	}
	inline void add(int lx,int ly,int rx,int ry,int v){
		add(lx,ly,v),add(lx,ry+1,-v),add(rx+1,ly,-v),add(rx+1,ry+1,v);
	}
	inline int query(int x,int y){
		int ret=0;
		for(;x;x^=lowbit(x))
			for(ri yy=y;yy;yy^=lowbit(yy))
				ret+=c[x][yy];
		return ret;
	}
}tx,ty;
struct qry{
	int op,dir,x,y,len;
}q[maxq];
int ans[maxq],cnt,m,n;
inline void solve(int k){
	for(ri i=1;i<=m;++i){
		if(q[i].op&1){
			if((q[i].dir&2)^k){
				if(q[i].dir&1){
					t.add(q[i].x+q[i].y,q[i].x+q[i].y+q[i].len,1);
					tx.add(q[i].x+q[i].y,1,q[i].x+q[i].y+q[i].len,q[i].x-1,1);
					ty.add(q[i].x+q[i].y,1,q[i].x+q[i].y+q[i].len,q[i].y-1,1);
				}
				else{
					t.add(q[i].x+q[i].y-q[i].len,q[i].x+q[i].y,1);
					tx.add(q[i].x+q[i].y-q[i].len,q[i].x+1,q[i].x+q[i].y,n,1);
					ty.add(q[i].x+q[i].y-q[i].len,q[i].y+1,q[i].x+q[i].y,n,1);
				}
			}
		}
		else{
			ans[q[i].len]+=t.query(q[i].x+q[i].y)-tx.query(q[i].x+q[i].y,q[i].x)-ty.query(q[i].x+q[i].y,q[i].y);
		}
	}
}
int main(){
	scanf("%d%d",&n,&m);
	t.mx_idx=tx.mx_idx1=ty.mx_idx1=n<<1;
	tx.mx_idx2=ty.mx_idx2=n;
	for(ri i=1;i<=m;++i){
		scanf("%d",&q[i].op);
		if(q[i].op&1)scanf("%d%d%d%d",&q[i].dir,&q[i].x,&q[i].y,&q[i].len);
		else{
			scanf("%d%d",&q[i].x,&q[i].y);
			q[i].len=++cnt;
		}
	}
	solve(2);
	for(ri i=1;i<=m;++i)q[i].x=n-q[i].x+1;
	t.clear(),tx.clear(),ty.clear();
	solve(0);
	for(ri i=1;i<=cnt;++i)printf("%d\n",ans[i]);
	return 0;
}