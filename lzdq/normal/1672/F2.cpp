#include<cstdio>
#include<algorithm>
#include<cstring>
typedef long long ll;
using namespace std;
const int MAXN=2e5+5;
int n,a[MAXN],b[MAXN];
int cnt[MAXN],mx;
int cnte,h[MAXN],to[MAXN],nx[MAXN],ind[MAXN];
inline void adde(int u,int v){
	cnte++;
	nx[cnte]=h[u];
	to[cnte]=v;
	h[u]=cnte;
	ind[v]++;
}
void Dfs(int u){
	ind[u]=-1;
	for(int i=h[u]; i; i=nx[i]){
		int v=to[i];
		if(!--ind[v]) Dfs(v);
	}
	return ;
}
bool Calc(){
	cnte=0;
	for(int i=1; i<=n; i++)
		cnt[i]=h[i]=ind[i]=0;
	for(int i=1; i<=n; i++)
		cnt[a[i]]++;
	mx=1;
	for(int i=2; i<=n; i++)
		if(cnt[i]>cnt[mx]) mx=i;
	for(int i=1; i<=n; i++)
		if(a[i]!=mx&&b[i]!=mx) adde(a[i],b[i]);
	for(int i=1; i<=n; i++)
		if(!ind[i]) Dfs(i);
	for(int i=1; i<=n; i++)
		if(~ind[i]) return 0;
	return 1;
}
int main(){
	int _; scanf("%d",&_);
	while(_--){
		scanf("%d",&n);
		for(int i=1; i<=n; i++)
			scanf("%d",a+i);
		for(int i=1; i<=n; i++)
			scanf("%d",b+i);
		if(Calc()) puts("AC");
		else puts("WA");
	}
	return 0;
}