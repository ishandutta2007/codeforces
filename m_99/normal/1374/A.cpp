#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000001

int main(){
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		
		int x,y,n;
		cin>>x>>y>>n;
		
		int ans = n/x;
		ans *= x;
		ans += y;
		while(ans > n){
			ans -= x;
		}
		
		cout<<ans<<endl;
		
		
		
		
	}
	
	return 0;
}