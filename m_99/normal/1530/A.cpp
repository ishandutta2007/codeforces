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
		
		int ans = 0;
		while(n!=0){
			ans = max(ans,n%10);
			n /= 10;
		}
		
		cout<<ans<<endl;
		
		
		
	}	
	
	return 0;
}