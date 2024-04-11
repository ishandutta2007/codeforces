#include<bits/stdc++.h>
using namespace std;
int n;
long long s[200000];
long long a[200000];
int p[200000];
vector<int> r[200000];
void dfs(int u,int h)
{
	int v;
	long long g=-1;
	if(h%2==0) {
		for(int i=0;i<r[u].size();i++) {
			v=r[u][i];
			if(g==-1 || s[v]<g) g=s[v];
		}
		if(g==-1) g=s[p[u]];
		a[u]=g-s[p[u]];
		s[u]=s[p[u]]+a[u];
	}
	else {
		if(u!=1) a[u]=s[u]-s[p[u]];
	}
	for(int i=0;i<r[u].size();i++) {
		v=r[u][i];
		dfs(v,h+1);
	}
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) a[i]=-1;
	for(int i=2;i<=n;i++) {
		scanf("%d",&p[i]);
		r[p[i]].push_back(i);
	}
	for(int i=1;i<=n;i++) scanf("%lld",&s[i]);
	a[1]=s[1];
	dfs(1,1);
	long long t=0;
	for(int i=1;i<=n;i++) {
		if(a[i]<0) {
			printf("-1");
			return 0;
		}
		t+=a[i];
	}
	printf("%lld",t);
	return 0;
}