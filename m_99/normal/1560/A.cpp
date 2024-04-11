#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000001

int main(){
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		
		int k;
		cin>>k;
		
		rep(i,1000000){
			if(i%3!=0&&i%10!=3){
				k--;
			}
			
			if(k==0){
				cout<<i<<endl;
				break;
			}
		}
		
		
		
	}
	
	return 0;
}