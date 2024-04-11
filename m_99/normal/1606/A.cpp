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
		if(s[0]!=s.back())s[0] = s.back();
		cout<<s<<endl;
		
		
	}
	
	return 0;
	
}