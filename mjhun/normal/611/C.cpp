#include <bits/stdc++.h>
using namespace std;

int n,m;
char b[512][512];

int p[512][512];
int r[512][512];
int c[512][512];

int main(){
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;++i){
		scanf("%s",b[i]);
	}
	for(int i=0;i<n;++i){
		for(int j=0;j<m;++j){
			if(i<n-1&&b[i][j]=='.'&&b[i+1][j]=='.'){
				p[i+1][j+1]++;p[i+2][j+1]++;
				r[i][j+1]++;
			}
			if(j<m-1&&b[i][j]=='.'&&b[i][j+1]=='.'){
				p[i+1][j+1]++;p[i+1][j+2]++;
				c[j][i+1]++;
			}
		}
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			p[i][j]+=p[i-1][j]+p[i][j-1]-p[i-1][j-1];
		}
	}
	for(int i=0;i<n;++i){
		for(int j=1;j<=m;++j){
			r[i][j]+=r[i][j-1];
		}
	}
	for(int j=0;j<m;++j){
		for(int i=1;i<=n;++i){
			c[j][i]+=c[j][i-1];
		}
	}
	int q;
	scanf("%d",&q);
	while(q--){
		int i0,j0,i1,j1;
		scanf("%d%d%d%d",&i0,&j0,&i1,&j1);i0--;j0--;
		int s=p[i1][j1]-p[i0][j1]-p[i1][j0]+p[i0][j0]-r[i1-1][j1]+r[i1-1][j0]-c[j1-1][i1]+c[j1-1][i0];
		if(i0)s-=r[i0-1][j1]-r[i0-1][j0];
		if(j0)s-=c[j0-1][i1]-c[j0-1][i0];
		printf("%d\n",s/2);
	}
	return 0;
}