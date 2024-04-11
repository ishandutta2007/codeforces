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
		
		int cur = 0;
		bool f = true;
		if(s.back()!='B')f = false;
		rep(i,s.size()){
			if(s[i]=='A')cur++;
			else{
				cur--;
				if(cur<0)f = false;
			}
		}
		if(f)cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
		
	}
	
	return 0;
}