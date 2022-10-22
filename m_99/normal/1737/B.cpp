#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf32 1000000001
#define Inf64 4000000000000000001

long long get(long long n){
	
	
	
	long long ok = 0,ng = Inf32;
	while(ng-ok>1LL){
		long long mid = (ok+ng)/2;
		if((mid+1)*(mid+1)<=n)ok = mid;
		else ng = mid;
	}
	long long ret = ok*3;
	//ret++;
	ok++;
	if(n >= ok*ok)ret++;
	if( n>= ok*ok+ok)ret++;
	if(n >= ok*ok+ok*2)ret++;
	return ret;
	
}

int main(){
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		
		long long l,r;
		cin>>l>>r;
		
		cout<<get(r) - get(l-1)<<endl;
	}	
	
	return 0;
}