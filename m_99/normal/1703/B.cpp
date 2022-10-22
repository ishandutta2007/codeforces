#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000000



int main(){
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		int n;
		cin>>n;
		string s;
		cin>>s;
		
		int ans = 0;
		set<char> S;
		rep(i,n){
			ans++;
			if(!S.count(s[i]))ans++;
			S.insert(s[i]);
		}
		cout<<ans<<endl;
		
	}
	
    return 0;
}