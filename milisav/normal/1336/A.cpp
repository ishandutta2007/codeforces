#include<bits/stdc++.h>
#define maxn 1000000
using namespace std;
int ch[maxn];
vector<int> a[maxn];
priority_queue<int> pq;
void dfs(int u,int p=-1,int d=0) {
	for(auto v:a[u]) {
		if(v!=p) {
			dfs(v,u,d+1);
			ch[u]+=ch[v];
		}
	}
	pq.push(d-ch[u]);
	ch[u]++;
}
int main() {
	int n,k;
	int u,v;
	scanf("%d %d",&n,&k);
	for(int i=0;i<n-1;i++) {
		scanf("%d %d",&u,&v);
		a[u].push_back(v);
		a[v].push_back(u);
	}
	dfs(1);
	long long ans=0;
	while(k>0) {
		ans+=(pq.top());
		pq.pop();
		k--;
	}
	printf("%lld",ans);
	return 0;
}