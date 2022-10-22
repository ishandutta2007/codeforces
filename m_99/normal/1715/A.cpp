#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf32 1000000001
#define Inf64 4000000000000000001



int main() {
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		
		long long n,m;
		cin>>n>>m;
		long long ans = (n-1) + (m-1);
		ans *= 2;
		
		ans -= max(0LL,max(n,m)-2);
		cout<<ans<<endl;
		
	}
	
    return 0;
}