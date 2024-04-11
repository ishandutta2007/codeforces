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
		int ans = Inf;
		
		for(int i=2;i<=7;i++){
			
			rep(j,n){
				int a = 0,b = 0,c = 0;
				rep(k,i){
					if(j+k>=n){
						a = -1;
						break;
					}
					if(s[j+k]=='a')a++;
					if(s[j+k]=='b')b++;
					if(s[j+k]=='c')c++;
				}
				
				if(a>b&&a>c){
					/*
					if(i==2){
						cout<<j<<endl;
					}
					*/
					ans = min(ans,i);
				}
			}
		}
		if(ans==Inf)ans = -1;
					
		
		cout<<ans<<endl;
		
	}
	
	return 0;
}