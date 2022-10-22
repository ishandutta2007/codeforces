#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define Inf 1000000001

int main(){
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		int n;
		string s;
		cin>>n>>s;
		
		int ans = 0;
		rep(i,n){
			if(s.substr(i,2)=="00")ans += 2;
			if(s.substr(i,3)=="010")ans++;
		}
		cout<<ans<<endl;
	}
	
	return 0;
}