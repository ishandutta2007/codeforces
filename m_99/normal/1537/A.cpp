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
		
		int sum = 0;
		rep(i,n){
			int a;
			cin>>a;
			sum += a;
		}
		
		int ans = 0;
		if(sum < n)ans = 1;
		else if(sum > n){
			ans = sum-n;
		}
		
		cout<<ans<<endl;
		
		
	}
	
	return 0;
}