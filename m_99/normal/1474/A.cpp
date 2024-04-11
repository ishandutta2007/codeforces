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
		scanf("%d",&n);
		string b;
		cin>>b;
		
		string ans = "1";
		rep(i,n){
			if(i==0)continue;
			int x = b[i]-'0' + 1;
			int y = b[i-1]-'0' + (ans.back()-'0');
			if(x==y)ans += '0';
			else ans += '1';
		}
		
		cout<<ans<<endl;
		
	}
	
    return 0;
}