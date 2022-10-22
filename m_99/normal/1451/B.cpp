#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000000

	

int main(){
	
	int t;
	cin>>t;
	
	rep(_,t){
		int n,q;
		cin>>n>>q;
		
		string s;
		cin>>s;
		
		rep(i,q){
			int l,r;
			cin>>l>>r;
			l--;r--;
			
			bool f = false;
			
			for(int j=r+1;j<n;j++){
				if(s[j]==s[r])f=true;
			}
			for(int j=0;j<l;j++){
				if(s[j]==s[l])f=true;
			}
			
			if(f)cout<<"YES"<<endl;
			else cout<<"NO"<<endl;
		}
	}
	
    return 0;
}