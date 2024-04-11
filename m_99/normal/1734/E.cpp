#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf32 1000000001
#define Inf64 4000000000000000001


int main(){	
	
	int n;
	cin>>n;
	
	vector ans(n,vector<int>(n));
	rep(i,n){
		ans[i][0]  =0;
		for(int j=1;j<n;j++){
			ans[i][j] = (ans[i][j-1] + i)%n;
		}
	}
	rep(i,n){
		int b;
		cin>>b;
		while(ans[i][i]!=b){
			rep(j,n){
				ans[i][j] = (ans[i][j]+1)%n;
			}
		}
	}
	rep(i,n){
		rep(j,n){
			if(j!=0)cout<<' ';
			cout<<ans[i][j];
		}
		cout<<endl;
	}
	
	return 0;
	
}