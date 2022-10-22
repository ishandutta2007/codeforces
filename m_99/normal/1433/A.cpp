#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 100000000


int main(){	
	
	int t;
	cin>>t;
	rep(_,t){
		string s;
		cin>>s;
		
		int ans = s[0]-'1';
		ans *= 10;
		for(int i=1;i<=s.size();i++)ans += i;
		cout<<ans<<endl;
	}
		
    return 0;
}