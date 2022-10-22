#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 1000000001

int main(){
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		
		int x;
		cin>>x;
		if(x%2==0)cout<<x/2<<endl;
		else{
			cout<<(x-3)/2 + 1<<endl;
		}
		
		
		
		
	}
	
    return 0;
}