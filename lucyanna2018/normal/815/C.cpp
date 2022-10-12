#include<stdio.h>
#include<vector>
using namespace std;
int n,b,pr1[5555],pr2[5555],fat[5555];
int sz[5555];
vector<int> e[5555];
long long int dp[5555][5555][2];
const long long int inf = 100000000000000000LL;
void upd(long long int&x,long long int y){
	if(x>y)x=y;
}
void dfs(int x){
	sz[x] = 1;
	
	for(int i=0; i<=n; i++){
		dp[x][i][0] = dp[x][i][1] = inf;
	}
	dp[x][0][0] = 0;
	dp[x][1][0] = pr1[x];
	dp[x][1][1] = pr2[x];
	for(vector<int>::iterator it = e[x].begin(); it!=e[x].end(); it++){
		int y = *it;
		dfs(y);
		for(int i=sz[x]; i>=1; i--)
		for(int j=sz[y]; j>=0; j--)
			upd(dp[x][i+j][1],dp[x][i][1] + min(dp[y][j][0], dp[y][j][1]));

		for(int i=sz[x]; i>=0; i--)
		for(int j=sz[y]; j>=0; j--)
			upd(dp[x][i+j][0],dp[x][i][0] + dp[y][j][0]);
		sz[x] += sz[y];
	}
}
int main(){
	scanf("%d%d%d%d",&n,&b,&pr1[1],&pr2[1]);
	for(int i=2; i<=n; i++){
		scanf("%d%d%d",&pr1[i],&pr2[i],&fat[i]);
		e[fat[i]].push_back(i);
	}
	for(int i=1; i<=n; i++)
		pr2[i] = pr1[i] - pr2[i];
	dfs(1);
	int res = 0;
	for(int i=1; i<=n; i++)
		if(dp[1][i][0] <= b || dp[1][i][1] <= b)
			res = i;
	printf("%d\n",res);
	return 0;
}