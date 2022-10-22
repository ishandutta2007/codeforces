#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000001

int main(){	
	
	int t;
	cin>>t;
	
	rep(_,t){
		
		int n;
		cin>>n;
		
		string s;
		cin>>s;
		bool f = true;
		rep(i,n){
			if(s[i]=='>'){
				f=false;
				break;
			}
		}
		
		if(f){
			cout<<n<<endl;
			continue;
		}
		
		f=true;
		rep(i,n){
			if(s[i]=='<'){
				f=false;
				break;
			}
		}
		if(f){
			cout<<n<<endl;
			continue;
		}
		
		int ans = 0;
		rep(i,n){
			int x = i;
			int y = x+1;
			y %= n;
			
			if(s[x]=='-'||s[y]=='-')ans++;
		}
		
		cout<<ans<<endl;
		
	}
	
    return 0;
}