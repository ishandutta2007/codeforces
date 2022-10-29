#include <cstdio>

double w[128][128][128];

int main(){
	for(int i=1;i<=100;++i){
		for(int j=0;j<=100;++j){
			w[i][j][0]=1;
		}
	}
	for(int i=1;i<=100;++i){
		for(int j=1;j<=100;++j){
			for(int k=1;k<=100;++k){
				int q=i*j+i*k+j*k;
				w[i][j][k]+=1.*i*j*w[i][j-1][k];
				w[i][j][k]+=1.*i*k*w[i-1][j][k];
				w[i][j][k]+=1.*j*k*w[i][j][k-1];
				w[i][j][k]/=q;
			}
		}
	}
	int r,s,p;
	scanf("%d%d%d",&r,&s,&p);
	printf("%.12lf %.12lf %.12lf\n",w[r][s][p],w[s][p][r],w[p][r][s]);
	return 0;
}