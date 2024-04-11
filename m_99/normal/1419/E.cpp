#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000000

int main(){

	int t;
	cin>>t;
	
	rep(_,t){
		int n;
		cin>>n;
		int N;
		N = n;
		vector<int> Y;
		for(int i=1;i*i<=n;i++){
			if(i==1||i==n)continue;
			if(n%i==0){
				Y.push_back(i);
				if(i*i!=n)Y.push_back(n/i);
			}
		}
		
		vector<int> p;
		for(int i=2;i*i<=n;i++){
			if(n%i==0){
				p.push_back(i);
				while(n%i==0)n/=i;
			}
		}
		if(n!=1)p.push_back(n);
		n = N;
		vector<vector<int>> ans(p.size(),vector<int>());
		
		rep(i,Y.size()){
			rep(j,p.size()){
				if(Y[i]%p[j]==0){
					ans[j].push_back(Y[i]);
					break;
				}
			}
		}
		
		for(int i=0;i+1<p.size();i++){
			rep(j,ans[i].size()){
				if(ans[i][j]%p[i+1]==0){
					int temp = ans[i][j];
					ans[i].erase(ans[i].begin() + j);
					ans[i].push_back(temp);
					break;
				}
			}
		}
		ans.back().push_back(n);
		bool f = true;
		rep(i,ans.size()){
			rep(j,ans[i].size()){
				if(!f)printf(" ");
				f=false;
				printf("%d",ans[i][j]);
			}
		}
		printf("\n");
		
		if(p.size()==2 && p[0]*p[1] == n){
			printf("1\n");
		}
		else{
			printf("0\n");
		}
		
		
		
	}

	return 0;
}