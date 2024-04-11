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
		char c;
		cin>>c;
		bool f = false;
		rep(i,s.size()){
			if(i%2==1)continue;
			if(s[i]==c)f = true;
		}
		cout<<(f?("Yes"):("No"))<<endl;
		
		
	}
	
	return 0;
}