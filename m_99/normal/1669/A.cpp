#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000000



int main(){
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		cout<<"Division ";
		int r;
		cin>>r;
		int ans;
		if(r>=1900)ans = 1;
		else if(r>=1600)ans = 2;
		else if(r>=1400)ans = 3;
		else ans = 4;
		cout<<ans<<endl;
		
		
	}
	
	
    return 0;
}