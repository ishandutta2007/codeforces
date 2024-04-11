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
using namespace std;
typedef long long ll;

#define MAXN (1<<20)

vector<int> g[MAXN];
int n,lw[MAXN],idx[MAXN],qidx,cmp[MAXN],qcmp;
stack<int> st;
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
		int x,l=-1;
		do{x=st.top();st.pop();cmp[x]=qcmp;}
		while(x!=u);
		qcmp++;
	}
}
void scc(){
	memset(idx,0,n*sizeof(idx[0]));qidx=0;
	memset(cmp,-1,n*sizeof(cmp[0]));qcmp=0;
	fore(i,0,n)if(!idx[i])tjn(i);
}

bool ok[MAXN];

int m;
vector<int> r0,r1;

int main(){
	int tn;
	scanf("%d",&tn);
	while(tn--){
		scanf("%d%d",&n,&m);
		while(m--){
			int x,y;
			scanf("%d%d",&x,&y);x--;y--;
			if(x!=y)g[x].pb(y);
		}
		scc();
		if(qcmp==1){
			puts("No");
		}
		else {
			memset(ok,true,n*sizeof(ok[0]));
			fore(i,0,n)for(int j:g[i])if(cmp[i]!=cmp[j])ok[cmp[i]]=false;
			int k=0;
			fore(i,0,qcmp)if(ok[i])k=i;
			r0.clear();r1.clear();
			fore(i,0,n){
				if(cmp[i]==k)r0.pb(i);
				else r1.pb(i);
			}
			printf("Yes\n%d %d\n",SZ(r0),SZ(r1));
			fore(i,0,SZ(r0))printf("%d%c",r0[i]+1," \n"[i==SZ(r0)-1]);
			fore(i,0,SZ(r1))printf("%d%c",r1[i]+1," \n"[i==SZ(r1)-1]);
		}
		fore(i,0,n)g[i].clear();
	}
	return 0;
}