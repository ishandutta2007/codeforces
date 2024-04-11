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

#define MAXN 400005
#define INF (1<<30)

ll r[MAXN];int k;

struct SuffixTree {
	int s[MAXN];
	map<int,int> to[MAXN];
	int len[MAXN]={INF},fpos[MAXN],link[MAXN],id[MAXN];
	int node,pos,sz=1,n=0;
	int make_node(int p, int l, int k){
		fpos[sz]=p;len[sz]=l;id[sz]=k;return sz++;}
	void go_edge(){
		while(pos>len[to[node][s[n-pos]]]){
			node=to[node][s[n-pos]];
			pos-=len[node];
		}
	}
	void add(int c, int k){
		s[n++]=c;pos++;
		int last=0;
		while(pos>0){
			go_edge();
			int edge=s[n-pos];
			int& v=to[node][edge];
			int t=s[fpos[v]+pos-1];
			if(v==0){
				v=make_node(n-pos,INF,k);
				link[last]=node;last=0;
			}
			else if(t==c){link[last]=node;return;}
			else {
				int u=make_node(fpos[v],pos-1,k);
				to[u][c]=make_node(n-1,INF,k);
				to[u][t]=v;
				fpos[v]+=pos-1;len[v]-=pos-1;
				v=u;link[last]=u;last=u;
			}
			if(node==0)pos--;
			else node=link[node];
		}
	}
	int w[MAXN];map<int,int> z[MAXN];
	void dfs(int x){
		if(!SZ(to[x])){
			w[x]=x;
			z[w[x]][id[x]]++;
			return;
		}
		w[x]=-1;
		for(auto _:to[x]){
			int y=_.snd;
			dfs(y);
			if(w[x]<0||SZ(z[w[y]])>SZ(z[w[x]]))w[x]=w[y];
		}
		if(!x)return;
		map<int,int>& a=z[w[x]];
		for(auto _:to[x]){
			int y=_.snd;
			if(w[y]==w[x])continue;
			for(auto p:z[w[y]])a[p.fst]+=p.snd;
		}
		if(SZ(a)>=k){
			for(auto p:a){
				r[p.fst]+=1LL*p.snd*len[x];
			}
		}
	}
	void doit(){dfs(0);}
};

int n;
SuffixTree t;
char _s[MAXN];

int main(){
	scanf("%d%d",&n,&k);
	fore(i,0,n){
		scanf("%s",_s);
		for(int j=0;_s[j];++j){
			t.add(_s[j],i);
			if(k==1)r[i]+=j+1;
		}
		t.add(-i,i);
	}
	if(k>1)t.doit();
	fore(i,0,n)printf("%lld%c",r[i]," \n"[i==n-1]);
	return 0;
}