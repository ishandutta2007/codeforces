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
		
		string s;
		cin>>s;
		
		vector<vector<int>> ind(2);
		rep(i,n){
			ind[s[i]-'1'].push_back(i);
		}
		
		if(ind[1].size()==1||ind[1].size()==2){
			cout<<"NO"<<endl;
			continue;
		}
		
		vector<string> ans(n,string(n,'='));
		
		rep(i,ind[1].size()){
			int a = ind[1][i],b = ind[1][(i+1)%ind[1].size()];
			ans[a][b] = '+';
			ans[b][a] = '-';
		}
		rep(i,n)ans[i][i] = 'X';
		cout<<"YES"<<endl;
		rep(i,n){
			cout<<ans[i]<<endl;
		}
		
	}
	
	return 0;
}