#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000001

bool check(string s){
	while(s.back()=='0'){
		s.pop_back();
	}
	int n = s.size();
	return s==string(n,'1');
}

int main(){
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		
		string s;
		cin>>s;
		int n = s.size();
		int ans = 2;
		
		if(s == string(n,'0'))ans = min(ans,1);
		if(s== string(n,'1'))ans=  min(ans,0);
		
		if(ans==2){
			string t = "";
			rep(i,s.size()){
				if(t.size()==0 || t.back()!=s[i])t += s[i];
			}
			
			int c = 0;
			rep(i,t.size()){
				if(t[i]=='0')c++;
			}
			if(c==1)ans = 1;
		}
		
		cout<<ans<<endl;
		
		
	}
	
	return 0;
}