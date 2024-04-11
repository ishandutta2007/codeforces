#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000000

int main(){
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		
		long long a,b;
		cin>>a>>b;
		
		if(a==b){
			cout<<0<<' '<<0<<endl;
		}
		else{
			long long x = abs(a-b);
			
			long long y = a%x;
			y = min(y,x-y);
			
			cout<<x<<' '<<y<<endl;
			
		}
		
	}
	
    return 0;
}