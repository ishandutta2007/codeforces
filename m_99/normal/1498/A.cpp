#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000001

long long gcdsum(long long n){
	long long a = n;
	long long b = 0;
	while(n!=0){
		b += n%10;
		n /= 10;
	}
	return gcd(a,b);
}

int main(){
	
	int _t;
	cin>>_t;
	
	
	rep(_,_t){
		
		long long n;
		cin>>n;
		
		rep(i,100){
			if(gcdsum(n+i)!=1){
				cout<<n+i<<endl;
				break;
			}
		}		
		
	}
	
	
	
	
    return 0;
}