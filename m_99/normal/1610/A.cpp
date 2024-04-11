#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define Inf 1000000001


int main(){
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		
		int n,m;
		cin>>n>>m;
		
		if(n==1&&m==1)cout<<0<<endl;
		else if(n==1||m==1)cout<<1<<endl;
		else cout<<2<<endl;
		
		
	}
	
	return 0;
}