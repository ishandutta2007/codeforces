#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;
const int MAXN=1e5+5;
int n,k,b[MAXN],a[MAXN],s[MAXN];
int cnte,h[MAXN],to[MAXN<<1],nx[MAXN<<1];
inline void adde(int u,int v){
	cnte++;
	nx[cnte]=h[u];
	to[cnte]=v;
	h[u]=cnte;
	s[u]++;
}
int dep[MAXN];
void Dfs(int u){
	for(int i=h[u]; i; i=nx[i]){
		int v=to[i];
		dep[v]=dep[u]+1;
		Dfs(v);
	}
	return ;
}
inline bool cmp(int x,int y){
	if(dep[x]!=dep[y]) return dep[x]<dep[y];
	return s[x]<s[y];
}
int main(){
	int _; scanf("%d",&_);
	while(_--){
		scanf("%d",&n);
		cnte=0;
		for(int i=0; i<=n+1; i++)
			h[i]=s[i]=0;
		for(int i=1; i<=n; i++)
			scanf("%d",b+i),adde(b[i],i),a[i]=i;
		if(s[n+1]){
			dep[n+1]=0;
			Dfs(n+1);
			for(k=n; k; k--)
				if(dep[k]&1) break;
		}else{
			dep[0]=0;
			Dfs(0);
			for(k=0; k<n; k++)
				if(dep[k+1]&1) break;
		}
		sort(a+1,a+n+1,cmp);
		printf("%d\n",k);
		for(int i=1; i<=n; i++)
			printf("%d ",a[i]);
		puts("");
	}
	return 0;
}