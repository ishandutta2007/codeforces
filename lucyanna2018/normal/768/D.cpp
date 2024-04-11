#include<stdio.h>
int n;
double d[10001][1001],p[1001];
int main(){
	scanf("%d",&n);
	d[0][0] = 1;
	for(int j=0; j<=n; j++)
		p[j] = (double)j/n;
	for(int i=0; i<10000; i++)
		for(int j=0; j<=n && j<=i; j++){
			d[i+1][j] += d[i][j] * p[j];
			d[i+1][j+1] += d[i][j] * (1 - p[j]);
		}
	int q,x;
	for(scanf("%d",&q); q--;){
		scanf("%d",&x);
		double y = x / 2000.0;
		for(int i=0; i<10000; i++)
			if(d[i][n] >= y){
				printf("%d\n",i);
				break;
			}
	}
	return 0;
}