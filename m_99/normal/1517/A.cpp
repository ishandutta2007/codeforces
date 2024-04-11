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
		cin>>n;
		
		if(n%2050!=0){
			cout<<-1<<endl;
			continue;
		}
		n /= 2050;
		
		long long ans = 0;
		while(n!=0){
			ans += n%10;
			n /= 10;
		}
		
		cout<<ans<<endl;
		
		
		
		
		
		
	}
	
    return 0;
}