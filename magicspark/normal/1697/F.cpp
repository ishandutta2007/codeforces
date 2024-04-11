#include<bits/stdc++.h>
using namespace std;
#define pb push_back
const int N=2e4+10;
int n,m,k;
int f[N][11][2],tot=0;
vector<int>vs;
int vis[N*25],id[N*25],cnt=0;
vector<int>g[N*25],rg[N*25];
inline void ae(int x1,int y1,int z1,int x2,int y2,int z2){
//	cerr<<f[x1][y1][z1]<<" "<<f[x2][y2][z2]<<endl;
	g[f[x1][y1][z1]].pb(f[x2][y2][z2]);
	rg[f[x2][y2][z2]].pb(f[x1][y1][z1]);
}
void dfs(int x){
	vis[x]=true;
	for(auto to:g[x])if(!vis[to])dfs(to);
	vs.pb(x);
}
void rdfs(int x,int c){
	id[x]=c;vis[x]=true;
	for(auto to:rg[x])if(!vis[to])rdfs(to,c);
}
void solv(){
	for(int i=1;i<=tot;i++)g[i].clear(),rg[i].clear(),id[i]=0;tot=0;
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;i++)for(int j=1;j<=k;j++)for(int t=0;t<2;t++)f[i][j][t]=++tot;
	for(int i=1;i<=n;i++)ae(i,1,0,i,1,1);
	for(int i=1;i<=n;i++)for(int j=1;j+1<=k;j++)ae(i,j,0,i,j+1,0),ae(i,j+1,1,i,j,1);
	for(int i=1;i+1<=n;i++)for(int j=1;j<=k;j++)ae(i,j,1,i+1,j,1),ae(i+1,j,0,i,j,0);
	for(int tt=1;tt<=m;tt++){
		int op;scanf("%d",&op);
		if(op==1){
			int i,x;scanf("%d%d",&i,&x);
			if(x==1)ae(i,2,0,i,2,1);
			else if(x==k)ae(i,k,1,i,k,0);
			else ae(i,x,1,i,x+1,1),ae(i,x+1,0,i,x,0);
		}else if(op==2){
			int i,j,x;scanf("%d%d%d",&i,&j,&x);
			for(int _=0;_<2;_++){
				for(int t=1;t<=k;t++){
					if(x+1-t<=0)ae(i,t,1,i,t,0);
					else if(x+1-t<=k)ae(i,t,1,j,x+1-t,0);
				}
				swap(i,j);
			}
		}else{
			int i,j,x;scanf("%d%d%d",&i,&j,&x);
			for(int _=0;_<2;_++){
				for(int t=1;t<=k;t++){
					if(x+1-t>k)ae(i,t,0,i,t,1);
					else if(x+1-t>=1)ae(i,t,0,j,x+1-t,1);
				}
				swap(i,j);
			}
		}
	}
	for(int i=1;i<=tot;i++)vis[i]=false;vs.clear();
	for(int i=1;i<=tot;i++)if(!vis[i])dfs(i);
	for(int i=1;i<=tot;i++)vis[i]=false;cnt=0;
	for(int i=(int)vs.size()-1;i>=0;i--)if(!vis[vs[i]])rdfs(vs[i],++cnt);
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=k;j++)cerr<<id[f[i][j][0]]<<","<<id[f[i][j][1]]<<" ";
//		cerr<<endl;
//	}
	for(int i=1;i<=n;i++)for(int j=1;j<=k;j++){
		if(id[f[i][j][0]]==id[f[i][j][1]]){
			printf("-1\n");
			return;
		}
	}
	for(int i=1;i<=n;i++){
		int res=0;
		for(int j=1;j<=k;j++)if(id[f[i][j][0]]<id[f[i][j][1]])res=j;
		printf("%d ",res);
	}
	printf("\n");
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		solv();
	}
	return 0;
}
/*inline? ll or int? size? min max?*/
/*
1
4 0 4
*/
/*
1
2 2 3
3 1 2 3
1 2 2
*/
/*
1
3 3 2
1 1 1
2 2 3 2
3 2 3 2
*/
/*
1
5 5 5
3 2 5 7
2 4 5 10
3 4 5 6
3 3 4 7
2 1 5 7 
*/
/*
1
5 4 5
3 2 5 7
2 4 5 10
3 4 5 6
2 1 5 7
*/ 
/*
1
5 2 5
2 1 5 7
3 2 5 7
*/
/*
1
2 2 2
2 1 2 3 
3 1 2 3
*/
/*
1
2 6 3
2 1 2 4
3 1 2 2
3 1 2 6
3 1 2 4
1 2 1
1 2 1
*/