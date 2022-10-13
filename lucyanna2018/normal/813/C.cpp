#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
#define ran 222222
vector<int> e[ran];
int d1[ran],d2[ran];
int n,t;
void dfs(int x,int fat,int*d){
	for(vector<int>::iterator it = e[x].begin(); it!=e[x].end(); it++){
		int y = *it;
		if(y == fat)continue;
		d[y] = d[x]+1;
		dfs(y, x, d);
	}
}
int main(){
	scanf("%d%d",&n,&t);
	for(int i=1; i<n; i++){
		int x,y;
		scanf("%d%d",&x,&y);
		e[x].push_back(y);
		e[y].push_back(x);
	}
	d1[1] = 0;
	dfs(1,1,d1);
	d2[t] = 0;
	dfs(t,t,d2);
	int res = 0;
	for(int i=1; i<=n; i++)
		if(d2[i] < d1[i])
			res = max(res, 2 * d1[i]);
	printf("%d\n",res);
	return 0;
}