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
		string s;
		cin>>s;
		
		vector<vector<int>> ind(26);
		rep(i,s.size()){
			if(i==0||i+1==s.size())continue;
			ind[s[i]-'a'].push_back(i);
		}
		
		int x = s[0]-'a',y = s.back()-'a';
		
		vector<int> ans(1,1);
		int cur = x;
		while(true){
			rep(i,ind[cur].size())ans.push_back(ind[cur][i]+1);
			
			if(cur==y)break;
			if(cur<y)cur++;
			else cur--;
		}
		ans.push_back(s.size());
		cout<<abs(x-y)<<' '<<ans.size()<<endl;
		rep(i,ans.size()){
			if(i!=0)cout<<' ';
			cout<<ans[i];
		}
		cout<<endl;
	}
	
	return 0;
}