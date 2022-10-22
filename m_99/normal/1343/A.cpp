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
		
		rep(i,30){
			if(i<=1)continue;
			int x = 1<<i;
			x--;
			if(n%x==0){
				cout<<n/x<<endl;
				break;
			}
		}
	}
	
	return 0;
}