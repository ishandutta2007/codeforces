#include <cstdio>
#include <vector>
using namespace std;

vector<int> g[500000];
unsigned char let[500001];
int d[500000];
int pre[500000];
int pos[500000];
vector<int> cnt[500000];
vector<int> vd[500000];
int prei,posi;
int n,m;

void dfs(int v){
	pre[v]=prei++;
	int k=d[v];
	int x=cnt[k].size();
	cnt[k].push_back(1<<(let[v]-'a'));
	if(x)cnt[k][x]^=cnt[k][x-1];
		
	vd[k].push_back(v);
	
	for(int i=0;i<g[v].size();++i){
		int s=g[v][i];
		d[s]=k+1;
		dfs(s);
	}
	pos[v]=posi++;
	g[v].clear();
}

int bs1(int v,int h){
	int s=0,e=vd[h].size();
	while(s+1<e){
		int m=(s+e)/2;
		if(pre[vd[h][m]]<pre[v]&&pos[vd[h][m]]<pos[v]) s=m;
		else e=m;
	}
	if(pre[vd[h][s]]>pre[v]&&pos[vd[h][s]]<pos[v])return s;
	return s+1;
}

int bs2(int v,int h){
	int s=0,e=vd[h].size();
	while(s+1<e){
		int m=(s+e)/2;
		if(pos[vd[h][m]]<pos[v]) s=m;
		else e=m;
	}
	return s;
}


int query(int v,int h){
	if(h<=d[v])return true;
	if(!vd[h].size())return true;
	int s=bs1(v,h),e=bs2(v,h);
	//~ printf("%d %d\n",s,e);
	if(s>=e||pre[vd[h][s]]<pre[v]||pos[vd[h][s]]>pos[v]||pre[vd[h][e]]<pre[v]||pos[vd[h][e]]>pos[v])return true;
	int r;
	if(s)r=cnt[h][e]^cnt[h][s-1];
	else r=cnt[h][e];
	return __builtin_popcount(r)<=1;
}

int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<n;++i){
		int f;
		scanf("%d",&f);
		g[f-1].push_back(i);
	}
	scanf("%s",let);
	dfs(0);
	while(m--){
		int v,h;
		scanf("%d%d",&v,&h);
		puts(query(v-1,h-1)?"Yes":"No");
	}
	return 0;
}