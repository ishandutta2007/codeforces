#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000000000000000

int main(){	
	
	int t;
	cin>>t;
	vector<int> p;
	vector<bool> isp(1000,true);
	
	for(int i=2;i<1000;i++){
		if(isp[i]){
			p.push_back(i);
			for(int j=i*2;j<1000;j+=i)isp[j] = false;
		}
	}
	
	rep(_,t){
		int n;
		cin>>n;
		vector<vector<int>> ans(n,vector<int>(n,1));
		int ind = distance(p.begin(),lower_bound(p.begin(),p.end(),n));
		
		while(binary_search(p.begin(),p.end(),p[ind]-(n-1)))ind++;
		
		
		rep(i,n){
			ans[i][i] = p[ind] - (n-1);
		}
		
		rep(i,n){
			rep(j,n){
				if(j!=0)cout<<' ';
				cout<<ans[i][j];
			}
			cout<<endl;
		}
	}
	
    return 0;
}