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
		set<char> S;
		bool f = true;
		rep(i,s.size()){
			if(islower(s[i]))S.insert(s[i]);
			else{
				if(!S.count(tolower(s[i])))f = false;
			}
		}
		if(f)cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
		
	}
	
	return 0;
}