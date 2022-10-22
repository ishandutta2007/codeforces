#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf32 1000000001
#define Inf64 2000000000000000001



int main(){
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		
		long long n;
		cin>>n;
		
		long long ans = n;
		ans += 2*(n/2);
		ans += 2*(n/3);
		
		cout<<ans<<endl;
		
	}
	
    return 0;
}