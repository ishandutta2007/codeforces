#include<bits/stdc++.h>
#define ran 222222
using namespace std;
int n;
vector<int> e[ran];
int d[ran],col[ran];
void dfs(int v,int fat,int c1,int c2){
	col[v] = c1;
	int T = 0;
	for(vector<int>::iterator it = e[v].begin(); it!=e[v].end(); it++){
		int y = *it;
		if(y == fat)continue;
		++T;
		while(T == c1 || T == c2)T++;
		dfs(y, v, T, c1);
	}
}
int main(){
	scanf("%d",&n);
	for(int i=1; i<n; i++){
		int x,y;
		scanf("%d%d",&x,&y);
		e[x].push_back(y);
		e[y].push_back(x);
		d[x]++;
		d[y]++;
	}
	int k = 0;
	for(int i=1; i<=n; i++)
		k = max(k, d[i]);
	printf("%d\n",k+1);
	dfs(1,-1,1,-1);
	for(int i=1; i<=n; i++)
		printf("%d%c",col[i],i<n?' ':'\n');
	return 0;
}