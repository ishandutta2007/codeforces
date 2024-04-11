#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000000000000

int main(){
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		long long x,y,k;
		cin>>x>>y>>k;
		
		long long ans = k;
		ans += (k*y+k-1 + (x-2))/(x-1);
		cout<<ans<<endl;
	}
	
    return 0;
}