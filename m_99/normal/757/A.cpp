#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000001



int main(){
	
	string S;
	cin>>S;
	
	string s = "Bulbasaur";
	int ans = 0;
	map<char,int> mp;
	rep(i,S.size()){
		mp[S[i]]++;
	}
	
	while(true){
		bool f = true;
		rep(i,s.size()){
			if(mp[s[i]]==0){
				f=false;
				break;
			}
			mp[s[i]]--;
		}
		if(f)ans++;
		else break;
	}
	
	cout<<ans<<endl;
	
    return 0;
}