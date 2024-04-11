#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=2e5+10;
int n,m,ed[MAXN][2],ex[10],ey[10];
int pre[MAXN];
int fnd(int x){
	if(x!=pre[x]) pre[x]=fnd(pre[x]);
	return pre[x];
}
char ans[MAXN];
int main(){
	int _; scanf("%d",&_);
	while(_--){
		scanf("%d%d",&n,&m);
		for(int i=1; i<=n; i++)
			pre[i]=i;
		*ex=*ey=0;
		for(int i=1; i<=m; i++){
			int &u=ed[i][0],&v=ed[i][1];
			scanf("%d%d",&u,&v);
			int x=fnd(u),y=fnd(v);
			if(x==y) ex[++*ex]=i,ey[++*ey]=u,ey[++*ey]=v;
			else pre[x]=y;
			ans[i]=0;
		}
		sort(ey+1,ey+*ey+1);
		*ey=unique(ey+1,ey+*ey+1)-ey-1;
		if(*ex<3||*ey>3){
			for(int i=1; i<=*ex; i++)
				ans[ex[i]]=1;
		}else{
			int u=ed[ex[1]][0];
			ans[ex[2]]=ans[ex[3]]=1;
			for(int i=1; i<=m; i++){
				if(i==ex[1]||i==ex[2]||i==ex[3]) continue;
				int x=ed[i][0],y=ed[i][1];
				if(x==u||y==u)
					ans[i]=1;
			}
		}
		for(int i=1; i<=m; i++)
			ans[i]+='0';
		ans[m+1]=0;
		puts(ans+1);
	}
	return 0;
}