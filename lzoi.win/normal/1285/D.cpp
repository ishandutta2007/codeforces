#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN=1e5+5;
int n;
int cntp,rt,lc[MAXN<<5],rc[MAXN<<5];
void Add(int x){
    int *k=&rt;
    for(int i=30; i>=0; i--){
        if(!*k) *k=++cntp;
        if((1<<i)&x) k=rc+*k;
        else k=lc+*k;
    }
    if(!*k) *k=++cntp;
    return ;
}
int f[MAXN<<5];
void Dfs(int u,int d){
	if(d<0) return ;
	if(lc[u]) Dfs(lc[u],d-1);
	if(rc[u]) Dfs(rc[u],d-1);
	if(lc[u]&&rc[u]) f[u]=(1<<d)|min(f[lc[u]],f[rc[u]]);
	else if(lc[u]) f[u]=f[lc[u]];
	else f[u]=f[rc[u]];
	return ;
}
int main(){
	scanf("%d",&n);
	while(n--){
		int a;scanf("%d",&a);
		Add(a);
	}
	Dfs(rt,30);
	printf("%d\n",f[rt]);
	return 0;
}