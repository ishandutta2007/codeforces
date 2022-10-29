#include <cassert>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

bool vis[16][16][16];
bool free[16][16][16];
int k,m,n;

void dfs(int l, int i, int j){
	if(l<1||i<1||j<1||l>k||i>m||j>n||vis[l][i][j]||!free[l][i][j])return;
	vis[l][i][j]=true;
	dfs(l-1,i,j);
	dfs(l+1,i,j);
	dfs(l,i-1,j);
	dfs(l,i+1,j);
	dfs(l,i,j-1);
	dfs(l,i,j+1);
}

int main(){
	int i,j,l,x,y,r=0;
	scanf("%d %d %d",&k,&m,&n);
	assert(getchar()=='\n');
	for(l=1;l<=k;++l){
		assert(getchar()=='\n');
		for(i=1;i<=m;++i){
			for(j=1;j<=n;++j){
				if(getchar()=='.')
					free[l][i][j]=true;
			}
			assert(getchar()=='\n');
		}
	}
	scanf("%d %d",&x,&y);
	
	dfs(1,x,y);
	
	for(l=1;l<=k;++l){
		for(i=1;i<=m;++i){
			for(j=1;j<=n;++j){
				r+=vis[l][i][j];
			}
		}
	}
	
	printf("%d\n",r);
	
	return 0;
}