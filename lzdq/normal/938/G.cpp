#include<cstdio>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;
typedef pair<int,int> pr;
#define mkp make_pair
const int MAXN=2e5+5,MAXM=2e7;
int top;
struct Change{
	int *x,v;
}stk[MAXM];
inline void c(int &x,int y){
	if(x!=y){
		stk[++top]=(Change){&x,x};
		x=y;
	}
}
int n,m,q;
struct Basis{
	int a[30];
	int Min(int x){
		for(int i=29; ~i; i--)
			x=min(x,x^a[i]);
		return x;
	}
	void Ins(int x){
		for(int i=29; ~i; i--)
			if(x>>i&1){
				if(a[i]) x^=a[i];
				else return c(a[i],x);
			}
	}
}bas;
map<pr,pr> mp;
vector<pair<pr,int> > vec[MAXN<<2];
int qs[MAXN][2];
int pre[MAXN],sum[MAXN],siz[MAXN],fw[MAXN];
int fnd(int x){
	if(x==pre[x]) return sum[x]=0,x;
	int res=fnd(pre[x]);
	sum[x]=sum[pre[x]]^fw[x];
	return res;
}
#define lc k<<1
#define rc k<<1|1
#define ls lc,l,mid
#define rs rc,mid+1,r
void Modify(int k,int l,int r,int x,int y,int u,int v,int w){
	if(x<=l&&r<=y){
		vec[k].push_back(mkp(mkp(u,v),w));
		return ;
	}
	int mid=l+r>>1;
	if(x<=mid) Modify(ls,x,y,u,v,w);
	if(mid<y) Modify(rs,x,y,u,v,w);
	return ;
}
void Query(int k,int l,int r){
	int tp=top;
	for(auto i:vec[k]){
		int u=i.first.first,v=i.first.second,w=i.second;
		int x=fnd(u),y=fnd(v);
		if(x==y) bas.Ins(sum[u]^sum[v]^w);
		else{
			if(siz[x]>siz[y]) swap(x,y),swap(u,v);
			c(pre[x],y);
			c(siz[y],siz[x]+siz[y]);
			fw[x]=w^sum[u]^sum[v];
		}
	}
	vec[k].clear();
	if(l==r){
		if(qs[l][0]){
			int u=qs[l][0],v=qs[l][1];
			fnd(u),fnd(v);
			int w=sum[u]^sum[v];
			printf("%d\n",bas.Min(w));
		}
	}else{
		int mid=l+r>>1;
		Query(ls);
		Query(rs);
	}
	while(top>tp){
		*stk[top].x=stk[top].v;
		top--;
	}
	return ;
}
int main(){
	scanf("%d%d",&n,&m);
	while(m--){
		int x,y,d;
		scanf("%d%d%d",&x,&y,&d);
		if(x>y) swap(x,y);
		mp[mkp(x,y)]=mkp(d,1);
	}
	scanf("%d",&q);
	for(int i=1; i<=q; i++){
		int op,x,y,d;
		scanf("%d%d%d",&op,&x,&y);
		if(x>y) swap(x,y);
		if(op==1){
			scanf("%d",&d);
			mp[mkp(x,y)]=mkp(d,i);
		}else if(op==2){
			pr it=mp[mkp(x,y)];
			Modify(1,1,q,it.second,i,x,y,it.first);
			mp.erase(mkp(x,y));
		}else qs[i][0]=x,qs[i][1]=y;
	}
	for(auto i:mp)
		Modify(1,1,q,i.second.second,q,i.first.first,i.first.second,i.second.first);
	mp.clear();
	for(int i=1; i<=n; i++)
		pre[i]=i,siz[i]=1;
	Query(1,1,q);
	return 0;
}