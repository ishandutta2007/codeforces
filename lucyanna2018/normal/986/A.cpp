#include<bits/stdc++.h>
using namespace std;
#define ran 101111
int N,M,K,S;
int a[ran];
vector<int> e[ran];
int d[ran][102];
int q[ran],op,cl;
int main(){
	scanf("%d%d%d%d",&N,&M,&K,&S);
	for(int i=1; i<=N; i++)scanf("%d",&a[i]);
	for(int i=0; i<M; i++){
		int x,y;
		scanf("%d%d",&x,&y);
		e[x].push_back(y);
		e[y].push_back(x);
	}
	for(int t=1; t<=K; t++){
		op=cl=0;
		for(int j=1; j<=N; j++)if(a[j]==t){
			d[j][t] = 0;
			q[op++] = j;
		}
		else
			d[j][t] = -1;
		while(cl<op){
			int x = q[cl++];
			for(auto y : e[x]){
				if(d[y][t] != -1)continue;
				d[y][t] = d[x][t] + 1;
				q[op++] = y;
			}
		}
	}
	for(int j=1; j<=N; j++){
		sort(d[j]+1, d[j]+K+1);
		int res = 0;
		for(int i=1; i<=S; i++)
			res += d[j][i];
		printf("%d%c",res,j<N?' ':'\n');
	}
	return 0;
}