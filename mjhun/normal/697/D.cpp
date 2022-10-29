#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
using namespace std;

typedef long long ll;

int n;
vector<int> g[100005];
int c[100005];
double r[100005];

void dfs(int x){
	c[x]=1;
	for(int i=0;i<g[x].size();++i){
		int y=g[x][i];
		dfs(y);
		c[x]+=c[y];
	}
}

void calc(int x){
	for(int i=0;i<g[x].size();++i){
		int y=g[x][i];
		r[y]=r[x]+1+(c[x]-c[y]-1)/2.;
		calc(y);
	}
}

int main(){
	scanf("%d",&n);
	for(int i=1;i<n;++i){
		int p;
		scanf("%d",&p);p--;
		g[p].push_back(i);
	}
	dfs(0);
	r[0]=1;
	calc(0);
	printf("1.0");
	for(int i=1;i<n;++i)printf(" %.1lf",r[i]);
	puts("");
	return 0;
}