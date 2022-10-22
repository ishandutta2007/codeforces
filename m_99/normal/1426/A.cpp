#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000000

int main(){

	int t;
	cin>>t;
	
	rep(_,t){
		int n,x;
		cin>>n>>x;
		
		rep(j,100000){
			if(n <= j*x + 2){
				cout<<j+1<<endl;
				break;
			}
		}
	}
	
	return 0;
}