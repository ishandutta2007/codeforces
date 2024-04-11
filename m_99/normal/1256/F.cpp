#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000000000000000

int get(string s){
	int n = s.size();
	int ret = 0;
	rep(i,n){
		for(int j=i+1;j<n;j++){
			if(s[j]<s[i])ret++;
		}
	}
	return ret;
}

int main(){
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		int n;
		cin>>n;
		string s,t;
		cin>>s>>t;
		
		vector<int> sc(26,0),tc(26,0);
		
		rep(i,n){
			sc[s[i]-'a']++;
			tc[t[i]-'a']++;
		}
		
		if(sc!=tc){
			cout<<"NO"<<endl;
			continue;
		}
		int m = 1;
		rep(i,26)m = max(m,sc[i]);
		if(m>=2){
			cout<<"YES"<<endl;
			continue;
		}
		
		if(get(s)%2!=get(t)%2){
			cout<<"NO"<<endl;
		}
		else{
			cout<<"YES"<<endl;
		}
		
	}
	
	return 0;
}