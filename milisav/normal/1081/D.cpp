#include<bits/stdc++.h>
using namespace std;
int par[150000];
int num[150000];
int n,m,k;
vector<pair<int,pair<int,int> > > e;
int x[150000];
void unite(int u,int v) {
	par[v]=u;
	num[u]+=num[v];
}
int parent(int u) {
	if(u==par[u]) return u;
	else par[u]=parent(par[u]);
	return par[u];
}
int main() {
	int u,v,w;
	scanf("%d %d %d",&n,&m,&k);
	for(int i=0;i<n;i++) par[i]=i;
	for(int i=0;i<k;i++) {
		scanf("%d",&x[i]);
		x[i]--;
		num[x[i]]=1;	
	}
	for(int i=0;i<m;i++) {
		scanf("%d %d %d",&u,&v,&w);
		u--;
		v--;
		e.push_back(make_pair(w,make_pair(u,v)));
	}
	sort(e.begin(),e.end());
	for(int i=0;i<m;i++) {
		w=e[i].first;
		u=e[i].second.first;
		v=e[i].second.second;
		u=parent(u);
		v=parent(v);
		if(u!=v) {
			unite(u,v);
			if(num[u]==k) { //Nasli smo ih sve
				for(int i=0;i<k;i++) {
					printf("%d ",w);
				}
				printf("\n");
				return 0;
			}
		}
	}
	return 0;
}