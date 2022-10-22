#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000001



int main(){
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		long long n;
		cin>>n;
		long long l,r;
		
		if(n==0)l = -1,r = 1;
		else if(n>0){
			r = n;
			l = -(n-1);
		}
		else{
			l = n;
			r = (-n)-1;
		}
		
		cout<<l<<' '<<r<<endl;
	}
	
	return 0;
}