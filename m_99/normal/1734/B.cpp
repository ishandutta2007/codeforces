#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf32 1000000001
#define Inf64 4000000000000000001


int main(){	
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		
		int n;
		cin>>n;
		vector<vector<int>> ans(n);
		rep(i,n){
			ans[i] = vector<int>(i+1,0);
			ans[i][0] = 1;
			ans[i].back() = 1;
		}
		rep(i,n){
			rep(j,i+1){
				if(j!=0)printf(" ");
				printf("%d",ans[i][j]);
			}
			printf("\n");
		}
	}
	
	return 0;
	
}