#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000000000000000

int query(int r){
	cout<<"? "<<1<<' '<<r<<endl;
	cin>>r;
	return r;
}

void answer(int ans){
	cout<<"! "<<ans<<endl;
	return;
}

int main(){
	
	int n,t,k;
	cin>>n>>t>>k;
	
	int ng = 0,ok = n+1;
	
	while(ok-ng>1){
		int mid = (ok+ng)/2;
		int r = query(mid);
		
		if(mid - r >= k)ok = mid;
		else ng = mid;
	}
	
	answer(ok);
	
    return 0;
}