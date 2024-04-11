#include<stdio.h>
#include<vector>
using namespace std;
int n,p[222222];
int res[222222];
vector<int> e[222222];
int r[444],lr;
int ct[444];
int gcd(int x,int y){
	return y?gcd(y,x%y):x;
}
void dfs(int x,int fat,int lst,int len){
	res[x] = lst;
	for(int i=lr-1; i>=0; i--){
		if(p[x] % r[i] == 0)ct[i] ++;
		if(ct[i] >= len - 1)
			res[x] = max(res[x], r[i]);
	}
	for(vector<int>::iterator it = e[x].begin(); it != e[x].end(); it++){
		int y = *it;
		if(y == fat)continue;
		dfs(y, x, gcd(lst, p[y]),len+1);
	}
	for(int i=lr-1; i>=0; i--)
		if(p[x] % r[i] == 0)ct[i] --;
}
int main(){
	scanf("%d",&n);
	for(int i=1; i<=n; i++)
		scanf("%d",&p[i]);
	for(int i=1; i<n; i++){
		int x,y;
		scanf("%d%d",&x,&y);
		e[x].push_back(y);
		e[y].push_back(x);
	}
	for(int i=1; i<=p[1]; i++)if(p[1]%i==0)
		r[lr++] = i;
	res[1] = p[1];
	dfs(1,1,0,1);
	for(int i=1; i<=n; i++)
		printf("%d%c",res[i],i<n?' ':'\n');
	return 0;
}