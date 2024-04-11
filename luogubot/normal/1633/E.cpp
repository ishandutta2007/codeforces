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
bool ST;
const int N=300+10,M=N*N*3,K=1e8+10;
int fa[N],n,m,p,k,a,b,c,q;
int get(int x){return fa[x]==x?x:fa[x]=get(fa[x]);}
struct node{
	int u,v,w;
	bool operator < (const node &x) const {
		return abs(w-q)!=abs(x.w-q)?abs(w-q)<abs(x.w-q):w<x.w;
	}
}e[N];
#define pi pair<int,int>
#define fi first
#define se second
bool merge(int x,int y){
	x=get(x),y=get(y);
	if(x==y)return 0;
	fa[x]=y;return 1;
}
pi work(int q){
	For(i,1,n)fa[i]=i;
	::q=q,sort(e+1,e+1+m);
	int ans=0,res=0;
	For(i,1,m){
		int u=e[i].u,v=e[i].v,w=e[i].w;
		if(merge(u,v)){
			if(w<=q)ans-=w,res++;
			else ans+=w,res--;
		}
	}return pi(res,ans);
	//fi*q+se
}
set<int> now;
set<pi> s;//(pos,id)
pi h[M];int l;
map<int,int> used;
void add(int q){
	now.insert(q);
}
bool ED;
signed main(){
	n=read(),m=read();
	For(i,1,m)e[i].u=read(),e[i].v=read(),e[i].w=read();
	add(0);For(i,1,m)For(j,i,m)add((e[i].w+e[j].w>>1)+1);
	now.insert(1e8);
	for(auto it=now.begin();it!=now.end();it++){
		if(next(it)!=now.end()){
			h[++l]=work(*it);
			s.insert(pi(*it,l));
		}
	}
	p=read(),k=read(),a=read(),b=read(),c=read();
	int q=0;int ans=0;
	For(i,1,k){
		if(i<=p)q=read();
		else q=(q*a+b)%c;
		int id=(*--s.upper_bound(pi(q,l+1))).se;
		ans^=(h[id].fi*q+h[id].se);
	}cout<<ans<<endl;
	return 0;
}