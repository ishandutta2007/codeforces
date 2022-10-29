#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

vector<int> g[100005];
int n;
char res[100005];
int q[100005];

int dfs(int v, int f){
	if(res[v])return 0;
	q[v]=1;
	for(int i=0;i<g[v].size();++i){
		int s=g[v][i];
		if(s==f)continue;
		q[v]+=dfs(s,v);
	}
	return q[v];
}

int centroid(int v){
	int m=q[v],f=-1;
	while(1){
		int s=-1;
		for(int i=0;s<0&&i<g[v].size();++i){
			if(res[g[v][i]]||g[v][i]==f)continue;
			if(2*q[g[v][i]]>=m)s=g[v][i];
		}
		if(s<0)break;
		f=v;
		v=s;
	}
	return v;
}

void solve(int v, char r){
	dfs(v,-1);
	int k=centroid(v);
	res[k]=r;
	for(int i=0;i<g[k].size();++i){
		int s=g[k][i];
		if(!res[s])solve(s,r+1);
	}
}

int main(){
	scanf("%d",&n);
	for(int i=0;i<n-1;++i){
		int a,b;
		scanf("%d%d",&a,&b);a--;b--;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	solve(0,'A');
	for(int i=0;i<n;++i){
		if(i)putchar(' ');
		putchar(res[i]);
	}
	puts("");
	return 0;
}