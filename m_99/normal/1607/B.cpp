#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000001

int main(){	
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		
		long long x,n;
		cin>>x>>n;
		
		long long t = n/4;
		t *= 4;
		
		for(long long i=t+1;i<=n;i++){
			if(x%2==0){
				x -= i;
			}
			else{
				x += i;
			}
		}
		
		cout<<x<<endl;
		
		
	}
	
	return 0;
	
}