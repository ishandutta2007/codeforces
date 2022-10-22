#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000001

int main(){
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		
		long long n,m;
		cin>>n>>m;
		
		
		long long ans = 0LL;
		if(n==1)ans = 0;
		else if(n==2)ans = m;
		else ans = m*2;
		
		cout<<ans<<endl;
	}
	
	return 0;
}