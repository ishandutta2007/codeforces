#include<bits/stdc++.h>
#define For(i,a,b) for(int i=(a),i##END=(b);i<=i##END;i++)
#define Rof(i,b,a) for(int i=(b),i##END=(a);i>=i##END;i--)
#define go(u) for(int i=head[u];i;i=nxt[i])
#define int long long
using namespace std;
inline int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
    return x*f;
}
const int N=2e5+10;
int n,a[N],stk1[N],tp1,stk2[N],tp2;
struct Tree{
	#define ls (k<<1)
	#define rs (k<<1|1)
	struct node{
		int v,c,T,V,tag;
	}t[N<<2];
	void up(int k){t[k].v=min(t[ls].v,t[rs].v),t[k].c=(t[ls].v==t[k].v)*t[ls].c+(t[rs].v==t[k].v)*t[rs].c,t[k].V=t[ls].V+t[rs].V;}
	void build(int k,int l,int r){
		t[k].c=r-l+1;if(l==r)return;
		int m=l+r>>1;build(ls,l,m),build(rs,m+1,r);
	}
	void f(int k,int v){t[k].v+=v,t[k].tag+=v;}
	void g(int k,int v){if(t[k].v==t[k>>1].v)t[k].V+=t[k].c*v,t[k].T+=v;} 
	void down(int k){f(ls,t[k].tag),f(rs,t[k].tag),t[k].tag=0;g(ls,t[k].T),g(rs,t[k].T),t[k].T=0;}
	void add(int k,int l,int r,int x,int y,int v){
		if(x<=l&&r<=y)return f(k,v);
		int m=l+r>>1;down(k);
		if(x<=m)add(ls,l,m,x,y,v);
		if(y>m)add(rs,m+1,r,x,y,v);
		up(k);
	}
	void G(int k,int l,int r,int x,int y){
		if(x<=l&&r<=y){
			if(t[k].v==-1)t[k].V+=t[k].c,t[k].T++;
			return;
		}
		int m=l+r>>1;down(k);
		if(x<=m)G(ls,l,m,x,y);
		if(y>m)G(rs,m+1,r,x,y);
		up(k);
	}
	int sum(int k,int l,int r,int x,int y){
		if(x<=l&&r<=y)return t[k].V;
		int m=l+r>>1;down(k);
		int ret=(x<=m?sum(ls,l,m,x,y):0)+(y>m?sum(rs,m+1,r,x,y):0);
		up(k);return ret;
	}
}T;
struct qry{
	int l,r,id;
	void input(int i){l=read(),r=read(),id=i;}
	bool operator < (const qry &x) const {return r<x.r;}
}Q[N];vector<int> g[N];
int ans[N];
signed main(){
	For(i,1,n=read())a[i]=read();
	int q=read();For(i,1,q)Q[i].input(i);sort(Q+1,Q+1+q);For(i,1,q)g[Q[i].r].push_back(i);
	T.build(1,1,n);For(i,1,n){
		while(tp1&&a[i]>a[stk1[tp1]])T.add(1,1,n,stk1[tp1-1]+1,stk1[tp1],-a[stk1[tp1]]),tp1--;
		while(tp2&&a[i]<a[stk2[tp2]])T.add(1,1,n,stk2[tp2-1]+1,stk2[tp2],a[stk2[tp2]]),tp2--;
		T.add(1,1,n,1,i,-1),T.add(1,1,n,stk1[tp1]+1,i,a[i]),T.add(1,1,n,stk2[tp2]+1,i,-a[i]);
		T.G(1,1,n,1,i),stk1[++tp1]=i,stk2[++tp2]=i;
		for(auto j:g[i])ans[Q[j].id]=T.sum(1,1,n,Q[j].l,i); 
	}For(i,1,q)printf("%lld\n",ans[i]);	
	return 0;
}