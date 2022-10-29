#include <stdio.h>
#define max(a,b) ((a)>(b)?(a):(b))

int m[4096][4];
int f[4096][4];

int main(){
	int n,i,j;
	scanf("%d",&n);
	for(j=0;j<3;++j){
		for(i=0;i<n;++i){
			scanf("%d",&(m[i][j]));
		}
		f[0][j]=m[0][j];
	}
	for(i=1;i<n;++i){
		for(j=0;j<2;++j){
			f[i][j]=max(m[i][j]+f[i-1][1],m[i][j+1]+f[i-1][0]);
		}
	}
	printf("%d\n",f[n-1][0]);
	return 0;
}