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
		
		int ind = -1;
		rep(i,n){
			if(s[i]!='?'){
				ind = i;
				break;
			}
		}
		if(ind==-1){
			rep(i,n){
				if(i%2==0)s[i] = 'B';
				else s[i] = 'R';
			}
		}
		else{
			for(int i=ind+1;i<n;i++){
				if(s[i]=='?'){
					if(s[i-1]=='R')s[i] = 'B';
					else s[i] = 'R';
				}
			}
			reverse(s.begin(),s.end());
			for(int i=1;i<n;i++){
				if(s[i]=='?'){
					if(s[i-1]=='R')s[i] = 'B';
					else s[i] = 'R';
				}
			}
			reverse(s.begin(),s.end());
		}
		cout<<s<<endl;
		
		
	}
	
	return 0;
}