#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define Inf 1000000001

long long get(long long n){
	return n * (n+1) / 2;
}

long long sum(long long l,long long r){
	return get(r) - get(l-1);
}

int main(){
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		long long k,x;
		cin>>k>>x;
		
		long long ok = 0LL,ng = k*2;
		while(ng-ok>1LL){
			long long mid = (ok+ng)/2;
			long long s = 0;
			if(mid <= k){
				s = get(mid);
			}
			else{
				s = get(k);
				s += sum(k-(mid-k),k-1);
			}
			if(s<x)ok = mid;
			else ng = mid;
			
		}
		ok = min(ok+1,k*2-1);
		cout<<ok<<endl;
	}
	
	return 0;
}