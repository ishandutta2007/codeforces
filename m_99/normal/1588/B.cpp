#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000001

long long query(int l,int r){
	cout<<"? "<<l<<' '<<r<<endl;
	long long ret;
	scanf("%lld",&ret);
	if(ret==-1){
		assert(false);
	}
	return ret;
}

void answer(int a,int b,int c){
	cout<<"! "<<a<<' '<<b<<' '<<c<<endl;
	return;
}

void solve(){
	
	int n;
	cin>>n;
	
	long long A = query(1,n);
	int ok = n,ng = 0;
	while(ok-ng>1){
		int mid = (ok+ng)/2;
		long long ret = query(1,mid);
		if(ret==A)ok = mid;
		else ng=  mid;
	}
	
	long long y = A - query(1,ok-1);
	
	y++;
	long long x;
	{
		long long Ok = 2LL,Ng = 1000000005;
		while(Ng-Ok>1LL){
			long long mid = (Ok+Ng)/2;
			if(((mid*(mid-1))/2) + ((y*(y-1))/2) > A)Ng = mid;
			else Ok = mid;
		}
		x = Ok;
	}
	
	answer(ok-(x+y)+1,ok-(y)+1,ok);
	
}

int main(){

	int _t;
	cin>>_t;
	
	rep(_,_t){
		solve();
	}
	
	return 0;
}