#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 1000000000000000000

int main(){
	
	vector<int> num(17,0);
	int T = 720720;
	rep(i,35){
		if(i==0)continue;
		int x = i*i*i*i;
		
		for(int j=1;j<=16;j++){
			if(T + x <= 1000000 && (T+x)%j==0)num[j] = T+x;
			if(T-x>=1&&(T-x)%j==0)num[j] = T-x;
		}
		
		
		
	}
	
	int n,m;
	scanf("%d %d",&n,&m);
	
	vector a(n,vector<int>(m));
	rep(i,n){
		rep(j,m){
			scanf("%d",&a[i][j]);
		}
	}
	
	vector b(n,vector<int>(m,T));
	rep(i,n){
		rep(j,m){
			if((i+j)%2==0){
				b[i][j] = num[a[i][j]];
			}
		}
	}
	
	rep(i,n){
		rep(j,m){
			if(j!=0)printf(" ");
			printf("%d",b[i][j]);
		}
		printf("\n");
	}
	
	
		
	
	return 0;
}