#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define Inf 1000000001

int main(){
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		
		int a,b;
		cin>>a>>b;
		
		cout<<min({a,b,(a+b)/4})<<endl;
		
		
	}
		
	return 0;
}