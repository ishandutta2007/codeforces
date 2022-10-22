#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000001



int main(){
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		
		int n;
		cin>>n;
		int sum = 0;
		rep(i,n){
			int a;
			cin>>a;
			sum += a-1;
		}
		sum %= 2;
		if(sum==1)cout<<"errorgorn"<<endl;
		else cout<<"maomao90"<<endl;
		
	}
	
	return 0;
}