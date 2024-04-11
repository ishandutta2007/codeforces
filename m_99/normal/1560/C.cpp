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
			int x = 2*i + 1;
			if(k<=x){
				int r,c;
				if(k<=i){
					r = k;
					c = i+1;
				}
				else{
					r = i+1;
					c = i+1;
					c -= (k-i-1);
				}
				cout<<r<<' '<<c<<endl;
				break;
			}
			else{
				k -= x;
			}
		}
		
	}
	
	return 0;
}