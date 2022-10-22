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
const int N=5e5+10;
#define pi pair<int,int>
#define fi first
#define se second
vector<pi> e[N];
int fa[N],sz[N],ans,n;
int get(int x){return fa[x]==x?x:get(fa[x]);}
int stkx[N],stky[N],tp;
void bk(){assert(tp),sz[stky[tp]]-=sz[stkx[tp]],fa[stkx[tp]]=stkx[tp],tp--;}
void merge(int x,int y){
	x=get(x),y=get(y);
	if(x==y)return;
	if(sz[x]>sz[y])swap(x,y); 
	fa[x]=y,sz[y]+=sz[x],tp++,stkx[tp]=x,stky[tp]=y;
}struct Tree{
	#define ls (k<<1)
	#define rs (k<<1|1)
	vector<pi> t[N<<2];
	void add(int k,int l,int r,int x,int y,pi e){
		if(x>y)return;
		if(x<=l&&r<=y)return t[k].push_back(e),void();
		int m=l+r>>1;if(x<=m)add(ls,l,m,x,y,e);
		if(y>m)add(rs,m+1,r,x,y,e);
	}
	void solve(int k,int l,int r){
		int now=tp;for(auto e:t[k])merge(e.fi,e.se);
		if(l==r){
			for(auto v:e[l])
				ans+=sz[get(v.fi)]*sz[get(v.se)];
		}else{
			int m=l+r>>1;
			solve(ls,l,m),solve(rs,m+1,r);
		}while(tp>now)bk();
	}
}T;
signed main(){
	int TTT=1;while(TTT--){
		For(i,1,n=read())fa[i]=i,sz[i]=1;
		For(i,2,n){
			int u=read(),v=read(),c=read();
			e[c].push_back(pi(u,v));
			T.add(1,1,n,1,c-1,pi(u,v)),T.add(1,1,n,c+1,n,pi(u,v));
		}T.solve(1,1,n);cout<<ans<<endl;
	}
	return 0;
}