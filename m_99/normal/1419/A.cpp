#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000000


int main(){

	int t;
	cin>>t;
	
	rep(_,t){
		int n;
		cin>>n;
		string s;
		cin>>s;
		
		if(s.size()%2==1){
			bool f = false;
			for(int i=0;i<s.size();i+=2){
				if((s[i]-'0')%2==1)f=true;
			}
			if(f)cout<<1<<endl;
			else cout<<2<<endl;
		}
		else{
			bool f = false;
			for(int i=1;i<s.size();i+=2){
				if((s[i]-'0')%2==0)f=true;
			}
			if(f)cout<<2<<endl;
			else cout<<1<<endl;
		}
		
	}

	return 0;
}