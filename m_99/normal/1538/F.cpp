#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000001

int f(int l,int r,int m){
	return (r/m) - (l/m);
}

int main(){
	
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		
		int l,r;
		cin>>l>>r;
		
		long long ans = 0LL;
		int cur = 1;
		for(int i=0;i<=9;i++){
			ans += f(l,r,cur);
			cur *= 10;
		}
		
		cout<<ans<<endl;
	}
	return 0;
}