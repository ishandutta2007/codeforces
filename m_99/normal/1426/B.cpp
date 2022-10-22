#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000000

int main(){

	int t;
	cin>>t;
	
	rep(_,t){
		int n,m;
		cin>>n>>m;
		
		vector<vector<vector<int>>> M(n,vector<vector<int>>(2,vector<int>(2,0)));
		
		rep(i,n){
			rep(j,2){
				rep(k,2){
					cin>>M[i][j][k];
				}
			}
		}
		
		if(m%2!=0){
			cout<<"No"<<endl;
			continue;
		}
		
		bool f = false;
		
		rep(i,n){
			if(M[i][0][1]==M[i][1][0]){
				f=true;
				break;
			}
		}
		
		if(f)cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
		
	}
	
	return 0;
}