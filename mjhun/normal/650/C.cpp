#include <bits/stdc++.h>
#define mp make_pair
#define fst first
#define snd second
using namespace std;

typedef long long ll;

int nr,nc,n;
int x[1<<20];
vector<int> g[1<<20];
int f[1<<20];
int uf[1<<20];
int sol[1<<20];
bool vis[1<<20];
stack<int> st;
vector<pair<int,int> > w;

int fnd(int x){
	if(uf[x]==x)return x;
	uf[x]=fnd(uf[x]);
	return uf[x];
}

void proc0(){
	sort(w.begin(),w.end());
	int i=0;
	while(i<w.size()){
		int j=i+1;
		while(j<w.size()&&w[j].fst==w[i].fst){
			uf[fnd(w[j].snd)]=fnd(w[i].snd);
			j++;
		}
		i=j;
	}
	w.clear();
}

void proc1(){
	sort(w.begin(),w.end());
	int i=0;
	while(i<w.size()){
		int j=i;
		while(j<w.size()&&w[j].fst==w[i].fst)j++;
		if(j<w.size())g[fnd(w[i].snd)].push_back(fnd(w[j].snd));
		i=j;
	}
	w.clear();
}

void dfs(int v){
	if(vis[v])return;
	vis[v]=true;
	for(int i=0;i<g[v].size();++i)dfs(g[v][i]);
	st.push(v);
}

int main(){
	scanf("%d%d",&nr,&nc);n=nr*nc;
	for(int i=0;i<n;++i){
		scanf("%d",x+i);
		uf[i]=i;
	}
	for(int i=0;i<nr;++i){
		for(int j=0;j<nc;++j){
			int k=i*nc+j;
			w.push_back(mp(x[k],k));
		}
		proc0();
	}
	for(int j=0;j<nc;++j){
		for(int i=0;i<nr;++i){
			int k=i*nc+j;
			w.push_back(mp(x[k],k));
		}
		proc0();
	}
	for(int i=0;i<nr;++i){
		for(int j=0;j<nc;++j){
			int k=i*nc+j;
			w.push_back(mp(x[k],k));
		}
		proc1();
	}
	for(int j=0;j<nc;++j){
		for(int i=0;i<nr;++i){
			int k=i*nc+j;
			w.push_back(mp(x[k],k));
		}
		proc1();
	}
	for(int i=0;i<n;++i)dfs(i);
	while(!st.empty()){
		int k=st.top();st.pop();if(fnd(k)!=k)continue;
		sol[k]=f[k]+1;
		for(int i=0;i<g[k].size();++i){
			f[g[k][i]]=max(f[g[k][i]],sol[k]);
		}
	}
	for(int i=0;i<nr;++i){
		for(int j=0;j<nc;++j){
			if(j)putchar(' ');
			printf("%d",sol[fnd(i*nc+j)]);
		}
		puts("");
	}
	return 0;
}