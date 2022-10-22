#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 1000000001

bool check(string ans){
	bool f = true;
	rep(i,ans.size()-1){
		if(abs(ans[i] - ans[i+1])==1)return false;
	}
	return true;
}


int main(){
	
	int T;
	cin>>T;
	
	rep(_,T){
		string s;
		cin>>s;
		
		vector<int> c(26,0);
		rep(i,s.size()){
			c[s[i]-'a']++;
		}
		
		vector<pair<char,int>> X;
		rep(i,26){
			if(c[i]!=0){
				X.emplace_back('a' + i,c[i]);
			}
		}
		
		sort(X.begin(),X.end());
		string ans = "";
		
		while(X.size()>1){
			rep(i,X.back().second)ans += X.back().first;
			X.pop_back();
			reverse(X.begin(),X.end());
		}
		rep(i,X.back().second){
			ans.insert(ans.begin(),X.back().first);
		}
		
		if(check(ans)){
			cout<<ans<<endl;
		}
		else{
			ans.erase(ans.begin(),ans.begin() + X.back().second);
			rep(i,X.back().second)ans += X.back().first;
			if(check(ans))cout<<ans<<endl;
			else cout<<"No answer"<<endl;
		}
		
	}
	
	return 0;
}