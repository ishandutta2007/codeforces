#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<cstdlib>
using namespace std;

int m,n,a[1005][1005];
int main(){
	int cas; scanf("%d",&cas);
	while (cas--){
		scanf("%d%d",&m,&n);
		int i,j,t=m>>1;
		for (i=1; i<=m; i++)
			for (j=1; j<=n; j++) scanf("%d",&a[i][j]);
		int t1=0,t2=0;
		for (i=1; i<=n; i++){
			t1+=abs(a[t][i]-a[t+1][i]); t2+=abs(a[1][i]-a[m][i]);
		}
		puts((t1<t2)?"NO":"YES");
	}
}