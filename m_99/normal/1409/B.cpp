#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000300

long long get(long long a,long long b,long long x,long long y,long long n){
	if(a-x < n){
		n -= a-x;
		a = x;
	}
	else{
		a -= n;
		n=0;
	}
	
	if(b-y<n){
		n -= b-y;
		b = y;
	}
	else{
		b -= n;
		n=0;
	}
	return a*b;
}

int main(){
	
	int t;
	cin>>t;
	
	rep(_,t){
		int a,b,x,y,n;
		cin>>a>>b>>x>>y>>n;
		
		cout<<min(get(a,b,x,y,n),get(b,a,y,x,n))<<endl;
		
	}
	
    return 0;
}