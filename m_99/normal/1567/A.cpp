#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000001


int main(){
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		
		int n;
		cin>>n;
		string s;
		cin>>s;
		rep(i,n){
			if(s[i]=='U')s[i] = 'D';
			else if(s[i]=='D')s[i] = 'U';
		}
		cout<<s<<endl;
		
	}
	
	return 0;
}