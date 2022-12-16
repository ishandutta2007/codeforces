#include<bits/stdc++.h>
using namespace std;
int dis(int x){
	printf("d %d\n",x);
	fflush(stdout);
	int r;
	scanf("%d",&r);
	return r;
}
int nxt(int x){
	printf("s %d\n",x);
	fflush(stdout);
	int r;
	scanf("%d",&r);
	return r;
}
void answer(int x){
	printf("! %d\n",x);
	fflush(stdout);
	exit(0);
}
const int N=200200;
vector<int> es[N];
void ae(int u,int v){
	es[u].push_back(v);
}
#define Fs(x) for(vector<int>::iterator it=es[x].begin();it!=es[x].end();++it)
int sz[N];
bool h[N]={false};
int dep[N];
void dfs1(int x,int fa=-1){
	dep[x]=fa==-1?0:dep[fa]+1;
	sz[x]=1;
	int mx=-1;
	Fs(x){
		if(*it==fa)continue;
		dfs1(*it,x);
		if(mx==-1||sz[*it]>sz[mx])mx=*it;
		sz[x]+=sz[*it];
	}
	if(mx!=-1)h[mx]=true;
}
int bot[N];
int dfn[N];
int ord[N];
int dft=0;
void dfs2(int x,int fa=-1){
	dfn[x]=++dft;
	ord[dft]=x;
	bot[x]=x;
	Fs(x)if(*it!=fa&&h[*it]){
		dfs2(*it,x);
		bot[x]=bot[*it];
	}
	Fs(x)if(*it!=fa&&!h[*it])dfs2(*it,x);
}
int n;
int main(){
	scanf("%d",&n);
	for(int i=0;i<n-1;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		ae(u,v);
		ae(v,u);
	}
	dfs1(1);
	dfs2(1);
	int adep=dis(1);
	for(int head=1;;){
		int qp=bot[head];
		if(qp==head){
			answer(head);
		}
		int d=dis(qp);
		int qd=dep[qp];
		if(adep+d==qd){
			answer(ord[dfn[head]+adep-dep[head]]);
		}
		else{
			int lcad=adep-(adep+d-qd)/2;
			head=nxt(ord[dfn[head]+lcad-dep[head]]);
		}
	}
	return 0;
}