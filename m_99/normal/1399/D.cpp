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
		
		vector<vector<int>> ans;
		set<int> S0,S1;
		
		rep(i,n){
			if(s[i]=='0'){
				if(S1.size()==0){
					S0.insert(ans.size());
					ans.push_back({i});
				}
				else{
					int t = (*S1.begin());
					ans[t].push_back(i);
					S1.erase(t);
					S0.insert(t);
				}
			}
			else{
				if(S0.size()==0){
					S1.insert(ans.size());
					ans.push_back({i});
				}
				else{
					int t = (*S0.begin());
					ans[t].push_back(i);
					S0.erase(t);
					S1.insert(t);
				}
			}
		}
		
		vector<int> p(n);
		rep(i,ans.size()){
			rep(j,ans[i].size())p[ans[i][j]] = i+1;
		}
		
		printf("%d\n",ans.size());
		rep(i,n){
			if(i!=0)printf(" ");
			printf("%d",p[i]);
		}
		cout<<endl;
		
	}
	
	return 0;
}