#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000001

long long solve(long long x,long long y){
	/*
	for(int i=1;i<=200;i++){
		if(i%x==y%i)cout<<i<<endl;
	}
	return 0;
*/
	
	if(x<=y){
		return y - (((y-x)%x)/2);
		/*
		if(x*3<=y)return x;
		else return (x+y)/2;
		*/
	}
	else{
		return x+y;
	}
	
}

int main(){
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		
		long long x,y;
		scanf("%lld %lld",&x,&y);
		
		printf("%lld\n",solve(x,y));
		
	}
	
	return 0;
	
}