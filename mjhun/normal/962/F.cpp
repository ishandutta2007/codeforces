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
#define mcpy(a,b) memcpy(a,b,sizeof(a))
using namespace std;
typedef long long ll;

#define MAXN 100005

vector<int> g[MAXN];int n;
struct edge {int u,v,comp;};
vector<edge> e;
void add_edge(int u, int v){
	g[u].pb(e.size());g[v].pb(e.size());
	e.pb((edge){u,v,-1});
}
int D[MAXN],B[MAXN],T;
int nbc;
stack<int> st;
void dfs(int u,int pe){
	B[u]=D[u]=T++;
	for(int ne:g[u])if(ne!=pe){
		int v=e[ne].u^e[ne].v^u;
		if(D[v]<0){
			st.push(ne);dfs(v,ne);
			if(B[v]>=D[u]){
				int last;
				do {
					last=st.top();st.pop();
					e[last].comp=nbc;
				} while(last!=ne);
				nbc++;
			}
			B[u]=min(B[u],B[v]);
		}
		else if(D[v]<D[u])st.push(ne),B[u]=min(B[u],D[v]);
	}
}
void doit(){
	memset(D,-1,sizeof(D));
	nbc=T=0;
	fore(i,0,n)if(D[i]<0)dfs(i,-1);
}

int m;
vector<int> r;
set<int> a[100005],b[100005];

int main(){
	scanf("%d%d",&n,&m);
	fore(_,0,m){
		int x,y;
		scanf("%d%d",&x,&y);x--;y--;
		add_edge(x,y);
	}
	doit();
	fore(i,0,m){
		a[e[i].comp].insert(i);
		b[e[i].comp].insert(e[i].u);
		b[e[i].comp].insert(e[i].v);
	}
	fore(i,0,nbc)if(SZ(a[i])==SZ(b[i]))for(int j:a[i])r.pb(j);
	sort(r.begin(),r.end());
	printf("%d\n",SZ(r));
	fore(i,0,SZ(r)){
		if(i)putchar(' ');
		printf("%d",r[i]+1);
	}
	puts("");
	return 0;
}