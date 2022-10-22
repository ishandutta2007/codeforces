#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000001
 
 
int main(){
	
	int _t;
	cin>>_t;
//	_t = 1;
	rep(_,_t){
		
		long long k,n,a,b;
		cin>>k>>n>>a>>b;
		
		k--;
		k -= b*n;
		int ans;
		if(k<0)ans = -1;
		else{
			ans = min(n,k/(a-b));
		}
		cout<<ans<<endl;
		
	}
	
	return 0;
}