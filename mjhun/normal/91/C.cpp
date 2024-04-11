#include <bits/stdc++.h>
#ifdef DEMETRIO
#define deb(...) fprintf(stderr,__VA_ARGS__)
#define deb1(x) cerr << #x << " = " << x << endl
#else
#define deb(...) 0
#define deb1(x) 0
#endif
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
#define SZ(x) ((int)x.size())
#define MOD 1000000009
using namespace std;
typedef long long ll;

struct STree {
	vector<int> st,lazy;int n;
	STree(int n): st(4*n+5,1), lazy(4*n+5,0), n(n) {}
	void init(int k, int s, int e){
		st[k]=e-s;
		if(s+1<e){
			int m=(s+e)/2;
			init(2*k,s,m);init(2*k+1,m,e);
		}
	}
	void push(int k, int s, int e){
		if(!lazy[k])return;
		st[k]=0;
		if(s+1<e){
			lazy[2*k]=1;
			lazy[2*k+1]=1;
		}
		lazy[k]=0;
	}
	void upd(int k, int s, int e, int a, int b){
		push(k,s,e);
		if(s>=b||e<=a)return;
		if(s>=a&&e<=b){
			lazy[k]=1;
			push(k,s,e);return;
		}
		int m=(s+e)/2;
		upd(2*k,s,m,a,b);upd(2*k+1,m,e,a,b);
		st[k]=st[2*k]+st[2*k+1];
	}
	int query(int k, int s, int e, int a, int b){
		if(s>=b||e<=a)return 0;
		push(k,s,e);
		if(s>=a&&e<=b)return st[k];
		int m=(s+e)/2;
		return query(2*k,s,m,a,b)+query(2*k+1,m,e,a,b);
	}
	void init(){init(1,0,n);}
	void upd(int a, int b){upd(1,0,n,a,b);}
	int query(int a, int b){return query(1,0,n,a,b);}
};

#define MAXN 100005

vector<int> g[MAXN];int n;
int wg[MAXN],dad[MAXN],dep[MAXN];
void dfs1(int x){
	wg[x]=1;
	for(int y:g[x])if(y!=dad[x]){
		dad[y]=x;dep[y]=dep[x]+1;dfs1(y);
		wg[x]+=wg[y];
	}
}
int curpos,pos[MAXN],head[MAXN];
void hld(int x, int c){
	if(c<0)c=x;
	pos[x]=curpos++;head[x]=c;
	int mx=-1;
	for(int y:g[x])if(y!=dad[x]&&(mx<0||wg[mx]<wg[y]))mx=y;
	if(mx>=0)hld(mx,c);
	for(int y:g[x])if(y!=mx&&y!=dad[x])hld(y,-1);
}
void hld_init(){
	curpos=0;
	memset(dad,-1,sizeof(dad));
	fore(i,0,n)if(dad[i]<0){
		dep[i]=0;dfs1(i);hld(i,-1);
	}
}
int query(int x, int y, STree& rmq){
	int r=0;
	while(head[x]!=head[y]){
		if(dep[head[x]]>dep[head[y]])swap(x,y);
		r+=rmq.query(pos[head[y]],pos[y]+1);
		y=dad[head[y]];
	}
	if(dep[x]>dep[y])swap(x,y);
	r+=rmq.query(pos[x]+1,pos[y]+1);
	return r;
}
void upd(int x, int y, STree& rmq){
	while(head[x]!=head[y]){
		if(dep[head[x]]>dep[head[y]])swap(x,y);
		rmq.upd(pos[head[y]],pos[y]+1);
		y=dad[head[y]];
	}
	if(dep[x]>dep[y])swap(x,y);
	rmq.upd(pos[x]+1,pos[y]+1);

}

int uf[100005];
int find(int x){
	if(uf[x]<0)return x;
	return uf[x]=find(uf[x]);
}
void join(int x, int y){
	if(uf[x]>uf[y])swap(x,y);
	uf[x]+=uf[y];
	uf[y]=x;
}

int m,a[100005],b[100005];
int r[200005];
bool t[200005];

int main(){
	memset(uf,-1,sizeof(uf));
	r[0]=0;
	fore(i,1,200005)r[i]=(r[i-1]*2+1)%MOD;
	scanf("%d%d",&n,&m);
	fore(i,0,m){
		scanf("%d%d",a+i,b+i);
		int x=find(a[i]),y=find(b[i]);
		if(x!=y){t[i]=true;g[a[i]].pb(b[i]);g[b[i]].pb(a[i]);join(x,y);}
	}
	hld_init();
	STree w(n);
	int nc=n,nb=0;
	fore(i,0,m){
		if(t[i])nb++;
		else {int k=query(a[i],b[i],w);upd(a[i],b[i],w);nb-=k;nc-=k;}
		printf("%d\n",r[i+1-nb-n+nc]);
	}
	return 0;
}