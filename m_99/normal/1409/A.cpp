#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000300


int main(){
	
	int t;
	cin>>t;
	
	rep(_,t){
		
		int a,b;
		cin>>a>>b;
		
		int c = abs(a-b);
		
		cout<<(c+9)/10<<endl;
		
	}
	
    return 0;
}