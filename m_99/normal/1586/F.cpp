#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000001

int main(){
	
	int n,k;
	cin>>n>>k;
	
	vector ans(n,vector<int>(n,-1));
	
	vector<vector<int>> t(n);
	rep(i,n)t[i] = {i};
	int cur = 0;
	while(t.size()>=2){
		vector<vector<int>> nt;
		while(t.size()>0){
			vector<int> temp;
			rep(j,k){
				if(t.size()==0)continue;
				
				rep(l,t.back().size()){
					rep(ll,temp.size()){
						ans[min(temp[ll],t.back()[l])][max(temp[ll],t.back()[l])] = cur;
					}
				}
				rep(l,t.back().size())temp.push_back(t.back()[l]);
				t.pop_back();
			}
			nt.push_back(temp);
					
		}
		swap(t,nt);
		cur++;
	}
	
	cout<<cur<<endl;
	bool f  =true;
	rep(i,n){
		for(int j=i+1;j<n;j++){
			if(f){
				f = false;
			}
			else{
				printf(" ");
			}
			printf("%d",ans[i][j]+1);
		}
	}
	cout<<endl;
	
	return 0;
}