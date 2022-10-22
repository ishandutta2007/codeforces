#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
typedef long long ll;
using namespace std;
const int MAXN=2e5+5;
int n;
int cnte,h[MAXN<<1],to[MAXN<<2],nx[MAXN<<2],d[MAXN<<1];
inline void adde(int u,int v){
	cnte++;
	nx[cnte]=h[u];
	to[cnte]=v;
	h[u]=cnte;
	d[v]++;
}
int ed[MAXN][2];
int fa[MAXN];
bool f[MAXN],c[MAXN],ans;
void Dfs(int u){
	int s=0;
	for(int i=h[u]; i; i=nx[i]){
		int v=to[i];
		if(v==fa[u]) continue;
		fa[v]=u;
		Dfs(v);
		if(f[v]) s++;
		else s--;
		c[i+1>>1]=f[v];
	}
	int t=(d[u]&1)-s;
	if(u>1){
		if(t==1) f[u]=1;
		else if(t==-1) f[u]=0;
		else ans=0;
	}else if(t) ans=0;
	return ;
}
void P(int u){
	d[u]=-1;
	printf("%d %d\n",ed[u-n][0],ed[u-n][1]);
	for(int i=h[u]; i; i=nx[i]){
		int v=to[i];
		if(!--d[v]) P(v);
	}
	return ;
}
int main(){
	//freopen("in1.txt","r",stdin);
	int _; scanf("%d",&_);
	while(_--){
		scanf("%d",&n);
		cnte=0;
		for(int i=1; i<=n*2; i++)
			h[i]=fa[i]=d[i]=0;
		for(int i=1; i<n; i++){
			int u,v;
			scanf("%d%d",&u,&v);
			ed[i][0]=u;
			ed[i][1]=v;
			adde(u,v);
			adde(v,u);
		}
		ans=1;
		Dfs(1);
		if(ans){
			puts("YES");
			for(int u=1; u<=n; u++){
				vector<int> s[2];
				for(int i=h[u]; i; i=nx[i]){
					int e=i+1>>1;
					s[c[e]].push_back(e);
				}
				if(d[u]&1){
					for(int i=0; i<s[0].size(); i++)
						adde(s[1][i]+n,s[0][i]+n),adde(s[0][i]+n,s[1][i+1]+n);
				}else{
					for(int i=0; i<s[0].size(); i++){
						adde(s[0][i]+n,s[1][i]+n);
						if(i+1<s[0].size()) adde(s[1][i]+n,s[0][i+1]+n);
					}
				}
			}
			for(int i=n+1; i<n*2; i++)
				if(!d[i]) P(i);
		}else puts("NO");
	}
	return 0;
}