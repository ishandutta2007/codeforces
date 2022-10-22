#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000000000000000


int main(){
	
	
	int t;
	cin>>t;
	
	rep(_,t){
		
		string s;
		cin>>s;
		bool F = true;
		bool f = false;
		rep(i,s.size()-1){
			if(s[i]=='1'&&s[i+1]=='1'){
				f=true;
			}
			if(f&&s[i]=='0'&&s[i+1]=='0'){
				F=false;
			}
		}
		if(F)printf("YES\n");
		else printf("NO\n");
	}
		
	
    return 0;
}