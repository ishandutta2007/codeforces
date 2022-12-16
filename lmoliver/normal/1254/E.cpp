#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef vector<int> V;
#define F(N,S,E) for(int N=(int)(S);N<=(int)(E);N++)
#define R(N,S,E) for(int N=(int)(S);N>=(int)(E);N--)
#define D(N,E) for(int N=0;N<(int)(E);N++)
LL read(){LL x;scanf("%lld",&x);return x;}

const int N=5.1e5;

V es[N];
int dep[N];
int fa[N];
void dfs(int x,int fa){
	::fa[x]=fa;
	dep[x]=fa!=-1?dep[fa]+1:0;
	D(i,es[x].size()){
		int v=es[x][i];
		if(v==fa)continue;
		dfs(v,x);
	}
}

int lca(int u,int v){
	while(u!=v){
		if(dep[u]<dep[v])swap(u,v);
		u=fa[u];
	}
	return u;
}

const int MOD=1e9+7;
int mul(int a,int b){return (LL)a*b%MOD;}
int fr[N];

void gg(){
	puts("0");
	exit(0);
}

map<int,int> st[N],ed[N];
void link(int m,int l,int r){
	// cerr<<"link "<<m<<" "<<l<<" "<<r<<endl;
	map<int,int> &st=::st[m],&ed=::ed[m];

	if(!ed.insert(make_pair(l,r)).second)gg();
	if(!st.insert(make_pair(r,l)).second)gg();

	int head=st.count(l)?st[l]:l,tail=ed.count(r)?ed[r]:r;
	ed[head]=tail;
	st[tail]=head;

	if(head==r&&st.size()!=es[m].size()+1)gg();
}

int a[N];
int main(){
	int n=read();
	F(i,0,n)fr[i]=i?mul(fr[i-1],i):1;
	D(_,n-1){
		int u=read(),v=read();
		es[u].push_back(v);
		es[v].push_back(u);
	}
	dfs(1,-1);
	F(i,1,n)a[i]=read();
	F(i,1,n)if(a[i]){
		int l=lca(i,a[i]);
		int dis=dep[i]+dep[a[i]]-2*dep[l];
		V p(dis+1);
		
		int cur=i;
		int j=0;
		while(cur!=l){
			p[j++]=cur;
			cur=fa[cur];
		}
		
		cur=a[i];
		j=dis;
		while(true){
			p[j--]=cur;
			if(cur==l)break;
			cur=fa[cur];
		}

		// cerr<<i<<" "<<a[i]<<" d="<<dis<<endl;
		// F(i,0,dis)cerr<<"p["<<i<<"]="<<p[i]<<endl;
		F(i,0,dis){
			int l=p[max(i-1,0)],m=p[i],r=p[min(i+1,dis)];
			link(m,l,r);
		}
	}

	int ans=1;
	F(i,1,n){
		int w=es[i].size()+1-ed[i].size();
		ans=mul(ans,w?fr[w-1]:1);
	}
	printf("%d\n",ans);
	return 0;
}