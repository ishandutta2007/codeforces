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
		vector<int> a(n);
		rep(i,n)scanf("%d",&a[i]);
		
		map<int,vector<int>> mp;
		rep(i,n)mp[a[i]].push_back(i);
		int m = 0;
		for(auto x:mp){
			m = max(m,(int)x.second.size());
		}
		
		vector ind(m,vector<int>());
		for(auto x:mp){
			rep(j,x.second.size())ind[j].push_back(x.second[j]);
		}
		
		vector<int> ans(n);
		rep(i,m){
			rep(j,ind[i].size()){
				int v = a[ind[i][j]];
				int jj = j+1;
				jj %= ind[i].size();
				ans[ind[i][jj]] = v;
			}
		}
		rep(i,n){
			if(i!=0)printf(" ");
			printf("%d",ans[i]);
		}
		printf("\n");
		
	}
	
	return 0;
}