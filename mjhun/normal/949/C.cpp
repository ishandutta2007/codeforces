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
#define SZ(x) ((int)(x).size())
#define mset(a,v) memset(a,v,sizeof(a))
#define mcopy(a,b) memcpy(a,b,sizeof(a))
using namespace std;
typedef long long ll;

#define MAXN 100005
vector<int> g[MAXN];
int n,lw[MAXN],idx[MAXN],qidx,cmp[MAXN],qcmp;
stack<int> st;
vector<int> c[MAXN];
void tjn(int u){
	lw[u]=idx[u]=++qidx;
	st.push(u);cmp[u]=-2;
	for(int v:g[u]){
		if(!idx[v]||cmp[v]==-2){
			if(!idx[v]) tjn(v);
			lw[u]=min(lw[u],lw[v]);
		}
	}
	if(lw[u]==idx[u]){
		int x;
		do{x=st.top();st.pop();cmp[x]=qcmp;c[cmp[x]].pb(x);}while(x!=u);
		qcmp++;
	}
}
void scc(){
	memset(idx,0,sizeof(idx));qidx=0;
	memset(cmp,-1,sizeof(cmp));qcmp=0;
	fore(i,0,n)if(!idx[i])tjn(i);
}

int m,h;
int t[MAXN];
vector<int> r;

int main(){
	scanf("%d%d%d",&n,&m,&h);
	fore(i,0,n)scanf("%d",t+i);
	while(m--){
		int a,b;
		scanf("%d%d",&a,&b);a--;b--;
		if((t[a]+1)%h==t[b])g[a].pb(b);
		if((t[b]+1)%h==t[a])g[b].pb(a);
	}
	scc();
	fore(i,0,qcmp){
		bool t=true;
		for(int x:c[i])for(int y:g[x])if(cmp[y]!=i)t=false;
		if(t){
			if(!SZ(r)||SZ(c[i])<SZ(r))r=c[i];
		}
	}
	printf("%d\n",SZ(r));
	fore(i,0,SZ(r))printf("%d%c",r[i]+1," \n"[i==SZ(r)-1]);
	return 0;
}