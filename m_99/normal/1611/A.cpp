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
		
		int ans;
		if((s.back()-'0')%2==0)ans = 0;
		else if((s[0]-'0')%2==0)ans = 1;
		else{
			bool f = false;
			rep(i,s.size()){
				if((s[i]-'0')%2==0)f = true;
			}
			if(f)ans = 2;
			else ans = -1;
		}
		cout<<ans<<endl;
		
		
	}
		
	return 0;
}