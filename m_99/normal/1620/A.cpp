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
		
		int c = 0;
		rep(i,s.size()){
			if(s[i]=='N')c++;
		}
		if(c==1)cout<<"NO"<<endl;
		else cout<<"YES"<<endl;
		
	}
	
	return 0;
}