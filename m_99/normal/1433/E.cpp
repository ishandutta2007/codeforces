#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 100000000


int main(){	
	
	int n;
	cin>>n;
	
	if(n==2)cout<<1<<endl;
	else if(n==4)cout<<3<<endl;
	else{
		long long ans = 1LL;
		rep(i,n/2-1){
			ans *= n-1-i;
		}
		rep(i,n/2-1){
			ans *= n/2-1-i;
		}
		cout<<ans<<endl;
	}
		
    return 0;
}