#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000000


int main(){
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		
		long long n;
		scanf("%lld",&n);
		while(n%2==0)n/=2;
		
		if(n==1)cout<<"NO"<<endl;
		else cout<<"YES"<<endl;
		
		
	}
	
    return 0;
}