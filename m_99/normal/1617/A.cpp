#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define Inf 1000000001

int main(){
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		
		string s;
		cin>>s;
		vector<int> cnt(26,0);
		rep(i,s.size()){
			cnt[s[i]-'a']++;
		}
		
		string t;
		cin>>t;
		
		string ans = "";
		if(t!="abc" || cnt[0]==0){
			rep(i,26){
				rep(j,cnt[i])ans += 'a'+i;
			}
		}
		else{
			rep(j,cnt[0])ans += 'a';
			rep(j,cnt[2])ans += 'c';
			rep(j,cnt[1])ans += 'b';
			for(int i=3;i<26;i++){
				rep(j,cnt[i])ans += 'a'+i;
			}
		}
		cout<<ans<<endl;
		
	}
	
	return 0;
}