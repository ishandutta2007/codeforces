#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000001


int main(){
	
	int _t;
	//cin>>_t;
	_t = 1;
	rep(_,_t){
		
		int n;
		cin>>n;
		int c = 0;
		rep(i,n){
			int x;
			cin>>x;
			if(x&1)c++;
		}
		
		cout<<min(c,n-c)<<endl;
		
		
	}
	
	return 0;
}