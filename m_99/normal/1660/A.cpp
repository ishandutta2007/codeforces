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
		if(a==0)cout<<1<<endl;
		else{
			cout<<a+b*2+1<<endl;
		}
		
	}
	
	return 0;
}