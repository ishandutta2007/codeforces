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
		
		for(int i=n;true;i++){
			int s = 0;
			int t = i;
			while(t!=0){
				s += t%10;
				t/=10;
			}
			if(s%4==0){
				cout<<i<<endl;
				break;
			}
		}
		
	}
	
	return 0;
}