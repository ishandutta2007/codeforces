#include<bits/stdc++.h>
#define For(i,a,b) for(int i=(a),i##END=(b);i<=i##END;i++)
#define Rof(i,b,a) for(int i=(b),i##END=(a);i>=i##END;i--)
#define go(u) for(int i=head[u];i;i=nxt[i])
using namespace std;
inline int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
    return x*f;
}
const int N=3e5+10,inf=1e8;
int n,q,a[N];
struct Tree{
	#define ls (k<<1)
	#define rs (k<<1|1)
	int t[N<<2],tag[N<<2];
	void up(int k){t[k]=max(t[ls],t[rs]);}
	void f(int k,int v){t[k]+=v,tag[k]+=v;}
	void down(int k){f(ls,tag[k]),f(rs,tag[k]),tag[k]=0;}
	void mdf(int k,int l,int r,int x,int v){
		if(l==r)return t[k]=v,void();
		down(k);
		int m=l+r>>1;x<=m?mdf(ls,l,m,x,v):mdf(rs,m+1,r,x,v);
		up(k);
	}
	int get(int k,int l,int r){
		if(t[k]<0)return -1;
		if(l==r)return l;
		int m=l+r>>1;down(k);
		int ret=t[rs]>=0?get(rs,m+1,r):get(ls,l,m);
		up(k);return ret;
	}
	void add(int k,int l,int r,int x,int y){
		if(x<=l&&r<=y)return f(k,1);
		int m=l+r>>1;down(k);
		if(x<=m)add(ls,l,m,x,y);
		if(y>m)add(rs,m+1,r,x,y);
		up(k);
	}
}T;
int ans[N];
struct qry{
	int l,r,id;
	bool operator < (const qry &x) const {
		return l>x.l;
	}
}b[N];
int c[N];
#define lowbit(x) (x&-x)
void Add(int u){for(int i=u;i<N;i+=lowbit(i))c[i]++;}
int ask(int u,int s=0){for(int i=u;i;i-=lowbit(i))s+=c[i];return s;}
void add(int i){
	if(a[i])return;
	Add(i);T.add(1,1,n,i,n);T.mdf(1,1,n,i,-inf);
	while(1){
		int x=T.get(1,1,n);
		if(x>=i){
			Add(x);T.add(1,1,n,x,n);T.mdf(1,1,n,x,-inf);
		}else break;
	}
}
signed main(){
	n=read(),q=read();For(i,1,n){
		a[i]=read()-i;
		if(a[i]>0)a[i]=-inf;
		T.mdf(1,1,n,i,a[i]);
	}
	For(i,1,q){
		int l=read()+1,r=n-read(),id=i;
		b[i]=(qry){l,r,id};
	}sort(b+1,b+1+q);int R=n+1;
	For(i,1,q){
		int l=b[i].l,r=b[i].r,id=b[i].id;
		while(R>l)add(--R);ans[id]=ask(r);
	}For(i,1,q)printf("%d\n",ans[i]);
	return 0;
}//faadas