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
bool ST;
const int N=1e6+10,ADD=100;
#define pi pair<int,int>
#define fi first
#define se second
int n,m;set<pi> s;pi a[N];
struct Tree{
	#define ls (k<<1)
	#define rs (k<<1|1)
	int t[N<<2],tag[N<<2],num[N<<2];
	void f(int k,int v){t[k]+=v,tag[k]+=v;}
	void up(int k){
		t[k]=min(t[ls],t[rs]),num[k]=0;
		if(t[ls]==t[k])num[k]+=num[ls];
		if(t[rs]==t[k])num[k]+=num[rs];
	}
	void down(int k){f(ls,tag[k]),f(rs,tag[k]),tag[k]=0;}
	void build(int k,int l,int r){
		if(l==r){t[k]=ADD+1,num[k]=1;return;}
		int m=l+r>>1;
		build(ls,l,m),build(rs,m+1,r);
		up(k);
	}
	void add(int k,int l,int r,int x,int y,int v){
		if(x<=l&&r<=y)return f(k,v);
		int m=l+r>>1;if(tag[k])down(k);
		if(x<=m)add(ls,l,m,x,y,v);
		if(y>m)add(rs,m+1,r,x,y,v);
		up(k);
	}
}T;
int X[N],U[N],V[N],b[N],tp;
inline int find(int x){return lower_bound(b+1,b+1+tp,x)-b;}
void add(int l,int r,int v){
	if(l<=r)return;assert(r+1<=l); 
	T.add(1,1,tp,r+1,l,v);
}
void ins(pi x){
	auto it=s.insert(x).fi;
	T.add(1,1,tp,it->se,it->se,-ADD);
	add(prev(it)->se,it->se,1);
	add(it->se,next(it)->se,1);
	add(prev(it)->se,next(it)->se,-1);
}
void del(pi x){
	auto it=s.find(x);assert(it!=s.end());
	T.add(1,1,tp,it->se,it->se,ADD);
	add(prev(it)->se,it->se,-1);
	add(it->se,next(it)->se,-1);
	add(prev(it)->se,next(it)->se,1);
	s.erase(it);
}
int stk[30],TP;
void write(int x){
	do stk[++TP]=x%10,x/=10;while(x);
	while(TP)putchar(stk[TP--]^48);
}
void out(){write((T.t[1]==1)*T.num[1]),putchar('\n');}
bool ED;
signed main(){
//	printf("%.2lf MB\n",abs(&ED-&ST)/1024.0/1024.0);
	b[++tp]=0,b[++tp]=2e9;
	n=read(),m=read();For(i,1,n)a[i].fi=i,a[i].se=read(),b[++tp]=a[i].se;
	For(i,1,m)X[i]=read(),U[i]=X[i],V[i]=read(),b[++tp]=V[i];
	sort(b+1,b+1+tp),tp=unique(b+1,b+1+tp)-b-1;
	s.insert(pi(0,tp)),s.insert(pi(2e9,1)),T.build(1,1,tp);
	For(i,1,n)a[i].se=find(a[i].se),ins(a[i]);
	For(i,1,m){
		int x=X[i],u=U[i],v=find(V[i]);
		del(a[x]),ins(a[x]=pi(u,v)),out();
	}
	return 0;
}