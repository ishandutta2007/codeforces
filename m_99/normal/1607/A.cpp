#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000001

int main(){	
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		
		string s;
		cin>>s;
		
		vector<int> pos(26,0);
		rep(i,s.size()){
			pos[s[i]-'a'] = i;
		}
		
		string t;
		cin>>t;
		int ans = 0;
		rep(i,t.size()-1){
			ans += abs(pos[t[i]-'a'] - pos[t[i+1]-'a']);
		}
		
		cout<<ans<<endl;
		
		
		
	}
	
	return 0;
	
}