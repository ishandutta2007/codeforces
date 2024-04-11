#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000001

int main(){
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		
		long long n,m,x;
		scanf("%lld %lld %lld",&n,&m,&x);
		
		x--;
		long long r = x%n,c = x/n;
		long long y = r*m + c;
		printf("%lld\n",y+1);
		
		
		
		
	}

    return 0;
}