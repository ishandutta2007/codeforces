#include<bits/stdc++.h>
using namespace std;
const int N=1009;

int n,e[N][N],base[2]={6,3};

void build() {
	for(int i=base[n%2]+2;i<=n;i+=2) {
		for(int j=1;j<=i-2;j++) e[i][j]=e[j][i-1]=1;
		e[i-1][i]=1;
	}
}

int main() {
	scanf("%d",&n);
	if(n&1) e[1][2]=e[2][3]=e[3][1]=1;
	else e[1][2]=e[1][3]=e[1][4]=e[2][3]=e[2][4]=e[2][5]=e[3][4]=e[3][6]
		=e[4][5]=e[4][6]=e[5][1]=e[5][3]=e[5][6]=e[6][1]=e[6][2]=1;
	if(n==4) return puts("-1"), 0;
	build();
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=n;j++) printf("%d ",e[i][j]);
		putchar('\n');
	}
	return 0;
}