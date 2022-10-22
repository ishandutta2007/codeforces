#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf32 1000000001
#define Inf64 2000000000000000001



int main(){
	
	int _t;
	cin>>_t;
	map<char,int> mp;
	mp['S'] = 0;
	mp['M'] = 1;
	mp['L'] = 2;
	rep(_,_t){
		
		string s,t;
		cin>>s>>t;
		if(s==t){
			cout<<"="<<endl;
			continue;
		}
		if(s.back()!=t.back()){
			if(mp[s.back()]<mp[t.back()])cout<<"<"<<endl;
			else cout<<">"<<endl;
		}
		else{
			if((s.size()<t.size())^(s.back()=='S'))cout<<"<"<<endl;
			else cout<<">"<<endl;
		}
		
	}
	
	return 0;
}