#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define Inf 1000000001


int main(){
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		
		int n;
		cin>>n;
		
		int m = Inf,M = -Inf;
		rep(i,n){
			int a;
			cin>>a;
			 m = min(m,a);
			 M = max(M,a);
		}
		cout<<M-m<<endl;
		
	}
	
	return 0;
}