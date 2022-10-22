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
		int n;
		cin>>n;
		string s,t;
		cin>>s>>t;
		
		set<pair<char,char>> S;
		bool f = false;
		if(n%2==0)f = true;
		rep(i,n){
			pair<char,char> p(s[i],t[n-1-i]);
			if(p.first>p.second)swap(p.first,p.second);
			/*
			if(p.first==p.second){
				if(!f){
					f = true;
					continue;
				}
			}*/
			
			if(S.count(p))S.erase(p);
			else S.insert(p);
			
		
				
		}
		if(n%2==1){
			auto it=  S.begin();
			if(it->first==it->second)S.erase(it);
		}
		if(S.size()==0)cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	
	return 0;
}