#include<bits/stdc++.h>
using namespace std;
const int N=500500;
int nxt[N];
int pnxt[N];
int p[N];
vector<int> es[N];
int c;
void dfs(int x){
	for(vector<int>::iterator it=es[x].begin();it!=es[x].end();++it){
		p[*it]=c--;
		dfs(*it);
	}
}
void work(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n+1;i++){
		es[i].clear();
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&nxt[i]);
		if(nxt[i]==-1){
			nxt[i]=i+1;
		}
		es[nxt[i]].push_back(i);
	}
	c=n;
	dfs(n+1);
	p[n+1]=INT_MAX;
	for(int i=n;i>=1;i--){
		for(pnxt[i]=i+1;p[i]>=p[pnxt[i]];pnxt[i]=pnxt[pnxt[i]]){}
		if(pnxt[i]!=nxt[i]){
			puts("-1");
			return;
		}
	}
	for(int i=1;i<=n;i++){
		printf("%d ",p[i]);
	}
	printf("\n");
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		work();
	}
	return 0;
}