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
		rep(i,n)ind[s[i]-'0'].push_back(i);
		vector<int> ans;
		while(true){
			if(ind[0].size()==0||ind[1].size()==0)break;
			if(ind[0].back()<ind[1][0])break;
			ans.push_back(ind[0].back());
			ind[0].pop_back();
			ans.push_back(ind[1][0]);
			ind[1].erase(ind[1].begin());
		}
		if(ans.size()==0){
			cout<<0<<endl;
		}
		else{
			cout<<1<<endl;
			sort(ans.begin(),ans.end());
			cout<<ans.size();
			rep(i,ans.size()){
				cout<<' '<<ans[i]+1;
			}
			cout<<endl;
		}
		
		
	}
	
	return 0;
}