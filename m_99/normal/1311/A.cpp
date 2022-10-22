#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000000


int main(){
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		
		long long a,b;
		cin>>a>>b;
		long long ans;
		if(a==b)ans = 0;
		else if(b>a){
			if((b-a)%2==1)ans = 1;
			else ans = 2;
			
		}
		else{
			if((b-a)%2==0)ans = 1;
			else ans = 2;
		}
		cout<<ans<<endl;
		
		
	}
	
	return 0;
}