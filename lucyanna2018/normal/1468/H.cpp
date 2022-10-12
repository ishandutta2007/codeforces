#include<bits/stdc++.h>
using namespace std;
int N,K,M;
int a[222222];
int main(){
	int _;
	for(scanf("%d",&_); _--;){
		scanf("%d%d%d",&N,&K,&M);
		memset(a,0,sizeof(int)*(N+1));
		for(int i=0; i<M; i++){
			int x;
			scanf("%d",&x);
			a[x] = 1;
		}
		for(int i=1; i<=N; i++)
			a[i] = a[i-1] + 1 - a[i];
		if((N-M) % (K-1) != 0){
			puts("NO");
			continue;
		}
		K /= 2;
		bool sol = false;
		for(int i=1; i<=N && !sol; i++)if(a[i] == a[i-1] && a[i] >= K && a[N] - a[i] >= K)
			sol = true;
		puts(sol?"YES":"NO");
	}
	return 0;
}