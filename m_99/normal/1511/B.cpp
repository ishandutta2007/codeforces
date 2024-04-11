#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000001


int main(){
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		
		int a,b,c;
		cin>>a>>b>>c;
		string x(a,'0'),y(b,'0');
		x[0] = '1';
		y[0] = '1';
		
		if(a>b){
			int n = a;
			x[n-c] = '1';
		}
		else{
			int n = b;
			y[n-c] = '1';
		}
		cout<<x<<' '<<y<<endl;
		
	}
	
    return 0;
}