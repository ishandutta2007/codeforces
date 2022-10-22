#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000001

int main(){
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		
		long long n;
		cin>>n;
		int ans = 0;
		while(n%3==0){
			ans ++;
			if(n%2==0){
				n /= 6;
			}
			else{
				n *= 2;
			}
		}
		if(n==1)cout<<ans<<endl;
		else cout<<-1<<endl;
		
		
		
	}
	
	return 0;
}