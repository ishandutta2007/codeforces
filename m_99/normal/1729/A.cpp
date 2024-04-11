#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf32 1000000001
#define Inf64 4000000000000000001



int main(){
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		
		int a,b,c;
		cin>>a>>b>>c;
		
		int x = a-1;
		int y = abs(b-c) + abs(c-1);
		
		if(x<y)cout<<1<<endl;
		else if(x>y)cout<<2<<endl;
		else cout<<3<<endl;
		
		
	}
	
	return 0;
}