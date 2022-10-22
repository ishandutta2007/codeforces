#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define Inf 1000000001

bool check(int a,int b,int c){
	if(a==1)return false;
	if(b==c){
		return (a%2==0);
	}
	if(a==b+c)return true;
	return false;
}

int main(){
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		
		int a,b,c;
		cin>>a>>b>>c;
		
		if(check(a,b,c)||check(b,a,c)||check(c,a,b))cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
		
	}
	
	return 0;
}