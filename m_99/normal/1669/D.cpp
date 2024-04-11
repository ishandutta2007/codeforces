#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000000

bool check(string s){
	if(s.size()==0)return true;
	int c = 0;
	rep(i,s.size()){
		if(s[i]=='B')c |= 1;
		if(s[i]=='R')c |= 2;
	}
	return c==3;
}

int main(){
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		int n;
		cin>>n;
		string s;
		cin>>s;
		s += 'W';
		string cur = "";
		bool f = true;
		rep(i,s.size()){
			if(s[i]=='W'){
				if(!check(cur)){
					f = false;
					break;
				}
				cur = "";
			}
			else cur += s[i];
		}
		if(f)cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	
	
    return 0;
}