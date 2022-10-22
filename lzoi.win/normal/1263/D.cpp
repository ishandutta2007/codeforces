#include<cstdio>
const int MAXN=2e5+5,MAXM=2e6+5;
int n,pre[MAXN];
int fnd(int x){
	if(x!=pre[x]) pre[x]=fnd(pre[x]);
	return pre[x];
}
char s[100];
int cnte,h[30],nx[MAXM],to[MAXM];
inline void adde(int u,int v){
	cnte++;
	nx[cnte]=h[u];
	to[cnte]=v;
	h[u]=cnte;
}
bool vis[MAXN];
int ans;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%s",s);
		for(int j=0;s[j];j++)
			adde(s[j]-'a',i);
		pre[i]=i;
	}
	for(int i=0;i<26;i++){
		int p=-1;
		for(int j=h[i];j;j=nx[j]){
			int v=fnd(to[j]);
			if(~p) pre[v]=p;
			else p=v;
		}
	}
	for(int i=1;i<=n;i++)
		vis[fnd(i)]=1;
	for(int i=1;i<=n;i++)
		if(vis[i]) ans++;
	printf("%d\n",ans);
	return 0;
}