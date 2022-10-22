#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000000



int main(){
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		
		string s;
		cin>>s;
		
		int n = s.size();
		
		if(n%2==1){
			cout<<"No"<<endl;
			continue;
		}
		
		if(s[0]==')'||s.back()=='('){
			cout<<"No"<<endl;
			continue;
		}
		
		cout<<"Yes"<<endl;
		
		
	}
	
    return 0;
}