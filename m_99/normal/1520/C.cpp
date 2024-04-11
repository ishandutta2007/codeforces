#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000001

int main(){
	
	
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		int n;
		cin>>n;
		
		if(n==2){
			printf("-1\n");
			continue;
		}
		
		int cur = 1;
		vector<vector<int>> ans(n,vector<int>(n));
		
		rep(i,n){
			rep(j,n){
				if((i+j)%2==0){
					ans[i][j] = cur;
					cur++;
				}
			}
		}
		rep(i,n){
			rep(j,n){
				if((i+j)%2==1){
					ans[i][j] = cur;
					cur++;
				}
			}
		}
		
		rep(i,n){
			rep(j,n){
				if(j!=0)printf(" ");
				printf("%d",ans[i][j]);
			}
			printf("\n");
		}
		
	}
	
    return 0;
}