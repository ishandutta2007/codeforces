#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
using namespace std;
typedef long long ll;

int n;
vector<int> g[100005];
int w[100005];
double r[100005];

void dfs0(int x){
	w[x]=1;
	for(int y:g[x]){
		dfs0(y);
		w[x]+=w[y];
	}
}

void dfs1(int x){
	for(int y:g[x]){
		r[y]=r[x]+.5*(w[x]-w[y]-1)+1;
		dfs1(y);
	}
}

int main(){
	scanf("%d",&n);
	fore(i,1,n){
		int p;
		scanf("%d",&p);p--;
		g[p].pb(i);
	}
	dfs0(0);
	r[0]=1.;
	dfs1(0);
	fore(i,0,n)printf("%.1lf%c",r[i]," \n"[i==n-1]);
	return 0;
}