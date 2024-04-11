#include <stdio.h>
#include <algorithm>
#include <string.h>

int t[102][102];
char c[100][100];

void solve(int n){
	int i,j;
	bool a;
	a=true;
	for(i=0;i<n+2;i++){
		t[0][i]=1;
		t[i][0]=1;
		t[n+1][i]=1;
		t[i][n+1]=1;
	}
	for(i=0;i<n;i++){
		scanf("%s",&c[i]);
	}
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(c[i][j]=='x') t[i+1][j+1]=1;
			else t[i+1][j+1]=-1;
		}
	}
/*	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			printf("%c",c[i][j]);
		}
		printf("\n");
	}
	for(i=0;i<n+2;i++){
		for(j=0;j<n+2;j++){
			printf("%d",t[i][j]);
		}
		printf("\n");
	}*/
	for(i=1;i<n+1&&a;i++){
		for(j=1;j<n+1&&a;j++){
			if(t[i][j-1]*t[i][j+1]*t[i-1][j]*t[i+1][j]==-1) a=false;
		}
	}
	if(a) printf("YES");
	else printf("NO");
}

int main(){
	int n;
	#pragma comment(linker, "/STACK:268435456")
	#ifndef ONLINE_JUDGE
	freopen("input.txt","rt",stdin);
	freopen("output.txt","wt",stdout);
	#endif
	while(scanf("%d",&n)!=EOF) solve(n);
}