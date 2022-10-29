#include <cstdio>
#include <iostream>
using namespace std;

int n;
double pr[32][32];
double dp[1<<18];
bool calc[1<<18];

double back(int mask,int m){
	if(calc[mask])return dp[mask];
	int i,j;
	double r=0;
	for(i=0;i<n;++i){
		for(j=0;j<n;++j){
			if(((mask>>i)&1)&&(!((mask>>j)&1))){
				r+=pr[i][j]*back(mask|(1<<j),m+1);
			}
		}
	}
	r/=((m+1)*m)/2;
	calc[mask]=true;
	dp[mask]=r;
	return r;
}

int main(){
	int i,j;
	scanf("%d",&n);
	for(i=0;i<n;++i){
		for(j=0;j<n;++j){
			scanf("%lf",&(pr[i][j]));
		}
	}
	calc[(1<<n)-1]=true;
	dp[(1<<n)-1]=1.;
	for(i=0;i<n;++i){
		printf("%.6lf ",back(1<<i,1));
	}
	putchar('\n');
	return 0;
}