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
		
		s[0] = tolower(s[0]);
		s[1] = tolower(s[1]);
		s[2] = tolower(s[2]);
		if(s=="yes")cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
		
	}
	
    return 0;
}