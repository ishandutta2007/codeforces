#include <bits/stdc++.h>

#define FOR(i,a,b) for(int i=a;i<b;i++)
#define REP(i,b) FOR(i,0,b)
#define PB push_back

using namespace std;

int read(){
	int i;
	scanf("%d",&i);
	return i;
}

const int Nmax=123456;
vector<int> t1[Nmax],t2[Nmax];
bool use[Nmax];
int ans;
bool useDfs(int v,int p){
	bool a=use[v];
	for(auto c:t1[v])if(c!=p)
		a|=useDfs(c,v);
	if(a&&p!=-1){
		t2[v].PB(p);
		t2[p].PB(v);
		ans++;
	}
	return a;
}

int dist[Nmax];
void distDfs(int v,int p,int d){
	dist[v]=d;
	for(auto c:t2[v])if(c!=p)
		distDfs(c,v,d+1);
}

int main(){
	int n=read(),m=read();
	REP(i,n-1){
		int u=read()-1,v=read()-1;
		t1[u].PB(v);
		t1[v].PB(u);
	}
	int root;
	REP(i,m)
		use[root=read()-1]=true;
	if(m==1){
		printf("%d\n0\n",root+1);
		return 0;
	}
	useDfs(root,-1);
	distDfs(root,-1,0);
	int s=max_element(dist,dist+n)-dist;
	fill(dist,dist+n,0);
	distDfs(s,-1,0);
	int t=max_element(dist,dist+n)-dist;
	cout<<min(s,t)+1<<endl<<ans*2-dist[t]<<endl;
}