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
		
		vector<string> s(n);
		rep(i,n){
			cin>>s[i];
		}
		{
			vector<string> t(n);
			rep(i,n)cin>>t[i];
			rep(i,n){
				rep(j,n){
					if(t[i][j]=='1'){
						if(s[i][j]=='0')s[i][j] = '1';
						else s[i][j] = '0';
					}
				}
			}
		}
		
		rep(i,n){
			if(s[i][0]=='1'){
				rep(j,n){
					if(s[i][j]=='0')s[i][j] = '1';
					else s[i][j] = '0';
				}
			}
		}
		
		bool f = true;
		
		rep(i,n-1){
			if(s[i]!=s[i+1])f = false;
		}
		
		if(f)cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	
	return 0;
}